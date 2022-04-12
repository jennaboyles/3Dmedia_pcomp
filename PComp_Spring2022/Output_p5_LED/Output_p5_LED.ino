#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);  // initialize serial communications
  pinMode(9, OUTPUT);  // pin 9 is labeled A2 on the board. Connect an LED to GND and A2
}

//Circuit Playground Express Analog Pins A0-A7 - refer to pinout sheet 

void loop() {
  if (Serial.available() > 0) { // if there's serial data available
    int inByte = Serial.read();   // read it
    Serial.write(inByte);         // send it back out as raw binary data
   analogWrite(9, inByte);       // use it to set the LED brightness
    // if you're using a speaker instead of an LED, uncomment line below  and comment out the previous line:
   // tone(A0, inByte*10);     // play tone on pin A0 (Circuit Playground Speaker)
  }
}
