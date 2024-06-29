Voice-Guided SmartGrip Gloves for Parkinson's Patients
Overview
The Voice-Guided SmartGrip Gloves are an assistive technology designed to help individuals with Parkinson's disease. These gloves feature pressure sensors and speech recognition to enhance grip stability and manage hand tremors. The design prioritizes comfort and adaptability, making them suitable for various hand sizes. This project aims for continuous improvement based on user feedback to best serve the needs of Parkinson's patients.
Table of Contents
•	Overview
•	Features
•	System Requirements
•	Installation
•	Usage
•	Code
•	Testing
•	Results
•	Conclusion
•	Acknowledgements
•	Contact
Features
•	Improved Grip Control: Assists users in maintaining a secure grip to counteract tremors.
•	Voice Commands: Allows hands-free operation via speech recognition.
•	Comfortable Design: Adjustable fit for various hand sizes and extended use.
•	User-Driven Development: Iteratively improved based on feedback from Parkinson's patients.
System Requirements
Software
•	Compatible operating system (Windows, macOS, Linux)
•	Python 3.x
•	Required Python packages (listed in requirements.txt)
Hardware
•	Microcontroller (e.g., Arduino, Raspberry Pi)
•	Pressure sensors
•	Microphone for speech input
•	Actuators for grip adjustment
Installation
1.	Clone the repository:
sh
Copy code
git clone https://github.com/username/SmartGripGloves.git
cd SmartGripGloves
2.	Install necessary Python packages:
sh
Copy code
pip install -r requirements.txt
3.	Set up the hardware according to the provided circuit diagram.
Usage
1.	Connect the microcontroller to your computer and power it on.
2.	Run the main script:
sh
Copy code
python main.py
3.	Wear the gloves and use voice commands to control the grip. The gloves will adjust based on the input received.
Code
cpp
Copy code
// sri
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
    condition = 1; 
  }  
  else
  {  
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
Testing
•	Unit Tests: Verify individual components and functions.
•	Integration Tests: Ensure proper interaction between hardware and software.
•	User Testing: Gather feedback from Parkinson's patients during use.
Results
•	System Architecture: [Link to Architecture Diagram]
•	Prototype Images: [Link to Prototype Images]
•	Setup Instructions: [Link to Setup Instructions]
Conclusion
The Voice-Guided SmartGrip Gloves project aims to enhance the daily lives of Parkinson's patients by providing a reliable and user-friendly assistive device. Continuous refinement and user feedback are key to its development and effectiveness.
Acknowledgements
Our sincere thanks to the management and Global Academy of Technology for their support and resources. Special thanks to:
•	Dr. N. Rana Pratap Reddy, Principal, Global Academy of Technology
•	Dr. Kiran YC, Professor and Head, Department of ISE, Global Academy of Technology
•	Prof. Sharmila Chidaravalli, Assistant Professor, Department of ISE, Global Academy of Technology
We also extend our gratitude to all teaching and non-teaching staff, our parents, friends, and everyone who contributed to this project.

