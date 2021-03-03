
int list[5] = {1000, 2000, 30000, 4000, 5000};
int listSize = sizeof(list) / sizeof(int);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(3000);

  Serial.println(" ");
  displayDataViaArrayPointer(list);
  displayDataSizedArray(list);
  displayDataUnSizedArray(list);

  int *pointerToReturnArray  = getList();
  displayDataMethodReturningPointer(pointerToReturnArray);
}

int* getList() {
  //array created with in method is local
  // so static is requested for it to return
  static int list[5] = {10, 20, 30, 40, 50};
  return list;
}

void displayDataMethodReturningPointer(int *pointerToList) {
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
}

void displayDataViaArrayPointer(int *pointerToList) {
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
}


void displayDataSizedArray(int list[5]) {
  Serial.println("List values using list as address ::=> *(list + i)");
  for ( int i = 0; i < listSize; i++ ) {
    Serial.print(*(list + i));
    Serial.print(" ");
  }
  Serial.println(" ");
}


void displayDataUnSizedArray(int list[]) {

  Serial.println("List values using list as address ::=> *(list + i)");
  for ( int i = 0; i < listSize; i++ ) {
    Serial.print(*(list + i));
    Serial.print(" ");
  }
  Serial.println(" ");
}
