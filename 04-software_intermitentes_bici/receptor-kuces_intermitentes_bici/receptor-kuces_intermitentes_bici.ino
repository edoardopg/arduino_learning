#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

bool izquierda = false;
bool derecha = false;

void setup() {
  mySwitch.enableReceive(0);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  if (mySwitch.available()) {
    long valor = mySwitch.getReceivedValue();
    if (valor == 1111) {
      izquierda = !izquierda;
      derecha = false;
    }
    if (valor == 2222) {
      derecha = !derecha;
      izquierda = false;
    }
    mySwitch.resetAvailable();
  }
  if (izquierda) {
    digitalWrite(7, HIGH);
    delay(300);
    digitalWrite(7, LOW);
    delay(300);
  }
  if (derecha) {
    digitalWrite(6, HIGH);
    delay(300);
    digitalWrite(6, LOW);
    delay(300);
  }
}
