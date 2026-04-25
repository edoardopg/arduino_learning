void setup() {
    pinMode(7, OUTPUT);  // pin 7, donde está el LED externo
}

void loop() {
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(7, LOW);
    delay(500);
}