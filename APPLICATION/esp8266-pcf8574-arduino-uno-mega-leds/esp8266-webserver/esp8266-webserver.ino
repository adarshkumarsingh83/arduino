#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

ESP8266WebServer server;
/* Set these to your credentials. */
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

// http://server-ip/led-operation?type=led&led=13&state=on
// http://server-ip/led-operation?type=led&led=13&state=off
void handleLedOnRequest() {

  // Send a JSON-formatted request with key "type" and value "request"
  // then parse the JSON-formatted response with keys "gas" and "distance"
  DynamicJsonDocument doc(128);
  String type = server.arg("type");
  String led = server.arg("led");
  String state = server.arg("state");

  doc["type"] = type;
  doc["ledNo"] = led;
  doc["state"] = state;
  doc["pin"]="-";
  doc["board"]="-";
  doc["opStatus"]="-";
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
  int board = doc["board"];
  int pin = doc["pin"];
  // Prepare the data for serving it over HTTP
  String output = "{ 'type': '" + type + "','board':'" + board + "','pin':'" + pin + "','state':'" + state + "','status':'" + opStatus + "'}";

  // Serve the data as plain text, for example
  server.send(200, "application/json", output);
}
