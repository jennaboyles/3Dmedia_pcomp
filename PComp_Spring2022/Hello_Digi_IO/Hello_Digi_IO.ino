#include <Adafruit_CircuitPlayground.h>

bool leftButtonPressed;
bool rightButtonPressed;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(A2,OUTPUT);
}

void loop() {
   leftButtonPressed = CircuitPlayground.leftButton();
   rightButtonPressed = CircuitPlayground.rightButton();

Serial.print("Left Button:");
if (leftButtonPressed) {
  Serial.print("DOWN");
  digitalWrite(A2,HIGH);
}else{
  Serial.print("UP");
  digitalWrite(A2,LOW);
}
 Serial.print("   Right Button: ");
  if (rightButtonPressed) {
    Serial.print("DOWN");
  } else {
    Serial.print("  UP");  
  }
   Serial.println();
 
}
