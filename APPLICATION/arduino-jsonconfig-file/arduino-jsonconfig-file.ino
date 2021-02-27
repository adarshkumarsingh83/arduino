#include <ArduinoJson.h>
#include <SD.h>
#include <SPI.h>

struct NodeConfiguration {
  char* macAddr;
  char* type;
};

const char *filename = "/config.json";
NodeConfiguration nodeConfiguration;

void loadConfiguration(const char *filename, NodeConfiguration &config) {
  // Open file for reading
  File file = SD.open(filename);

  // Allocate a temporary JsonDocument
  // Don't forget to change the capacity to match your requirements.
  // Use arduinojson.org/v6/assistant to compute the capacity.
  StaticJsonDocument<512> doc;

  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, file);
  if (error)
    Serial.println(F("Failed to read file, using default configuration"));

  // Copy values from the JsonDocument to the Config
  nodeConfiguration.type = doc["type"] | "slave";
  strlcpy(nodeConfiguration.macAddr,                  // <- destination
          doc["macAddr"] | "example.com",  // <- source
          sizeof(nodeConfiguration.macAddr));         // <- destination's capacity

  // Close the file (Curiously, File's destructor doesn't close the file)
  file.close();
}

void setup() {
  Serial.begin(9600);
  while (!Serial) continue;

  // Initialize SD library
  while (!SD.begin()) {
    Serial.println(F("Failed to initialize SD library"));
    delay(1000);
  }

  // Should load default config if run for the first time
  Serial.println(F("Loading configuration..."));
  loadConfiguration(filename, nodeConfiguration);
}

void loop() {
  Serial.print("loaded configuation");
  Serial.print(" MacAddress " + String(nodeConfiguration.macAddr));
  Serial.println(" Type " + String(nodeConfiguration.type));

}
