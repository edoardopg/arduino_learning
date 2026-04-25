#include <Servo.h>

Servo miServo;

void setup() {
    miServo.attach(9, 500, 2400);
    Serial.begin(9600);
}

void loop() {
    int valorPot = analogRead(A0);  // lee el potenciómetro: 0 a 1023
    
    // convierte 0-1023 a 0-180 grados
    // es la misma interpolación que acabas de entender
    int grados = map(valorPot, 0, 1023, 0, 180);
    
    miServo.write(grados);
    Serial.println(grados);
    
    delay(15);
}