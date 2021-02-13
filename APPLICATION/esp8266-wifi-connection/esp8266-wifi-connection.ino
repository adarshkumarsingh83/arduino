#include <ESP8266WiFi.h>

#ifndef APSSID
#define APSSID "*****"
#define APPSK  "*****"
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin(ssid, password);
  Serial.println();
  Serial.print("Connecting");
}

void loop() {

  if ( WiFi.status() != WL_CONNECTED ) {
    digitalWrite( LED_BUILTIN , HIGH);
    Serial.println();
    Serial.println("Wifi Connected Success!");
    Serial.print("NodeMCU IP Address : ");
    Serial.println(WiFi.localIP() );
    delay(1000);    
    Serial.print(".");
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);    
  }
}
