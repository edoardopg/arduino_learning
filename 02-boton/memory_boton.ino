int estadoLED = LOW;      // guardamos si el LED está encendido o apagado
int botonAnterior = HIGH; // guardamos cómo estaba el botón antes

void setup() {
    pinMode(7, OUTPUT);
    pinMode(2, INPUT_PULLUP);
}

void loop() {
    int botonAhora = digitalRead(2); // leemos el botón

    // detectamos exactamente el momento en que se pulsa
    // es decir cuando pasa de HIGH a LOW
    if (botonAnterior == HIGH && botonAhora == LOW) {
        
        // cambiamos el estado del LED al contrario
        if (estadoLED == LOW) {
            estadoLED = HIGH;
        } else {
            estadoLED = LOW;
        }
        
        digitalWrite(7, estadoLED); // aplicamos el nuevo estado
    }

    botonAnterior = botonAhora; // guardamos el estado del botón para el siguiente loop
    delay(50); // pequeña pausa para evitar rebotes del botón
}