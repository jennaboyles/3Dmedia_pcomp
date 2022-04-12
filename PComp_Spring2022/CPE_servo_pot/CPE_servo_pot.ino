#include <Adafruit_Circuit_Playground.h>
#include <Servo.h> // Call the servo library (built into the IDE)

Servo myservo;
int pos = 0;  // variable to store the position value
int sensorPin = A0;    // select the input pin for the potentiometer (could also be a photocell or other sensor)

void setup() {
  // declare the ledPin as an OUTPUT:
 myservo.attach(A3); // Pin connected to servo
}

void loop() {
  // read the value from the sensor:
  int sensorValue = analogRead(sensorPin);
  // scale 1024 values to 180
  sensorValue = map(sensorValue, 0, 1023, 0, 179);
  //Scale of 0-179 (180 values)
  pos = constrain(sensorValue, 0, 179);

  myservo.write(pos); //set the servo angle
  delay(100);
}
