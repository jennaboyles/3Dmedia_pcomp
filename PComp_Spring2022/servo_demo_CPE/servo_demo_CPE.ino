//demo for basic sweep control

//include libraries
#include <Adafruit_CircuitPlayground.h>
#include <Servo.h>

Servo myservo;
int pos = 0; // variable for position value

void setup() {
  CircuitPlayground.begin();
  myservo.attach(A3); // attach your motor data wire to A3 on CPE
}

//this loop code is identical to Examples > Servo > Sweep 
void loop() {
   for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
