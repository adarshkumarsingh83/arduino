#include <ArduinoJson.h>
#include <SoftwareSerial.h>

#define GREEN_PIN 5

const char LED_TYPE = 'L'; // 76  L
const long interval = 1000;
unsigned long previousMillis = 0;

String data = "";
bool dataAvalable = false;
bool flag1 =  true;
bool flag2 =  true;
bool swtich =  true;
bool greenState = false;

SoftwareSerial softwareSerial(3, 1); // (Rx, Tx)

void setup() {
  // Init Serial Monitor
  Serial.begin(9600);
  softwareSerial.begin(9600);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (greenState) {
      digitalWrite(GREEN_PIN, HIGH);
      greenState = false;
    } else {
      digitalWrite(GREEN_PIN, LOW);
      greenState = true;
    }



    if (swtich) {
      swtich = false;
      if (flag1) {
        flag1 = false;
        testEspToUno( flag1, 5);
      } else {
        flag1 = true;
        testEspToUno(flag1, 5);
      }
    } else {
      swtich = true;
      if (flag2) {
        flag2 = false;
        testEspToUno(flag2, 4);

      } else {
        flag2 = true;
        testEspToUno(flag2, 4);
      }
    }

    if (softwareSerial.available()) {
      data = softwareSerial.readString();
      dataAvalable = true;
    }

    if (dataAvalable) {
      DynamicJsonDocument jsonDocument(128);
      DeserializationError error = deserializeJson(jsonDocument, data);
      if (error) {
        //Serial.print(F("ESP deserializeJson() failed: "));
        //Serial.println(error.c_str());
        data = "";
        return;
      }

      String type = jsonDocument["type"];
      String pin = jsonDocument["pin"];
      String state = jsonDocument["state"];
      String opStatus = jsonDocument["opStatus"];
      String output = "Uno Response = { 'type': '" + type + "','pin':'" + pin + "','state':'" + state + "','status':'" + opStatus + "'}";
       // to print response 
      //softwareSerial.println(output);
      data = "";
      dataAvalable = false;
    }
  }
}

void testEspToUno(bool flag, int pin) {
  DynamicJsonDocument jsonDocument(128);
  jsonDocument["type"] = LED_TYPE;
  jsonDocument["pin"] = pin;
  jsonDocument["state"] = flag;
  serializeJson(jsonDocument, softwareSerial);
  Serial.println();
  Serial.flush();
}
