/*
  Smart Speed Breaker
  ---------------------------------------------------------
  Based on: "Enhancing Road Safety with Smart Infrastructure:
  Development and Implementation of Advanced Zebra Crossings
  and Speed Breaking" (IJRASET, Vol. 12, Issue X, Oct 2024)

  Working:
  - Ultrasonic sensor takes two distance readings a fixed
    time interval apart and calculates the approaching
    vehicle's approximate speed.
  - If speed exceeds the 60 km/h threshold, the Arduino
    drives a mini servo motor 90 degrees clockwise, physically
    raising the speed breaker for 5 seconds to force the
    driver to slow down.
  - After 5 seconds (or if the vehicle is within the limit),
    the servo rotates back 90 degrees counterclockwise,
    lowering the breaker and returning to standby.

  Pin Connections (as per paper):
    Ultrasonic Sensor
      Echo -> Arduino Pin 6
      Trig -> Arduino Pin 5
      VCC  -> 5V
      GND  -> GND

    Mini Servo Motor
      Signal (orange) -> Pin 7
      GND (brown)      -> GND
      VCC (red)         -> 3.3V / 5V
*/

#include <Servo.h>

// ---------- Pin Definitions ----------
const int trigPin = 5;
const int echoPin = 6;
const int servoPin = 7;

Servo breakerServo;

// ---------- Tunable Parameters ----------
const float speedThresholdKmph = 60.0;   // Threshold from the paper
const unsigned long sampleIntervalMs = 100; // Time gap between two distance readings
const int breakerUpAngle   = 90;   // Servo angle when breaker is raised
const int breakerDownAngle = 0;    // Servo angle when breaker is lowered
const unsigned long breakerHoldMs = 5000; // Breaker stays up for 5 seconds

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  breakerServo.attach(servoPin);
  breakerServo.write(breakerDownAngle); // Start in lowered / standby position

  Serial.begin(9600);
}

void loop() {
  float speedKmph = measureSpeedKmph();

  Serial.print("Estimated Speed: ");
  Serial.print(speedKmph);
  Serial.println(" km/h");

  if (speedKmph > speedThresholdKmph) {
    Serial.println("Speeding detected - raising breaker");
    raiseBreaker();
    delay(breakerHoldMs);   // keep breaker up for 5 seconds
    lowerBreaker();
  }

  delay(50); // brief pause before next measurement cycle
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

// Takes two distance readings a short time apart and estimates vehicle speed in km/h
float measureSpeedKmph() {
  long d1 = getDistanceCm();
  delay(sampleIntervalMs);
  long d2 = getDistanceCm();

  if (d1 <= 0 || d2 <= 0) return 0.0; // invalid readings, treat as no vehicle

  long distanceCoveredCm = d1 - d2; // positive when vehicle is approaching
  if (distanceCoveredCm <= 0) return 0.0; // vehicle moving away or stationary

  float distanceMeters = distanceCoveredCm / 100.0;
  float timeSeconds = sampleIntervalMs / 1000.0;

  float speedMps = distanceMeters / timeSeconds;
  float speedKmph = speedMps * 3.6;

  return speedKmph;
}

// Raises the speed breaker by rotating the servo clockwise
void raiseBreaker() {
  breakerServo.write(breakerUpAngle);
}

// Lowers the speed breaker by rotating the servo counterclockwise
void lowerBreaker() {
  breakerServo.write(breakerDownAngle);
}
