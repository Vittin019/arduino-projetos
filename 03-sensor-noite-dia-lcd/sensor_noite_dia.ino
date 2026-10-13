/*
 * Sensor Dia/Noite com LCD I2C
 * Sensor digital no pino 3
 * LCD I2C endereço 0x27 (16x2)
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define PIN_SENSOR 3

int valorSensor;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(PIN_SENSOR, INPUT);
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Sensor Dia/Noite");
  delay(1500);
  lcd.clear();
}

void loop() {
  valorSensor = digitalRead(PIN_SENSOR);
  Serial.println(valorSensor);

  lcd.clear();
  lcd.setCursor(0, 0);

  if (valorSensor == 0) {
    lcd.print("Dia");
  } else {
    lcd.print("Noite");
  }

  delay(800);
}
