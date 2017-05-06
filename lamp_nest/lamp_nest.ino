#include "FastSPI_LED2.h"

#define NUM_LEDS 295
#define DATA_PIN 6

CRGB leds[NUM_LEDS];
int random_num[NUM_LEDS];


/////////////////// SETUP AND LOOP ///////////////////

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(255);  
  shuffle(random_num, NUM_LEDS); 
  all_off();   
}

void loop() {
  demo();
}


/////////////////// FUNCTIONS ///////////////////
void demo() {
 for(int i = 0; i < NUM_LEDS; i++) {
    leds[random_num[i]] = CRGB(255,255,255);
    FastLED.show(); 
  }
  delay(1000);
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[random_num[i]] = CRGB(0,0,0);
    FastLED.show(); 
  }
  delay(1000); 
}

void all_off() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}

void shuffle (int* random_num, int n) {
  while (--n >= 2) {
    int k = random (n);
    int temp = random_num[n];
    random_num[n] = random_num[k];
    random_num[k] = temp;
  }
}
