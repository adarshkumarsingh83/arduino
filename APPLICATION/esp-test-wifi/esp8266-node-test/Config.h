#ifndef Config_h
#define Config_h
#include "Arduino.h"

/************************************************************************************************/
#define BROAD_RATE 115200
#define DELAY_TIME 200
#define WIFI_RECONNECT_DELAY_TIME 500


// ESP8266 do not support 5G wifi connection
#define WIFI_SSID  "adarsh-model-trains"
#define WIFI_PASSWROD  "adarsh-model-trains"

// IP OF THE SERVER MACHINE WHERE SPRING TRANSFORMER IS RUNNING
#define SERVER_URL  "http://192.168.0.188:8080/espark/adarsh"

#endif
