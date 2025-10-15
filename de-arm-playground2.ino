#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;
// twelve servo objects can be created on most boards

int pos1 = 0;    // variable to store the servo position
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;

void setup() {
  servo1.attach(14);  // attaches the servo on pin 9 to the servo object
  servo2.attach(15);
  servo3.attach(16);
  servo4.attach(17);
  Serial.begin(9600);
}

void loop() {
  //servo1 sweep
  for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    servo1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  //servo2 sweep
  for (pos2 = 0; pos2 <= 180; pos2 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (pos2 = 180; pos2 >= 0; pos2 -= 1) { // goes from 180 degrees to 0 degrees
    servo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  //servo3 sweep
  for (pos3 = 0; pos3 <= 180; pos3 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo3.write(pos3);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (pos3 = 180; pos3 >= 0; pos3 -= 1) { // goes from 180 degrees to 0 degrees
    servo3.write(pos3);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  //servo4 sweep
  for (pos4 = 0; pos4 <= 180; pos4 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo4.write(pos4);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (pos4 = 180; pos4 >= 0; pos4 -= 1) { // goes from 180 degrees to 0 degrees
    servo4.write(pos4);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}
