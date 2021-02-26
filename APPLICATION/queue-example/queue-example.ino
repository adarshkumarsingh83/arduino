#include "Queue.h"

/*
   search the lib Arduino-Queue.h in lib manager
*/

String serialData = "";

#define QUEUE_SIZE_ITEMS 10

Queue<String> queue = Queue<String>();
bool dataAvalable = false;
const byte numChars = 32;
const  char startMarker = '{';
const  char endMarker = '}';
char receivedChars[numChars];
void setup() {
  // Init Serial Monitor
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {

    serialData = recivedSerialJsonData();
    if (queue.count() != 256) {
      queue.push(serialData);
    } else {
      String data = queue.pop();
      Serial.println(data);
    }
  }
}

String recivedSerialJsonData() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char rc;
  String data;
  while (Serial.available() > 0 && Serial == false) {
    rc = Serial.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      } else {
        receivedChars[ndx] = '}';
        ndx++;
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        dataAvalable = true;
      }
    } else if (rc == startMarker) {
      receivedChars[ndx] = '{';
      ndx++;
      recvInProgress = true;
    }
  }
  data = receivedChars;
  return  data;
}
