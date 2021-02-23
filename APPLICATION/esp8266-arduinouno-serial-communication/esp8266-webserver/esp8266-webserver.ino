#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

ESP8266WebServer server;
/* Set these to your desired credentials. */
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

void setup() {

  Serial.begin(9600);
  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/led-operation", handleLedOnRequest);

  server.begin();
}

void loop() {
  server.handleClient();
}

// http://server-ip/led-operation?type=led&pin=13&state=on
// http://server-ip/led-operation?type=led&pin=13&state=off
void handleLedOnRequest() {

  // Send a JSON-formatted request with key "type" and value "request"
  // then parse the JSON-formatted response with keys "gas" and "distance"
  StaticJsonDocument<200> doc;
  String type = server.arg("type");
  String pin = server.arg("pin");
  String state = server.arg("state");

  doc["type"] = type;
  doc["pin"] = pin;
  doc["state"] = state;
  // Sending the request
  serializeJson(doc, Serial);


  // Reading the response
  boolean messageReady = false;
  String message = "";
  while (messageReady == false) { // blocking but that's ok
    if (Serial.available()) {
      message = Serial.readString();
      messageReady = true;
    }
  }
  // Attempt to deserialize the JSON-formatted message
  DeserializationError error = deserializeJson(doc, message);
  if (error) {
    Serial.print(F("ESP deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  
  String opStatus = doc["opStatus"];
  // Prepare the data for serving it over HTTP
  String output = "{ 'type': '" + type + "','pin':'" + pin + "','state':'" + state + "','status':'" + opStatus + "'}";

  // Serve the data as plain text, for example
  server.send(200, "application/json", output);
}
