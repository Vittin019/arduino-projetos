/*
 * Controle de Servo com Potenciômetro
 * Servo no pino 2 | Potenciômetro no A0
 * Ângulo limitado entre 60° e 120°
 */

#include <Servo.h>

#define PIN_SERVO 2

Servo servo;
int angulo;

void setup() {
  Serial.begin(9600);
  servo.attach(PIN_SERVO);

  // Teste inicial do servo
  servo.write(0);
  delay(500);
  servo.write(180);
  delay(500);
  servo.write(90);
  delay(500);
}

void loop() {
  angulo = analogRead(A0);
  angulo = map(angulo, 0, 1023, 60, 120);
  servo.write(angulo);

  Serial.print("Angulo: ");
  Serial.println(angulo);
  delay(20);
}
