/*
{"type":76,"pin":5,"state":1}  
{"type":76,"pin":5,"state":1,"opStatus":"ON"}

{"type":76,"pin":5,"state":0}
{"type":76,"pin":5,"state":0,"opStatus":"OFF"}

{"type":76,"pin":4,"state":1}
{"type":76,"pin":4,"state":1,"opStatus":"ON"}

{"type":76,"pin":4,"state":0}
{"type":76,"pin":4,"state":0,"opStatus":"OFF"}
*/

boolean newData = false;
const byte numChars = 32;
const  char startMarker = '{';
const  char endMarker = '}';
char receivedChars[numChars];

void setup() {
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
}

void loop() {
  recvWithStartEndMarkers();
  showNewData();
}


void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char rc;
  while (Serial.available() > 0 && newData == false) {
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
        newData = true;
      }
    } else if (rc == startMarker) {
      receivedChars[ndx] = '{';
      ndx++;
      recvInProgress = true;
    }
  }
}

void showNewData() {
  if (newData == true) {
    Serial.print("This just in ... ");
    Serial.println(receivedChars);
    newData = false;
  }
}
