
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti WiFiMulti;

const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

const char* serverLedOn = "http://192.168.4.1/led-on";
const char* serverLedOff = "http://192.168.4.1/led-off";

String serverLedOnStatus;
String serverLedOffStatus;

void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);
  while ((WiFiMulti.run() == WL_CONNECTED)) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");

}

bool flipVar = true;
unsigned long previousMillis = 0;
const long interval = 5000;

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {

    if ((WiFiMulti.run() == WL_CONNECTED)) {
      if (flipVar) {
        serverLedOnStatus = httpGETRequest(serverLedOn);
        flipVar = false;
      } else {
        serverLedOffStatus = httpGETRequest(serverLedOff);
        flipVar = true;
      }
    } else {
      Serial.println("WiFi Disconnected");
    }
  }
}

String httpGETRequest(const char* serverName) {

  WiFiClient client;
  HTTPClient http;

  // Your IP address with path or Domain name with URL path
  http.begin(client, serverName);

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "--";

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();
  return payload;
}
