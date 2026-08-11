/*
  Smart Zebra Crossing
  ---------------------------------------------------------
  Based on: "Enhancing Road Safety with Smart Infrastructure:
  Development and Implementation of Advanced Zebra Crossings
  and Speed Breaking" (IJRASET, Vol. 12, Issue X, Oct 2024)

  Working:
  - Ultrasonic sensor continuously checks for a pedestrian
    near the crossing.
  - When a pedestrian is detected, 7 red LEDs embedded in the
    crossing light up SEQUENTIALLY to alert oncoming drivers
    and improve visibility, especially in low light.
  - When no pedestrian is present, all LEDs stay off (standby).

  Pin Connections (as per paper):
    Ultrasonic Sensor
      Echo -> Arduino Pin 13
      Trig -> Arduino Pin 12
      VCC  -> 5V
      GND  -> GND

    LED Pins (7 red LEDs, sequential)
      LED1 -> Pin 2
      LED2 -> Pin 3
      LED3 -> Pin 4
      LED4 -> Pin 5
      LED5 -> Pin 6
      LED6 -> Pin 7
      LED7 -> Pin 8
*/

// ---------- Pin Definitions ----------
const int trigPin = 12;
const int echoPin = 13;

const int ledPins[7] = {2, 3, 4, 5, 6, 7, 8};
const int numLeds = 7;

// ---------- Tunable Parameters ----------
const int detectionDistanceCm = 100;   // Pedestrian considered "detected" within this range
const int sequenceDelayMs     = 150;   // Delay between each LED turning on in the sequence

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);   // Start in standby (lights off)
  }

  Serial.begin(9600);
}

void loop() {
  long distance = getDistanceCm();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= detectionDistanceCm) {
    // Pedestrian detected -> Crossing ON: sequentially light up LEDs
    Serial.println("Pedestrian detected - Crossing ON");
    sequenceLightsOn();
  } else {
    // No pedestrian -> Crossing OFF: keep lights off, keep monitoring
    allLightsOff();
  }

  delay(100); // small loop delay for stable sensor readings
}

// ---------- Helper Functions ----------

// Measures distance using the ultrasonic sensor and returns value in cm
long getDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout (~5m range)
  if (duration == 0) return -1; // no echo received

  long distance = duration * 0.0343 / 2; // speed of sound = 343 m/s
  return distance;
}

// Turns LEDs on one after another to create a sequential lighting effect
void sequenceLightsOn() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(sequenceDelayMs);
  }
}

// Turns all LEDs off (standby mode)
void allLightsOff() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
