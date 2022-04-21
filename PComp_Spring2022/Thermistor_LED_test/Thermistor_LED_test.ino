
// https://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/
//main code copied from the above source

#include <Adafruit_CircuitPlayground.h>

//for calibration
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


int sensorPin = A1; //analog in pin. Thermistor connected to A1 and 3.3V
int redPin = 9;  //analog out Red LED on GND and 9 (A2 on Circuit Playground)
float R1 = 10000; //resistor value. Use a 10kΩ resistor instead of a 100kΩ (the thermistor in the kit is 10kΩ) 
//connect R1 to thermistor and GND as voltage divider.
int sensorValue = 0;
int Vo = 0; 
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

int outputValue = 0; //variable used to map T to LED brightness

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(redPin,OUTPUT); //A2 is pin 9 for analog output

}

void loop() {
  Vo = analogRead(sensorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 
  Serial.println(T); //print temperature as a number, no text

  outputValue = map(T, 74, 98, 0, 255); //map the incoming T values to LED brightness range
  analogWrite(redPin, outputValue); //set LED to outputValue
  Serial.println(outputValue);
  
  delay(1000);
}
