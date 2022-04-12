//reference: https://learn.adafruit.com/circuit-playground-digital-input/pull-it-down

#include <Adafruit_CircuitPlayground.h>

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(A2, INPUT_PULLDOWN); //attach 10kΩ resistor between GND and A2 
  pinMode(A3, INPUT_PULLDOWN); //attach another 10kkΩ resistor between GND and A3
}

void loop() {
  int button1State = digitalRead(A2);
  int button2State = digitalRead(A3);
  
  Serial.print(button1State);
  Serial.println(button2State);
  
  if (button1State == HIGH){
    CircuitPlayground.setPixelColor(4, 255, 0, 0); //set onboard NeoP to red if A2 is high
  }
  else {
    CircuitPlayground.setPixelColor(4, 0, 0, 255); //set it to blue
  }

   if (button2State == HIGH){
    CircuitPlayground.setPixelColor(5, 255, 0, 0); //set onboard NeoP to red if A3 is high
  }
  else {
    CircuitPlayground.setPixelColor(5, 0, 0, 255); //set it to blue
  }

  delay(500);
}
