#include <Servo.h>

const int pinoSensor = 2;     // Pino do sensor PIR
const int pinoServo = 9;      // Pino do servo motor

Servo meuServo;
bool emMovimento = false;

void setup() {
  pinMode(pinoSensor, INPUT);
  meuServo.attach(pinoServo);
  meuServo.write(0); // Começa na posição 0°
  Serial.begin(9600);
}

void loop() {
  int movimento = digitalRead(pinoSensor);

  if (movimento == HIGH && !emMovimento) {
    Serial.println("Movimento detectado!");
    emMovimento = true;
    meuServo.write(90);     // Gira para 90 graus
    delay(10000);            // Espera 2 segundos
    meuServo.write(0);      // Volta para 0 graus
    delay(100);             // Evita múltiplos acionamentos seguidos
    emMovimento = false;
  }
}
