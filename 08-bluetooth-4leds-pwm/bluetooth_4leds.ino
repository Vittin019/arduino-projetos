/*
 * Controle de 4 LEDs via Bluetooth com Toggle + PWM
 * RX = 4 | TX = 3
 * LED1 = 8 | LED2 = 9 | LED3 = 10 | LED4 = 11
 *
 * Comandos (números):
 *   1 = Alterna LED1
 *   2 = Alterna LED2
 *   3 = Alterna LED3
 *   4 = Alterna LED4
 *   Valores >= 50 = valor PWM
 */

#include <SoftwareSerial.h>

#define RX 4
#define TX 3
#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11

SoftwareSerial bluetooth(RX, TX);

bool statusLed1 = false;
bool statusLed2 = false;
bool statusLed3 = false;
bool statusLed4 = false;

int dado;
int valorPwm = 0;
unsigned long tempoAnterior = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Bluetooth 4 LEDs pronto");
}

void loop() {
  if (millis() - tempoAnterior >= 1000) {
    Serial.println("X");
    bluetooth.print("X");
    tempoAnterior = millis();
  }

  if (bluetooth.available()) {
    dado = bluetooth.read();

    if (dado == 1) {
      statusLed1 = !statusLed1;
      digitalWrite(LED1, statusLed1);
    }
    else if (dado == 2) {
      statusLed2 = !statusLed2;
      digitalWrite(LED2, statusLed2);
    }
    else if (dado == 3) {
      statusLed3 = !statusLed3;
      digitalWrite(LED3, statusLed3);
    }
    else if (dado == 4) {
      statusLed4 = !statusLed4;
      digitalWrite(LED4, statusLed4);
    }
    else if (dado >= 50) {
      valorPwm = dado;
    }
  }
}
