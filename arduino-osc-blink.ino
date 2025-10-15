/*
   arduino-osc-blink

   Listens for serial messages and controls the
   the on-board LED according to the message.

   To be used with the Processing sketch
   processing_osc_to_arduino.pde

   Written by Becky Stewart 2022
    edits by Joey More 2025
*/
const int redLedPin = 10;    // the number of the LED pin
const int greenLedPin = 12;    // the number of the LED pin
const int amberLedPin = 11;    // the number of the LED pin

// variable used for LED blink pattern
int blinkCode;

void setup() {
  Serial.begin(9600);  // initialise the serial communication


  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(amberLedPin, OUTPUT);
}

void loop() {
  // wait for a message to arrive
  if (Serial.available()) {
    // save the message when it arrives
    blinkCode = Serial.read();
  }

  // create two variables to control the blink patter
  int onDelay;
  int offDelay;

 switch (blinkCode) {
    case 1:
      /* on one second, off a quarter second
      onDelay = 1000;
      offDelay = 250;*/
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      digitalWrite(amberLedPin, LOW);
      break;
    case 0:
      /*/ on a half second, off one second
      onDelay = 250;
      offDelay = 1000; */
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      digitalWrite(amberLedPin, LOW);
      break;
    default:
      // default to on one second, off one second
      onDelay = 1000;
      offDelay = 1000;
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, LOW);
      digitalWrite(amberLedPin, HIGH);
      break;
  } 

Serial.println(blinkCode);

}
