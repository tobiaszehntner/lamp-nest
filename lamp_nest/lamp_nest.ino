#include "FastSPI_LED2.h"

#define NUM_LEDS 295
#define LED_PIN 6
#define POT_PIN A0

CRGB leds[NUM_LEDS];
int random_num[NUM_LEDS];


/////////////////// SETUP AND LOOP ///////////////////

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS);
  pinMode(LED_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);

  LEDS.setBrightness(255);
  shuffle(random_num, NUM_LEDS); 
  all_off();   
}

void loop() {
  set_leds(read_pot());
//  demo();
}


/////////////////// FUNCTIONS ///////////////////

void set_leds(num) {
  for(int i = 0; i <= num; i++) {
    leds[i] = CRGB(255,255,255);
  }
  for(int i = num + 1; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,0);
  }
}

int read_pot() {
  int value = analogRead(POT_PIN);
  return map(value, 0, 1023, 0, NUM_LEDS)
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
