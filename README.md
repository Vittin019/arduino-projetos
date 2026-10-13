# arduino-projetos

Códigos de Arduino que eu fui fazendo nas aulas e em casa.

Organizei em pastas pra não ficar tudo misturado.

### o que tem aqui

- **01-servo-potenciometro** → servo controlado por potenciômetro
- **02-sensor-luz** → sensor de luz digital
- **03-sensor-noite-dia-lcd** → mostra "Dia" ou "Noite" no LCD
- **04-dht11-lcd** → temperatura e umidade no display
- **05-motor-dc-potenciometro** → motor dc com controle de direção e velocidade
- **06-bluetooth-leds** → controla 2 leds pelo celular via bluetooth
- **07-bluetooth-leds-temp** → mesma coisa + sensor de temperatura
- **08-bluetooth-4leds-pwm** → 4 leds com toggle
- **09-dht11-lcd-v2** → outra versão do dht11 com lcd

A maioria usa LCD I2C (endereço 0x27). Se não aparecer nada, tenta 0x3F.

Bibliotecas que costumo usar: Servo, LiquidCrystal_I2C, DHT, OneWire, DallasTemperature, SoftwareSerial.
