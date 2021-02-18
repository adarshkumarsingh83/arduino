#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"

// Set your access point network credentials
const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Assign output variables to GPIO pins
const int LED_PIN = D0;

String ledOnAction() {
  digitalWrite(LED_PIN, HIGH);
  return String("LED IS ON");
}

String ledOffAction() {
  digitalWrite(LED_PIN, LOW);
  return String("LED IS OFF");
}

void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/led-on", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", ledOnAction().c_str());
  });

  server.on("/led-off", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", ledOffAction().c_str());
  });

  // Start server
  server.begin();
}

void loop() {

}
