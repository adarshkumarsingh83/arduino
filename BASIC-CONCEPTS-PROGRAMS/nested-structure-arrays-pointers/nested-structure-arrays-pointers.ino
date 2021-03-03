

typedef struct {
  char _type[20];
} MessageType;

typedef struct  {
  char data[20];
  MessageType msgType;
} Message;

Message * messagePointer;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(2000);

  messagePointer = getMessages();
  displayMessage(messagePointer);
  displayMessageViaPointer(messagePointer);
}

void displayMessage( Message message[]) {
  Serial.println("Structur array ");
  for (int i = 0; i < 10; i++) {
    Serial.print(" Text: ");
    Serial.print((message[i]).data);
    Serial.print(", Type: ");
    Serial.println((message[i]).msgType._type);
  }
}

void displayMessageViaPointer( Message *message) {
  Serial.println("Structur pointer");
  for (int i = 0; i < 10; i++) {
    Serial.print(" Text: ");
    Serial.print(message[i].data);
    Serial.print(", Type: ");
    Serial.println(message[i].msgType._type);
  }
}

Message* getMessages() {
  Message * messageArray = new Message[10];
  for (int i = 0; i < 10; i++) {
    
    if (i % 2 == 0) {
      strcpy(messageArray[i].data, "welcome to espark");
      strcpy(messageArray[i].msgType._type, "normal");
    } else {
      strcpy(messageArray[i].data, "save the world");
      strcpy(messageArray[i].msgType._type, "urgent");
    }
  }
  return messageArray;
}
