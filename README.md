# Vineyard Pest Monitoring With Arduino Pro

Edge Impulse project: https://studio.edgeimpulse.com/public/184880/latest

## Hardware Requirements
- [Nicla Vision](https://store.arduino.cc/products/nicla-vision)
- [Arduino MKR WAN 1310](https://store.arduino.cc/products/arduino-mkr-wan-1310)
- LoRa antenna
- Neopixel LED strip

## Software Requirements
- update the Nicla Vision firmware with the [latest Edge Impulse firmware](https://docs.edgeimpulse.com/docs/development-platforms/officially-supported-mcu-targets/arduino-nicla-vision)

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
