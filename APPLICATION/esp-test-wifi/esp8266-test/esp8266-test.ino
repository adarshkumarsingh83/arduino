#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include"Config.h"

String serverResponse;
String payload = "";
int httpResponseCode = -1;

ESP8266WiFiMulti WiFiMulti;

void setup() {
  Serial.begin(BROAD_RATE);
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(WIFI_SSID, WIFI_PASSWROD);
  while ((WiFiMulti.run() != WL_CONNECTED)) {
    delay(WIFI_RECONNECT_DELAY_TIME);
    Serial.print(".");
  }
  // Debugging - Output the IP Address of the ESP8266
  Serial.println();
  Serial.print("CONNECTED TO WIFI ");
  Serial.print(WiFi.SSID());
  Serial.print(" ");
  Serial.println(WiFi.localIP());

}

void loop() {
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    serverResponse = httpGETRequest(SERVER_URL);
    // todo with the server response
    if (serverResponse != "") {
      Serial.println(serverResponse);
      delay(DELAY_TIME);
    }

  } else {
    Serial.println("NOT CONNECTED TO WIFI ");
  }
}

String httpGETRequest(const char* serverName) {

  WiFiClient client;
  HTTPClient http;

  // Your IP address with path or Domain name with URL path
  http.begin(client, serverName);

  // Send HTTP POST request
  httpResponseCode = http.GET();
  payload = "";

  if (httpResponseCode > 0) {
    //Serial.println("HTTP Response code: " + String(httpResponseCode));
    payload = http.getString();
  }
  else {
    Serial.println("Error code: " + String(httpResponseCode));
  }
  http.end();
  return payload;
}
