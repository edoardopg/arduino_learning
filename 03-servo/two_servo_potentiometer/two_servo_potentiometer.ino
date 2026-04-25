#include <Servo.h>

Servo miServo;
Servo miServo_2;

void setup() {
    miServo.attach(9, 500, 2400);
    miServo_2.attach(11, 500, 2400);
    Serial.begin(9600);
}

void loop() {
    int valorPot = analogRead(A0);  // lee el potenciómetro: 0 a 1023
    int valorPot_2 = analogRead(A1);
    
    // convierte 0-1023 a 0-180 grados
    // es la misma interpolación que acabas de entender
    int grados = map(valorPot, 0, 1023, 0, 180);
    int grados_2 = map(valorPot_2,0,1023,0,180);
    
    miServo.write(grados);
    miServo_2.write(grados_2);
    Serial.println(grados);
    Serial.println(grados_2);
    
    delay(15);
}