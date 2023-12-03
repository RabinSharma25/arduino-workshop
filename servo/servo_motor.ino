#include<Servo.h>
const int servoPin = 7; // connect signal pin to pin 5
int servoPos = 0;
Servo myServo; // create a servo object

void setup() 
{
Serial.begin(9600);
myServo.attach(servoPin);
}

void loop() 
{
myServo.write(180);
delay(2000);
myServo.write(0);
delay(2000);
}
