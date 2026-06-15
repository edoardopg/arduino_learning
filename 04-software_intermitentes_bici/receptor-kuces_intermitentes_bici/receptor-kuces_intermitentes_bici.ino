#include <RCSwitch.h>
#include <FastLED.h>

#define NUM_LEDS 3
#define DATA_PIN 6

CRGB leds[NUM_LEDS];
RCSwitch mySwitch = RCSwitch();

bool izquierda = false;
bool derecha = false;
unsigned long ultimaRecepcion = 0;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  mySwitch.enableReceive(0);
}

void loop() {
  if (mySwitch.available()) {
    if (millis() - ultimaRecepcion > 800) {
      long valor = mySwitch.getReceivedValue();
      if (valor == 1111) {
        izquierda = !izquierda;
        derecha = false;
      }
      if (valor == 2222) {
        derecha = !derecha;
        izquierda = false;
      }
      ultimaRecepcion = millis();
    }
    mySwitch.resetAvailable();
  }
  if (izquierda) {
    for(int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB::Orange;
    FastLED.show();
    delay(300);
    for(int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB::Black;
    FastLED.show();
    delay(300);
  }
  if (derecha) {
    for(int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB::Orange;
    FastLED.show();
    delay(300);
    for(int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB::Black;
    FastLED.show();
    delay(300);
  }
}
