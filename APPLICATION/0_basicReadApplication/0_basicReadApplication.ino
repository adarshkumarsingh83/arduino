void setup() {
  Serial.begin(9600);
}

void loop() {
   char inputChar = readByteData();
   Serial.println(inputChar);

  String  inputString = readString();
  Serial.println(inputString);

  int inputInt = readInteger();
  Serial.println(inputInt);
}

char readByteData() {
  clearSerialBuffer();
  char byteInput = 0;
  Serial.println("Enter your Byte Data.");
  while (Serial.available() == 0) {
  }

  byteInput = Serial.read();

  // check if a number was received
  if ((byteInput >= '0')) {
    Serial.print("Number received: ");
  } else {
    Serial.println("Not a number.");
  }
  return byteInput;
}

String readString() {
  clearSerialBuffer();
  Serial.println("Enter your name.");
  while (Serial.available() == 0) {
  }
  String  inputString = Serial.readString();
  return inputString;
}

int readInteger() {
  clearSerialBuffer();
  Serial.println("Enter your int value.");
  while (Serial.available() == 0) {
    ;
  }
  String  input = Serial.readString();
  return input.toInt();
}

void clearSerialBuffer() {

  while (Serial.available() > 0) {
    Serial.read();
    Serial.flush();
  }
}
