#include "arduino_secrets.h"
#include "thingProperties.h"
#include <Adafruit_NeoPixel.h>

#define PIN 0
#define NUMPIXELS 12

unsigned long previousMillis = 0;
const long interval = 30000;  // 30 second interval

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  Serial1.begin(9600);
  pixels.begin();

  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection, false);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  for (int i = 0; i < NUMPIXELS; i++) {  // For each pixel...
    pixels.setPixelColor(i, pixels.Color(250, 250, 250));
  }
  pixels.show();
}

void loop() {
  unsigned long currentMillis = millis();

  if (Serial1.available()) {
    bugsCount = Serial1.parseInt();
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ArduinoCloud.update();
  }
}
