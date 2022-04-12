#include <Adafruit_CircuitPlayground.h>
#define LED_COUNT 20
#define LED_PIN A2

Adafruit_CPlay_NeoPixel strip = Adafruit_CPlay_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup()

{
strip.begin();
}
void loop()
{
for (int i = 0; i < LED_COUNT; i++)
{
strip.setPixelColor(i, strip.Color(255, 147, 41));
}
strip.show();
}
