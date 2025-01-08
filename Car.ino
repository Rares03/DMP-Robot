#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Define L298N motor driver pins for the right motor
int enableRightMotor = 22; // PWM pin
int rightMotorPin1 = 12;   // IN1
int rightMotorPin2 = 14;   // IN2

// Define L298N motor driver pins for the left motor
int enableLeftMotor = 23; // PWM pin
int leftMotorPin1 = 27;   // IN3
int leftMotorPin2 = 26;   // IN4

#define MAX_MOTOR_SPEED 255 // Max PWM value for full speed

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  // Control right motor direction
  if (rightMotorSpeed > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else if (rightMotorSpeed < 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
    rightMotorSpeed = -rightMotorSpeed; // Make speed positive for PWM
  } else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  // Control left motor direction
  if (leftMotorSpeed > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else if (leftMotorSpeed < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
    leftMotorSpeed = -leftMotorSpeed; // Make speed positive for PWM
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  // Set motor speeds using PWM
  analogWrite(enableRightMotor, rightMotorSpeed);
  analogWrite(enableLeftMotor, leftMotorSpeed);
}

void setUpPinModes() {
  // Set motor control pins as outputs
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  // Stop motors initially
  rotateMotor(0, 0);
}

void setup() {
  setUpPinModes();           // Configure motor control pins
  Dabble.begin("MyCar");     // Start Bluetooth communication
  Serial.begin(115200);      // Initialize serial communication
}

void loop() {
  int rightMotorSpeed = 0; // Speed for the right motor
  int leftMotorSpeed = 0;  // Speed for the left motor

  Dabble.processInput(); // Process gamepad input from Dabble app

  // Control motors based on gamepad input
  if (GamePad.isUpPressed()) {
    rightMotorSpeed = MAX_MOTOR_SPEED;
    leftMotorSpeed = MAX_MOTOR_SPEED;
  } else if (GamePad.isDownPressed()) {
    rightMotorSpeed = -MAX_MOTOR_SPEED;
    leftMotorSpeed = -MAX_MOTOR_SPEED;
  } else if (GamePad.isLeftPressed()) {
    rightMotorSpeed = MAX_MOTOR_SPEED;
    leftMotorSpeed = -MAX_MOTOR_SPEED;
  } else if (GamePad.isRightPressed()) {
    rightMotorSpeed = -MAX_MOTOR_SPEED;
    leftMotorSpeed = MAX_MOTOR_SPEED;
  }

  // Set motor speeds
  rotateMotor(rightMotorSpeed, leftMotorSpeed);
}
