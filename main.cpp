// Include libs
#include "FastLED.h"
#include <SoftwareSerial.h>
#define FASTLED_INTERNAL

// LED Defines
#define NUM_LEDS 150
#define LED_PIN 5

// Create leds and dht objects
CRGB leds[NUM_LEDS];

CHSV orange(10, 255, 64);
CHSV purple(192, 255, 78);
CHSV white(0, 0, 32);
int counter = 0;

int g_Brightness = 32; // 0-255

#include "marquee.h"
#include "twinkle.h"
#include "commet.h"

void setup()
{
  delay(1000);
  pinMode(LED_PIN, OUTPUT);
  //Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  //FastLED.setBrightness(64);
}

void loop()
{
  bool bLED = 0;

  uint8_t initialHue = 0;
  // How fast rainbow advances
  const uint8_t deltaHue = 16;
  // How tightly packed the rainbow is
  const uint8_t hueDensity = 2;

  for (;;) //forever
  {
    bLED = !bLED;
    digitalWrite(LED_BUILTIN, bLED);

    double dStart = millis() / 1000.0;

    fill_rainbow(leds, NUM_LEDS, initialHue += hueDensity, deltaHue);

    //DrawMarquee();
    //DrawTwinkle();
    //DrawCommet();

    FastLED.setBrightness(g_Brightness);
    FastLED.show();

    double dEnd = millis() / 1000.0;
  }


}
