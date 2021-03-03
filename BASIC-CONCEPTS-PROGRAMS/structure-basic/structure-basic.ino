
struct Message {
  char data[20];
  char type[20];
};

Message * messagePointer;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(2000);
  
  struct Message message1;
  strcpy(message1.data, "hi welcome ");
  strcpy(message1.type, "normal");
  displayMessage(message1);
  messagePointer = &message1;
  displayMessageViaPointer(messagePointer);
  Serial.println();
  struct Message message2;
  strcpy(message2.data, "hi come fast ");
  strcpy(message2.type, "urgent");
  displayMessage(message2);
  messagePointer = &message2;
  displayMessageViaPointer(messagePointer);
  Serial.println();
}

void displayMessage(struct Message message) {
  Serial.println("Structure object");
  Serial.print(" Text: ");
  Serial.print(message.data);
  Serial.print(", Type: ");
  Serial.println(message.type);
}

void displayMessageViaPointer(struct Message *message) {
  Serial.println("Structur pointer");
  Serial.print(" Text: ");
  Serial.print(message->data);
  Serial.print(", Type: ");
  Serial.println(message->type);
}
