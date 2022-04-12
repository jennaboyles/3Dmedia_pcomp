#include <Adafruit_CircuitPlayground.h>

bool slideSwitch;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(A2,OUTPUT);
}

void loop() {
    slideSwitch = CircuitPlayground.slideSwitch();
 if (slideSwitch) {
    digitalWrite(A2, HIGH);
    Serial.print("+");
    } else {
    digitalWrite(A2, LOW);
  Serial.print("-");
  }
  Serial.println();
 
}
