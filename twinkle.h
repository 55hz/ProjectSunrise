// Draws random co lored stars on an LED strip for a Twinkly effect.

#include <FastLED.h>

#define NUM_COLORS 5

static const CRGB TwinkleColors [NUM_COLORS]
{
    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Orange
};

// Fraction of 256 to fade a pixel
// by if it is to be faded this pass
const byte fadeAmt = 128;

void DrawTwinkleOld()
{
    FastLED.clear(false);

    for (int i = 0; i < NUM_LEDS / 4; i++)
    {
        leds[random(NUM_LEDS)] = TwinkleColors[random(NUM_COLORS)];
        FastLED.setBrightness(g_Brightness);
    }
    delay(200);

}

void DrawTwinkle()
{
    static int passCount = 0;
    passCount++;

    if (passCount == NUM_LEDS/4)
    {
        passCount = 0;
        //FastLED.clear(false);
    }

    

    leds[random(NUM_LEDS)] = TwinkleColors[random(NUM_COLORS)];

    for (int i = 0; i < NUM_LEDS; i++)
    {
        if (random(2) == 1)
        {
            leds[i] = leds[i].fadeToBlackBy(fadeAmt);
        }
    }

    delay(100);
}