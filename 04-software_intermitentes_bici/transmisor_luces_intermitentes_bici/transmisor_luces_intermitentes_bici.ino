#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  mySwitch.enableTransmit(12);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(2) == LOW) {
    mySwitch.send(1111, 24);
    delay(500);
  }
  if (digitalRead(3) == LOW) {
    mySwitch.send(2222, 24);
    delay(500);
  }
}
