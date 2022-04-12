//https://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/
//main code copied from the above source
//use a 10kΩ resistor instead of a 100kΩ (the thermistor in the kit is 10kΩ)

#include <Adafruit_CircuitPlayground.h>

int sensorPin = A1; //Thermistor connected to A1 and 3.3V
int tempRead;
float R1 = 10000; ////resistor value. Connect R1 to thermistor and GND as voltage divider.
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {

  tempRead = analogRead(sensorPin);
  R2 = R1 * (1023.0 / (float)tempRead - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" F"); 

  delay(1000);
}
