/*
  NODEMCU ESP8266 WEB SERVER CODE
*/
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <Wire.h>


// Set your access point network credentials
const char* ssid = "adarsh_radha_2G";
const char* password = "Endless@1309";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);


String ledOnAction() {
  Wire.beginTransmission(8);
  Wire.write("{\"gpio\":3,\"state\":1}");
  Wire.endTransmission();
  Serial.println("LED IS ON");
  return String("LED IS ON");
}

String ledOffAction() {
  Wire.beginTransmission(8);
  Wire.write("{\"gpio\":3,\"state\":0}");
  Wire.endTransmission();
  Serial.println("LED IS OFF");
  return String("LED IS OFF");
}

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/led-on", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", ledOnAction().c_str());
  });

  server.on("/led-off", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", ledOffAction().c_str());
  });

  server.begin();
}

void loop() {

}
