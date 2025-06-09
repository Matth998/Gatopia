#include <Servo.h>

const int pinoSensor = 2;     
const int pinoServo = 9;      

Servo meuServo;
bool emMovimento = false;

void setup() {
  pinMode(pinoSensor, INPUT);
  meuServo.attach(pinoServo);
  meuServo.write(0); /
  Serial.begin(9600);
}

void loop() {
  int movimento = digitalRead(pinoSensor);

  if (movimento == HIGH && !emMovimento) {
    Serial.println("Movimento detectado!");
    emMovimento = true;
    meuServo.write(90);   
    delay(10000);           
    meuServo.write(0);      
    delay(100);            
    emMovimento = false;
  }
}
