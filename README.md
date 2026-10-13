# Projetos Arduino

Códigos organizados e revisados de projetos feitos no Arduino IDE.

## Projetos

| Pasta | Descrição | Componentes principais |
|-------|-----------|------------------------|
| [`01-servo-potenciometro`](01-servo-potenciometro) | Controle de servo com potenciômetro (60°–120°) | Servo + Potenciômetro |
| [`02-sensor-luz`](02-sensor-luz) | Leitura de sensor de luz digital | Sensor digital de luz |
| [`03-sensor-noite-dia-lcd`](03-sensor-noite-dia-lcd) | Sensor dia/noite com display LCD | Sensor digital + LCD I2C |
| [`04-dht11-lcd`](04-dht11-lcd) | Temperatura e umidade no LCD | DHT11 + LCD I2C |
| [`05-motor-dc-potenciometro`](05-motor-dc-potenciometro) | Controle de motor DC (frente/ré) com potenciômetro | Motor DC + Driver + Pot |
| [`06-bluetooth-leds`](06-bluetooth-leds) | Controle de 2 LEDs via Bluetooth | HC-05/HC-06 + LEDs |
| [`07-bluetooth-leds-temp`](07-bluetooth-leds-temp) | LEDs via Bluetooth + temperatura DS18B20 | Bluetooth + DS18B20 + LEDs |
| [`08-bluetooth-4leds-pwm`](08-bluetooth-4leds-pwm) | 4 LEDs com toggle + suporte a PWM | Bluetooth + 4 LEDs |
| [`09-dht11-lcd-v2`](09-dht11-lcd-v2) | Versão alternativa DHT11 + LCD | DHT11 + LCD I2C |

## Observações

- Todos os códigos foram limpos, padronizados e corrigidos.
- Bibliotecas usadas: `Servo`, `LiquidCrystal_I2C`, `DHT`, `OneWire`, `DallasTemperature`, `SoftwareSerial`.
- Endereço padrão do LCD I2C: `0x27`. Se não funcionar, teste `0x3F`.

## Como usar

1. Abra a pasta do projeto desejado.
2. Abra o arquivo `.ino` no Arduino IDE.
3. Instale as bibliotecas necessárias (se ainda não tiver).
4. Selecione a placa e a porta.
5. Faça o upload.
