/*
 * Controle de 2 LEDs via Bluetooth + Sensor de Temperatura DS18B20
 * RX = 4 | TX = 3
 * LED1 = 8 | LED2 = 9
 * Sensor DS18B20 no pino 8 (OneWire)
 *
 * Comandos:
 *   A = Liga LED1
 *   B = Desliga LED1
 *   C = Liga LED2
 *   D = Desliga LED2
 *
 * A temperatura é enviada pelo Bluetooth a cada 1 segundo
 */

#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

#define SENSOR_PIN 8
#define RX 4
#define TX 3
#define LED1 8
#define LED2 9

OneWire oneWire(SENSOR_PIN);
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;

SoftwareSerial bluetooth(RX, TX);

char comando;
unsigned long tempoAnterior = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  Serial.begin(9600);
  bluetooth.begin(9600);

  sensors.begin();
  sensors.getAddress(sensor1, 0);

  Serial.println("Bluetooth + Temp pronto");
}

void loop() {
  if (millis() - tempoAnterior >= 1000) {
    sensors.requestTemperatures();
    float tempC = sensors.getTempC(sensor1);

    Serial.print("Temp: ");
    Serial.println(tempC);
    bluetooth.println(tempC);

    tempoAnterior = millis();
  }

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
