#include <AFMotor.h>

AF_DCMotor motor(2);

const int forcr_sensor = 2;
unsigned int condition = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(forcr_sensor, INPUT);
  motor.setSpeed(200);
  motor.run(RELEASE);
}

void loop() 
{
  int forcr_value = digitalRead(forcr_sensor);

  if (forcr_value == HIGH)
  {
    motor.run(FORWARD);
    //Serial.println("TOUCH DETECTED"); 
    condition = 1; 
  }  
  else
  {  
    //Serial.println("TOUCH NOTDETECTED");
    if(condition == 1)
    {
      motor.run(BACKWARD);
      delay(3000);
      motor.run(RELEASE);
      condition = 0;
    }  
  }  
  if (Serial.available()) 
  {
    int inByte = Serial.read();
    //Serial.write(inByte);
    switch(inByte)
    {
      case '1'://Soft        
        Serial.println("SOFT"); 
        motor.run(FORWARD);
        delay(1000);
        motor.run(RELEASE);
      break;
      case '2'://Medium
        Serial.println("MEDIUM"); 
        motor.run(FORWARD);
        delay(2000);
        motor.run(RELEASE);
      break;
      case '3'://Hard        
        Serial.println("HARD"); 
        motor.run(FORWARD);
        delay(3000);
        motor.run(RELEASE);
      break;
      case '4'://Stop
        Serial.println("OPEN"); 
        motor.run(BACKWARD);
        delay(3000);
        motor.run(RELEASE);
      break;
      case '0'://Stop
        Serial.println("STOP"); 
        motor.run(RELEASE);
      break;
    }
  }
  delay(1000);
}
