#include <Servo.h>
#include <NewPing.h>

// --- CONFIGURATION SECTION (Change things here easily) ---
// Motor Pins
const int LeftMotorForward  = 2;
const int LeftMotorBackward = 3;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

// Sensor Pins
const int trig_pin = A1;
const int echo_pin = A2;
const int maximum_distance = 200;

// Bluetooth / Alert Pins
const int ledPin    = 13; // Visual indicator
const int buzzerPin = 12; // Audio alert

// Settings
int speedSet     = 180; // Motor speed (0-255)
int safeDistance = 30;  // Distance to trigger avoidance (cm)

// Objects
Servo servo_motor;
NewPing sonar(trig_pin, echo_pin, maximum_distance);

void setup() {
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  servo_motor.attach(11); // Servo on pin 11
  servo_motor.write(115); // Center position
  delay(2000);
  
  digitalWrite(ledPin, HIGH); // System ready
}

void loop() {
  int distance = readPing();

  if (distance <= safeDistance) {
    moveStop();
    alertSound(); // Beep when obstacle detected
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    
    int distanceRight = lookRight();
    delay(300);
    int distanceLeft = lookLeft();
    delay(300);

    if (distanceRight >= distanceLeft) {
      turnRight();
      moveStop();
    } else {
      turnLeft();
      moveStop();
    }
  } else {
    moveForward();
  }
}

// --- HELPER FUNCTIONS ---

int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) cm = 250;
  return cm;
}

void alertSound() {
  digitalWrite(ledPin, LOW);
  tone(buzzerPin, 1000, 200); // 1kHz tone for 200ms
  delay(100);
  digitalWrite(ledPin, HIGH);
}

int lookRight() {  
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft() {
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

void moveStop() {
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void moveBackward() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnRight() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  delay(500);
  moveForward();
}

void turnLeft() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  delay(500);
  moveForward();
}
