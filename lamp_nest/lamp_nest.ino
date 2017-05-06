#include "FastSPI_LED2.h"
#define NUM_LEDS 295
#define DATA_PIN 6
CRGB leds[NUM_LEDS];
byte r                 = 255;   // (0-127)
byte g                 = 255;   // (0-127)
byte b                 = 255;   // (0-127)
int randNum[NUM_LEDS];

void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(2000);
    FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
    // For safety (to prevent too high of a power draw), the test case defaults to
    // setting brightness to 25% brightness
    LEDS.setBrightness(255);
//    LEDS.addLeds<WS2811, 13>(leds, NUM_LEDS);
    r = 0;   // (0-127)
    g = 0;   // (0-127)
    b = 0;   // (0-127)
    for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB(r,g,b);
    }
    FastLED.show();

    for(int i=0; i < NUM_LEDS; i++) {
    randNum[i] = i;
  }
//  shuffle(randNum, NUM_LEDS); 

    
}

void loop() {
    for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[randNum[whiteLed]] = CRGB(255,255,255);
      FastLED.show(); 
    }
    delay(1000);
    for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[randNum[whiteLed]] = CRGB(0,0,0);
      FastLED.show(); 
    }
    delay(1000);
}

void shuffle (int* randNum, int n)
  {
  while (--n >= 2)
    {
    // n is now the last pertinent index
    int k = random (n); // 0 <= k <= n - 1
    // Swap
    int temp = randNum[n];
    randNum[n] = randNum[k];
    randNum[k] = temp;
    }
}
