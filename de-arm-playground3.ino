#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4; 


int potpin = A0;  // analog pin used to connect the potentiometer
//int val;   // variable to read the value from the analog pin

int currentPos1 = 90;  // start position
int currentPos2 = 90;
int currentPos3 = 90;
int currentPos4 = 90;
int targetPos1, targetPos2, targetPos3, targetPos4;


void setup() {
  servo1.attach(2);  // attaches the servo on pin 9 to the servo object
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  Serial.begin(9600);
}

void loop() {
  targetPos1 = map(analogRead(potpin), 0, 1023, 0, 180);
  targetPos2 = map(analogRead(potpin), 0, 1023, 0, 180);
  targetPos3 = map(analogRead(potpin), 0, 1023, 0, 180);
  targetPos4 = map(analogRead(potpin), 0, 1023, 0, 180);    

  // Smoothly move servo1
  if (currentPos1 < targetPos1) currentPos1++;
  else if (currentPos1 > targetPos1) currentPos1--;

  // Smoothly move servo2
  if (currentPos2 < targetPos2) currentPos2++;
  else if (currentPos2 > targetPos2) currentPos2--;
  
  // Smoothly move servo1
  if (currentPos3 < targetPos3) currentPos3++;
  else if (currentPos3 > targetPos3) currentPos3--;

  // Smoothly move servo1
  if (currentPos4 < targetPos4) currentPos4++;
  else if (currentPos4 > targetPos4) currentPos4--;

  servo1.write(currentPos1);
  servo2.write(currentPos2);
  servo3.write(currentPos3);
  servo4.write(currentPos4);  

  Serial.println(potpin);

  delay(10); // smaller delay = faster response, but less smooth

}
