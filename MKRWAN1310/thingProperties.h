// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "<YOUR_THING_ID>";

const char APPEUI[]   = SECRET_APP_EUI;
const char APPKEY[]   = SECRET_APP_KEY;


int bugsCount;

void initProperties(){
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(bugsCount, 1, READ, ON_CHANGE, NULL);

}

LoRaConnectionHandler ArduinoIoTPreferredConnection(APPEUI, APPKEY, _lora_band::EU868);