/*
   arduino-osc-blink

   Listens for serial messages and controls the
   the on-board LED according to the message.

   To be used with the Processing sketch
   processing_osc_to_arduino.pde

   Written by Becky Stewart 2022
*/
#include <Servo.h>

Servo gripservo;
Servo rotateServo;
Servo pushServo;
Servo liftServo;

const int redLedPin = 11;     // the number of the LED pin
const int greenLedPin = 12;   // the number of the LED pin
const int amberLedPin = 8;    // the number of the LED pin
const int blueLedPin = 9;

int closePos = 180;     // adjust this if your servo's "open" position is different
int openPos = 0;        // adjust this if your servo's "closed" position is different

// variable used for LED blink pattern
int colourCode;

void setup() {
  Serial.begin(9600);  // initialise the serial communication

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(amberLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  gripservo.attach(2);      // Grip servo on pin 3
  rotateServo.attach(3);    // Rotation servo on pin 3
  pushServo.attach(4);
  liftServo.attach(5);
}

void loop() {
  // wait for a message to arrive
  if (Serial.available()) {
    // save the message when it arrives
    colourCode = Serial.read();
  }

 switch (colourCode) {
    case 1:
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, LOW);
      digitalWrite(amberLedPin, LOW);
      digitalWrite(blueLedPin, LOW);
      break;
    case 2:
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, LOW);
      digitalWrite(amberLedPin, LOW);
      digitalWrite(blueLedPin, HIGH);
      break;
    case 3:
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      digitalWrite(amberLedPin, LOW);
      digitalWrite(blueLedPin, LOW);
      break;
    case 4:
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      digitalWrite(amberLedPin, LOW);
      digitalWrite(blueLedPin, LOW);
      break;
    case 5:
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, LOW);
      digitalWrite(amberLedPin, HIGH);
      digitalWrite(blueLedPin, LOW);
      break;
    default:
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, LOW);
      digitalWrite(amberLedPin, LOW);
      digitalWrite(blueLedPin, LOW);
      break;
  } 

Serial.println(colourCode);

}