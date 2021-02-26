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

SoftwareSerial s(3, 1); // (Rx, Tx)

void setup() {
  // Init Serial Monitor
  Serial.begin(9600);
  s.begin(9600);
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

    DynamicJsonDocument doc(128);

    if (swtich) {
      swtich = false;
      if (flag1) {
        flag1 = false;
        testEspToUno(doc, flag1, 5);
      } else {
        flag1 = true;
        testEspToUno(doc, flag1, 5);
      }
    } else {
      swtich = true;
      if (flag2) {
        flag2 = false;
        testEspToUno(doc, flag2, 4);

      } else {
        flag2 = true;
        testEspToUno(doc, flag2, 4);
      }
    }

    if (s.available()) {
      data = s.readString();
      dataAvalable = true;
    }

    if (dataAvalable) {
      DeserializationError error = deserializeJson(doc, data);
      if (error) {
        //Serial.print(F("ESP deserializeJson() failed: "));
        //Serial.println(error.c_str());
        data = "";
        return;
      }

      String type = doc["type"];
      String pin = doc["pin"];
      String state = doc["state"];
      String opStatus = doc["opStatus"];
      String output = "Uno Response = { 'type': '" + type + "','pin':'" + pin + "','state':'" + state + "','status':'" + opStatus + "'}";
      //Serial.println(output);
      data = "";
      dataAvalable = false;
    }
  }
}

void testEspToUno(DynamicJsonDocument doc, bool flag, int pin) {
  doc["type"] = LED_TYPE;
  doc["pin"] = pin;
  doc["state"] = flag;
  serializeJson(doc, s);
  Serial.flush();
  Serial.println();
}

void displayData(int id, char type, int pin, boolean state) {
  Serial.println();
  Serial.print("DATA RECIEVED  ::=>");
  Serial.print(id);
  Serial.print("  ");
  Serial.print(type);
  Serial.print(" ");
  Serial.print(pin);
  Serial.print(" ");
  Serial.print(state);
  Serial.println();
}
