
typedef struct  {
  char data[20];
  char type[20];
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
    Serial.println((message[i]).type);
  }
}

void displayMessageViaPointer( Message *message) {
  Serial.println("Structur pointer");
  for (int i = 0; i < 10; i++) {
    Serial.print(" Text: ");
    Serial.print(message[i].data);
    Serial.print(", Type: ");
    Serial.println(message[i].type);
  }
}

Message* getMessages() {
  Message * messageArray = new Message[10];
  for (int i = 0; i < 10; i++) {
    strcpy(messageArray[i].data, "welcome to espark");
    strcpy(messageArray[i].type, "normal");
  }
  return messageArray;
}
