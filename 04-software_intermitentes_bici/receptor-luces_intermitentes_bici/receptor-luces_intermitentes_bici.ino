#include <RCSwitch.h>
#include <FastLED.h>

#define NUM_LEDS 4
#define DATA_PIN_IZQ 6
#define DATA_PIN_DER 5
#define TIMEOUT_MS 30000  // 30 segundos

CRGB leds_izq[NUM_LEDS];
CRGB leds_der[NUM_LEDS];
RCSwitch mySwitch = RCSwitch();

bool izquierda = false;
bool derecha = false;
unsigned long ultimaRecepcion = 0;
unsigned long ultimaActivacion = 0;

void apagarTodo() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds_izq[i] = CRGB::Black;
    leds_der[i] = CRGB::Black;
  }
  FastLED.show();
  izquierda = false;
  derecha = false;
}

void efectoCascada(CRGB* leds) {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Orange;
    FastLED.show();
    delay(120);
  }
  delay(200);
  for(int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB::Black;
  FastLED.show();
  delay(300);
}

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN_IZQ, GRB>(leds_izq, NUM_LEDS);
  FastLED.addLeds<WS2812B, DATA_PIN_DER, GRB>(leds_der, NUM_LEDS);
  mySwitch.enableReceive(0);
}

void loop() {
  // Apagado automático por timeout
  if ((izquierda || derecha) && (millis() - ultimaActivacion > TIMEOUT_MS)) {
    apagarTodo();
  }

  if (mySwitch.available()) {
    if (millis() - ultimaRecepcion > 1500) {
      long valor = mySwitch.getReceivedValue();
      if (valor == 1111) {
        izquierda = !izquierda;
        derecha = false;
        for(int i = 0; i < NUM_LEDS; i++) leds_der[i] = CRGB::Black;
        FastLED.show();
        if (izquierda) ultimaActivacion = millis();
      }
      if (valor == 2222) {
        derecha = !derecha;
        izquierda = false;
        for(int i = 0; i < NUM_LEDS; i++) leds_izq[i] = CRGB::Black;
        FastLED.show();
        if (derecha) ultimaActivacion = millis();
      }
      ultimaRecepcion = millis();
    }
    mySwitch.resetAvailable();
  }

  if (izquierda) efectoCascada(leds_izq);
  if (derecha) efectoCascada(leds_der);
}
