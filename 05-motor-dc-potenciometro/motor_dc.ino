/*
 * Controle de Motor DC com Potenciômetro
 * PWM no pino 5 | Direção no pino 6
 * Potenciômetro no A1
 * Zona morta central para parar o motor
 */

#define PIN_DIR  6
#define PIN_PWM  5

int pot;
int velocidade;

void setup() {
  pinMode(PIN_DIR, OUTPUT);
  pinMode(PIN_PWM, OUTPUT);
  Serial.begin(9600);
  Serial.println("Controle de Motor DC iniciado");
}

void loop() {
  pot = analogRead(A1);
  Serial.print("Pot: ");
  Serial.print(pot);

  if (pot >= 490 && pot <= 530) {
    velocidade = 0;
    digitalWrite(PIN_DIR, LOW);
  }
  else if (pot > 530) {
    velocidade = map(pot, 530, 1023, 0, 255);
    digitalWrite(PIN_DIR, LOW);
  }
  else {
    velocidade = map(pot, 490, 0, 0, 255);
    digitalWrite(PIN_DIR, HIGH);
  }

  analogWrite(PIN_PWM, velocidade);

  Serial.print(" | Vel: ");
  Serial.println(velocidade);
  delay(20);
}
