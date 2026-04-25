# Arduino Learning

Proyectos progresivos de Arduino como base para construir un brazo robótico de 6 ejes.
Cada proyecto introduce conceptos nuevos que se usan directamente en el brazo.

---

## Proyectos

### 01 — LED interno
Primer programa. El LED integrado en la placa parpadea cada segundo.

**Conceptos:** `pinMode`, `digitalWrite`, `delay`, estructura `setup/loop`

---

### 02 — LED externo
LED externo conectado a la protoboard con resistencia de 220Ω.

**Conceptos:** resistencias, protoboard, circuitos en serie y paralelo, Ley de Ohm

---

### 03 — Botón con memoria
Pulsador que enciende y apaga el LED como un interruptor real. Un pulso enciende, el siguiente apaga.

**Conceptos:** `INPUT_PULLUP`, detección de flanco, estado, rebotes de botón, lógica invertida

---

### 04 — Servo con potenciómetro
Control de un servo SG90 en tiempo real girando un potenciómetro.

**Conceptos:** PWM, `writeMicroseconds`, calibración de servo, pines analógicos, función `map()`

---

### 05 — Dos servos con dos potenciómetros
Dos ejes controlados de forma independiente y simultánea. Base funcional de un brazo de 2 ejes.

**Conceptos:** múltiples objetos Servo, múltiples entradas analógicas, control en tiempo real

---

## Hardware usado

- Arduino Uno
- 2x Servo SG90
- 2x Potenciómetro
- LEDs de colores
- Resistencias 220Ω
- Botón pulsador
- Protoboard
- Cables jumper

---

## Objetivo final

Construir un brazo robótico de 6 ejes con piezas impresas en 3D, motores NEMA y control desde Python con FastAPI.

---

## Stack

- C++ (Arduino IDE)
- Python + FastAPI (capa de control — próximamente)