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

  // Smoothly move servo1
  if (pos1 <= 90) pos1++;
  else (pos1--);

  // Smoothly move servo2
 // if (pos2 <= 180) pos2++;
  ///else (pos2--);

  // Smoothly move servo3
 // if (pos3 = 0; pos3 <= 180) pos3++;
 // else (pos3--);

  // Smoothly move servo4
//  if (pos4 = 0; pos4 <= 180) pos4++;
 // else (pos4--);

  servo1.write(pos1);
  servo2.write(pos1);
  servo3.write(pos1);
  servo4.write(pos1); 

  delay(10); // smaller delay = faster response, but less smooth
}
