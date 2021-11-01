// Draws old Movie Theater style marquee but in color

#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

void DrawMarquee()
{
    static byte j = HUE_BLUE;
    j += 4;
    byte k = j;

    // The following is roughtly equivilent to fill_rainbow(leds, NUM_LEDS, j, 8)

    CRGB c;
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = c.setHue(k+=8);
    }

    static int scroll = 0;
    scroll++;

    for (int i = scroll % 5; i < NUM_LEDS - 1; i += 5)
    {
        leds[i] = CRGB::Black;
    }

    delay(50);
}