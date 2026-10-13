/*
 * Sensor DHT11 (Temperatura e Umidade) + LCD I2C - Versão limpa
 * DHT11 no pino 2
 * LCD I2C endereço 0x27 (16x2)
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(umidade) || isnan(temperatura)) {
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1);
  lcd.write(223);
  lcd.print("C   ");

  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(umidade, 1);
  lcd.print("%   ");

  delay(2000);
}
