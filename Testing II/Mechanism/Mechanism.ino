//Backpack design coding

// Include the Servo library
#include <Servo.h> 

// Declare the Servo pin
int servoPin = 3;
// Declare the LED pin
int ledPin = 8;
// Declare the output
int analogOutPin = 6;

// Value from the pot
int analogInPin = 0;
// SensorValue is an integer
int sensorValue = 0;
// outputValue is an integer
int outputValue = 0;

// Create a servo object
Servo Servo1;

void setup() {
  // We need to attach the servo to the used pin number
  Servo1.attach(servoPin);
  pinMode(ledPin, OUTPUT);
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop(){
  digitalWrite(ledPin, HIGH);
  delay(100);
  //  digitalWrite(8, LOW);
  //  delay(100);


  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  //0-->1023 == 1-->120
  outputValue = map(sensorValue, 0, 1023, 0, 120);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

//  Serial.print("sensor = ");
  Serial.println(sensorValue);
//  Serial.println(Serial.readString());
  
  // Make servo go from 0 to 120 degrees
  //Or -60 to 60
  Servo1.write(outputValue);
//  Servo1.write(60);
  delay(100);
}
