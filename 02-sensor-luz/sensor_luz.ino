/*
 * Sensor de Luz Digital
 * Sensor digital no pino 3
 */

#define PIN_SENSOR 3

int valorSensor;

void setup() {
  pinMode(PIN_SENSOR, INPUT);
  Serial.begin(9600);
  Serial.println("Sensor de Luz iniciado");
}

void loop() {
  valorSensor = digitalRead(PIN_SENSOR);
  Serial.println(valorSensor);
  delay(500);
}
