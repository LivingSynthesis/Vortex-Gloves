#ifndef Patterns_h
#define Patterns_h

#include "Arduino.h"
#include <FastLED.h>
#include "Modes.h"


#define NUM_LEDS 28
#define totalModes 14
#define DATA_PIN 4

class Patterns
{
  public:
    Patterns();

    CRGB leds[NUM_LEDS];
    CRGB copy[NUM_LEDS];

    Modes mode;

    unsigned long time1 = 5;
    unsigned long time2 = 8;
    unsigned long time3 = 0;
    unsigned long time4 = 0;

    bool on, on2, on3, on4;
    byte frame = 0;
    int gap;

    byte dot = 0;
    byte k = 0;
    unsigned long mainClock, prevTime, duration, prevTime2, duration2, duration3, duration4;
    unsigned long prevTime3, prevTime4;
    int rep = 0;
    int finger = 0;
    int prevHue = 0;

    int hue, sat, val;

    void playPattern();
    void refresh(Modes thisMode);
    CRGB getLed(int i);

    void adjustValues(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);

  private:
    void getColor(int target);
    void setLed(int target);
    void setLeds(int first, int last);
    void nextColor(int start);
    void nextColor1(int start);
    void clearAll();
    void clearLight(int lightNum);
    void clearLights(int first, int last);

    void basicPattern(unsigned long onDuration, unsigned long offDuration = 0, unsigned long gapDuration = 0);
    void dashDops(unsigned long dashDuration, unsigned long dotDuration, unsigned long offDuration);
    void tracer(unsigned long dashDuration, unsigned long dotDuration);
    void blendPattern(unsigned long onDuration, unsigned long offDuration);
    void brackets(unsigned long onDuration, unsigned long edgeDuration = 0, unsigned long offDuration = 50);
    void theaterChase(unsigned long onDuration, unsigned long offDuration, unsigned long flipDuration = 25, unsigned long fingerDuration = 125);
    void zigZag(unsigned long onDuration, unsigned long offDuration, unsigned long zipDuration = 25);
    void zipFade(unsigned long onDuration, unsigned long offDuration, unsigned long zipDuration, unsigned long fadeDuration);
    void tipTop(unsigned long onDuration, unsigned long offDuration, unsigned long onDuration2, unsigned long offDuration2);
};

#endif
