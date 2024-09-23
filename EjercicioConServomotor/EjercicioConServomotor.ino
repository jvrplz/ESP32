#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
int posDegrees = 0;    // variable to store the servo position
int servoPin = 4;

byte incomingByte = 0;
int number = 0;
String total;

// Check limit values
int checkLimits(int min_val, int max_val, int value)
{
  if (value <= min_val)
    return min_val;
  if (value >= max_val)
    return max_val;
  return value;
}

void setup() {
  Serial.begin(230400);
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo.attach(servoPin, 1000, 2000); // attaches the servo on pin 4 to the servo object  
 }

void loop() {
  // wait till receive data (only one byte)
  while (Serial.available() > 0 )
  {
    // read the incoming Byte
    incomingByte = Serial.read();
    
	// add to string only if it is digit or if it is negative sign
    if (isdigit(incomingByte) || incomingByte == '-')
    {
      total += (char)incomingByte;
    }
    
	// end receiving with \n
    if (incomingByte == '\n')
    {
      number = total.toInt();
      Serial.print("Value: ");
      Serial.println(number);
      // clear the string for new input
      total = "";
    }
  }
  myservo.write(checkLimits(0, 180, number));
  sleep(5);
}