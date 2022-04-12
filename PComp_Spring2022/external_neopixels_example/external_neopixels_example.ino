#include <Adafruit_CircuitPlayground.h>
// do NOT include the standard NeoPixel library

#define NEOPIX_PIN    A2
#define NUM_PIXELS    20 // number of pixels on strip
int myPixels[] = {0, 1, 2, 3, 4};;  // an array to reuse 5 pixels at a time

// use Adafruit_CPlay_NeoPixel to create a separate external NeoPixel strip
Adafruit_CPlay_NeoPixel strip = Adafruit_CPlay_NeoPixel(NUM_PIXELS, NEOPIX_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // initialize the Circuit Playground as usual
  // this will initialize the onboard NeoPixels as well
  CircuitPlayground.begin();

  // initialize external NeoPixel strip separately
  strip.begin();
}

void loop() {
  // for the on board NeoPixels, use the CircuitPlayground functions
  CircuitPlayground.clearPixels();
  
  // for the external NeoPixels, must use the Adafruit_CPlay_NeoPixel functions directly
  strip.clear();
  strip.show();

  delay(500);

 for (int i = 0; i <= 5; i++) {
  strip.setPixelColor(i, strip.Color(255,  0,  0)); //set first 5 to red
    }
 for (int i = 5; i <= 10; i++) {
  strip.setPixelColor(i, strip.Color(128, 128,  0)); //set next 5 to yellow
    }
 for (int i = 10; i <= 15; i++) {
  strip.setPixelColor(i, strip.Color(0, 255,   0));  //set next 5 to green
    }
 for (int i = 15; i <= 20; i++) {
  strip.setPixelColor(i, strip.Color(0, 128, 128)); //set last 5 to blue
    }


//these are onboard LEDS
  CircuitPlayground.setPixelColor(0, 255,   0,   0); //first neopixel on board set to red
  CircuitPlayground.setPixelColor(1, 128, 128,   0); // second neopixel set to yellow
  CircuitPlayground.setPixelColor(2,   0, 255,   0); // third neopixel set to green
  CircuitPlayground.setPixelColor(3,   0, 128, 128); // fourth neopixel set to light blue
  CircuitPlayground.setPixelColor(4,   0,   0, 255); // fifth pixel to...
  
  CircuitPlayground.setPixelColor(5, 0xFF0000); // set to red
  CircuitPlayground.setPixelColor(6, 0x808000); // yellow
  CircuitPlayground.setPixelColor(7, 0x00FF00); // green
  CircuitPlayground.setPixelColor(8, 0x008080); // light blue
  CircuitPlayground.setPixelColor(9, 0x0000FF); // dark blue

  
  // but for the external strip, must call show()
  strip.show();

  delay(5000);
}

//sets all leds to red
// for (int i = 0; i <= 20; i++) {
//  strip.setPixelColor(i, 255,   0,   0);
//    }
