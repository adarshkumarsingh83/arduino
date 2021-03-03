
void changeFormat(int* data);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(3000);
  int dataValue = 100;
  Serial.println();
  Serial.print("INSIDE LOOP BEFORE METHOD CALL ");
  Serial.println(dataValue);
  changeFormat(&dataValue);
  Serial.print("INSIDE LOOP AFTER METHOD CALL ");
  Serial.println(dataValue);
}


void changeFormat(int* dataValue) {
  Serial.print("INSIDE METHOD ");
  *dataValue = *dataValue + 100;
  Serial.println(*dataValue);
}
