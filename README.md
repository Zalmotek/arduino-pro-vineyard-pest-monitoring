# Vineyard Pest Monitoring With Arduino Pro

Edge Impulse project: https://studio.edgeimpulse.com/public/184880/latest

## How to use 

- In *MKRWAN1310/arduino_secrets.h* update `SECRET_APP_KEY` and `SECRET_APP_EUI`
- in *thingProperties.h* update `THING_ID`

## Wiring

| Arduino MKR WAN 1310 | Arduino Nicla Vision |
| ----------- | ----------- |
| PB_9 (TX) | D13 (RX) |
| GND | GND |

| Arduino MKR WAN 1310 | Neopixel LEDs |
| ----------- | ----------- |
| D0 | DIN |
| GND | GND |
