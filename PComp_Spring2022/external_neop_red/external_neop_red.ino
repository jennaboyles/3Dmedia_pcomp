#include <Adafruit_CircuitPlayground.h>
// do NOT include the standard NeoPixel library

#define NEOPIX_PIN    A2
#define NUM_PIXELS    20

Adafruit_CPlay_NeoPixel strip = Adafruit_CPlay_NeoPixel(NUM_PIXELS, NEOPIX_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  CircuitPlayground.begin();

  // initialize external NeoPixel strip separately
  strip.begin();

}

void loop() {
 CircuitPlayground.clearPixels();
  // for the external NeoPixels, must use the Adafruit_CPlay_NeoPixel functions directly
  strip.clear();

  delay(500);

 for (int i = 0; i <= 20; i++) {
  strip.setPixelColor(i, 255,   0,   0);
    }

  strip.show();
}
