

double list[5] = {1000.0, 2000.0, 30000.0, 4000.0, 5000.0};
int listSize = sizeof(list) / sizeof(double);
double *pointerToList;

void setup() {
  Serial.begin(9600);
  pointerToList = list;
}

void loop() {
  delay(3000);

  Serial.println("List values using pointer ::=> *(pointerToList + i)");
  for ( int i = 0; i < listSize; i++ ) {
    Serial.print(*(pointerToList + i));
    Serial.print(" ");
  }
  Serial.println(" ");

  Serial.println("List values using pointer ::=>  pointerToList[i]");
  for ( int i = 0; i < listSize; i++ ) {
    Serial.print( pointerToList[i]);
    Serial.print(" ");
  }
  Serial.println(" ");

  Serial.println("List values using list as address ::=> *(list + i)");
  for ( int i = 0; i < listSize; i++ ) {
    Serial.print(*(list + i));
    Serial.print(" ");
  }
  Serial.println(" ");
}
