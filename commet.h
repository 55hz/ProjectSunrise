// Draws random co lored stars on an LED strip for a Twinkly effect.

#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

//extern CRGB leds();

void DrawCommet()
{
    //FastLED.clear(false);

    // Fraction of 256 to fade a pixel
    // by if it is to be faded this pass
    const byte fadeAmt = 128;

    // Size of comet in pixels
    const int cometSize = 5;

    // How far to step the cycling hue each draw
    const int deltaHue = 4;

    //How far to advance the comet every frame
    const double cometSpeed = 0.5;

    static byte hue = HUE_RED;  // Current color
    static int iDirection = 1;  // Current direction (-1 or +1)
    static double iPos = 0.0;   // Current comet position on strip

    hue += deltaHue;            // Update the comet color
    iPos += iDirection * cometSpeed;        // Update the comet position

    // Flip the comet direction when it hits either end
    if (iPos == (NUM_LEDS - cometSize) || iPos == 0)
    {
        iDirection *= -1;
    }

    // Draw the comet at its current position
    for (int i = 0; i < cometSize; i++)
    {
        leds[(int)iPos + i].setHue(hue);
    }

    for (int i = 0; i < NUM_LEDS; i++)
    {
        if (random(2) == 1)
        {
            leds[i] = leds[i].fadeToBlackBy(fadeAmt);
        }
    }

    //delay(5);
}