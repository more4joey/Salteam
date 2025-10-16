#include <Servo.h>

/*----------------------------------------------------------------------------------------------------*/
// WEKINATOR
int colourInput;

/*----------------------------------*/
// SERVOS
Servo gripServo;
Servo rotateServo;
Servo pushServo;
Servo liftServo;

// gripServo ints
int gripPos;
int closePos = 0;
int openPos = 160;

// rotateServo ints
int rotatePos;
int centreRotatePos = 90;
int leftPos = 0;
int rightPos = 0;

// pushServo ints
int pushPos;
int centrePushPos = 45;
int forwardPos = 160;
int backPos = 30;

// liftServo ints
int liftPos;
int centreLiftPos = 90;
int upPos = 160;
int downPos = 50;

/*----------------------------------*/
// LEDs
const int redLedPin = 11;  
const int greenLedPin = 12;   
const int amberLedPin = 8; 
const int blueLedPin = 9;   

int red = 0;
int green = 0;
int amber = 0;
int blue = 0;

/*----------------------------------*/
// TIMING
unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 10;  // interval at which to loop (milliseconds) - won't change

/*----------------------------------------------------------------------------------------------------*/
// SETUP
void setup() {
  Serial.begin(9600);  // initialise the serial communication

  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(amberLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  gripServo.attach(2);      // Grip servo on pin 3
  rotateServo.attach(3);    // Rotation servo on pin 3
  pushServo.attach(4);
  liftServo.attach(5);
}

/*----------------------------------------------------------------------------------------------------*/
// LOOP
void loop() {
  // wait for a message to arrive
  if (Serial.available()) {
    // save the message when it arrives
    colourInput = Serial.read();
  }
  
  // here is where you'd put code that needs to be running all the time.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last timing
    previousMillis = currentMillis;

    switch (colourInput) {
        /*----------------------------------*/
        // NO COLOUR
        case 1:
          red = 0;
          green = 0;
          amber = 0;
          blue = 0;

          gripPos = closePos;
          rotatePos = centreRotatePos;
          pushPos = centrePushPos;
          liftPos = centreLiftPos;
          break;

        /*----------------------------------*/
        // BLUE  
        case 2:
          red = 0;
          green = 0;
          amber = 0;
          blue = 1;

          gripPos = openPos;
          rotatePos = centreRotatePos;
          pushPos = forwardPos;
          liftPos = downPos;
          break;
        
        /*----------------------------------*/
        // RED  
        case 3:
          red = 1;
          green = 0;
          amber = 0;
          blue = 0;

          gripPos = closePos;
          rotatePos = centreRotatePos;
          pushPos = backPos;
          liftPos = upPos;
          break;

        /*----------------------------------*/
        // GREEN  
        case 4:
          red = 0;
          green = 1;
          amber = 0;
          blue = 0;

          gripPos = openPos;
          rotatePos = rightPos;
          pushPos = forwardPos;
          liftPos = centreLiftPos;
          break;

        /*----------------------------------*/
        // AMBER (Black input)  
        case 5:
          red = 0;
          green = 0;
          amber = 1;
          blue = 0;

          gripPos = openPos;
          rotatePos = leftPos;
          pushPos = forwardPos;
          liftPos = centreLiftPos;
          break;

        /*----------------------------------*/
        // DEFAULT  (no signal)
        default:
          red = 1;
          green = 1;
          amber = 1;
          blue = 1;

          gripPos = closePos;
          rotatePos = centreRotatePos;
          pushPos = centrePushPos;
          liftPos = centreLiftPos;
          break;
      } 
  }

/*----------------------------------------------------------------------------------------------------*/
// WRITE OUTPUTS
/*----------------------------------*/
// write LEDs
digitalWrite(redLedPin, red);
digitalWrite(greenLedPin, green);
digitalWrite(amberLedPin, amber);
digitalWrite(blueLedPin, blue);

/*----------------------------------*/
// write servos
gripServo.write(gripPos);      
rotateServo.write(rotatePos);    
pushServo.write(pushPos);
liftServo.write(liftPos);
}