
#include <Adafruit_CircuitPlayground.h>
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  pinMode(A2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(A2,HIGH);
  delay(500);
  digitalWrite(A2,LOW);
  delay(500);
}
