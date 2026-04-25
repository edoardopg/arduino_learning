void setup() {
    // Esto se ejecuta UNA SOLA VEZ al encender el Arduino
    pinMode(13, OUTPUT);  
    // Le dices al Arduino: "el pin número 13 va a ser de salida"
    // es decir, va a ENVIAR electricidad, no recibirla
}

void loop() {
    // Esto se repite INFINITAMENTE mientras el Arduino tenga luz
    
    digitalWrite(13, HIGH);  // Manda corriente al pin 13 → LED se ENCIENDE
    delay(1000);              // Espera 1000 milisegundos = 1 segundo
    digitalWrite(13, LOW);   // Corta la corriente al pin 13 → LED se APAGA
    delay(1000);              // Espera 1 segundo
    
    // Y vuelve a empezar... para siempre
}