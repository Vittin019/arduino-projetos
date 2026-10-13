/*
 * Sensor DHT11 (Temperatura e Umidade) + LCD I2C
 * DHT11 no pino 7
 * LCD I2C endereço 0x27 (16x2)
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte grau[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, grau);

  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(umidade) || isnan(temperatura)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro no sensor!");
    delay(2000);
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1);
  lcd.write(0);
  lcd.print("C   ");

  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(umidade, 1);
  lcd.print("%   ");

  delay(2000);
}
