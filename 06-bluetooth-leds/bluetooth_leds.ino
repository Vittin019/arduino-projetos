/*
 * Controle de 2 LEDs via Bluetooth (HC-05/HC-06)
 * RX = 4 | TX = 3
 * LED1 = 8 | LED2 = 9
 *
 * Comandos:
 *   A = Liga LED1
 *   B = Desliga LED1
 *   C = Liga LED2
 *   D = Desliga LED2
 */

#include <SoftwareSerial.h>

#define RX 4
#define TX 3
#define LED1 8
#define LED2 9

SoftwareSerial bluetooth(RX, TX);
char comando;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Bluetooth LEDs pronto");
}

void loop() {
  if (bluetooth.available()) {
    comando = bluetooth.read();
    Serial.print("Recebido: ");
    Serial.println(comando);

    switch (comando) {
      case 'A':
        digitalWrite(LED1, HIGH);
        break;
      case 'B':
        digitalWrite(LED1, LOW);
        break;
      case 'C':
        digitalWrite(LED2, HIGH);
        break;
      case 'D':
        digitalWrite(LED2, LOW);
        break;
    }
  }
}
