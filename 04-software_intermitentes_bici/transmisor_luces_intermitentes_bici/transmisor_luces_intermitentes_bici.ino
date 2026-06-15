#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

bool btn2Anterior = HIGH;
bool btn3Anterior = HIGH;

void setup() {
  mySwitch.enableTransmit(12);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  bool btn2 = digitalRead(2);
  bool btn3 = digitalRead(3);

  if (btn2 == LOW && btn2Anterior == HIGH) {
    mySwitch.send(1111, 24);
    delay(200);
  }
  if (btn3 == LOW && btn3Anterior == HIGH) {
    mySwitch.send(2222, 24);
    delay(200);
  }

  btn2Anterior = btn2;
  btn3Anterior = btn3;
}
