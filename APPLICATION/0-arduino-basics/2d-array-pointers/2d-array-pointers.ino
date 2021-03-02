
const int rowSize = 3;
const int colSize = 3;
int array2D[rowSize][colSize];
int * pointer;

void setup() {
  Serial.begin(9600);
  pointer = *array2D;

}

void loop() {
  delay(2000);

  populateData(array2D);
  displayData(array2D);
  Serial.println();
  Serial.println();
  populateData(pointer, rowSize, colSize);
  displayData(pointer, rowSize, colSize);

}

void populateData(int array2D[rowSize][colSize]) {
  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < colSize; j++) {
      array2D[i ][ j] = (i + j);
    }
  }
}

void displayData(int array2D[rowSize][colSize]) {
  Serial.println();
  Serial.println();
  for (int i = 0 ; i < rowSize; i++) {
    for (int j = 0 ; j < colSize; j++) {
      Serial.print(array2D[i][j]);
      Serial.print(", ");
    }
    Serial.println();
  }
}

void displayData(int *array2DPointer, int rowSize, int colSize) {
  Serial.println();
  Serial.println();
  for (int i = 0 ; i < rowSize; i++) {
    for (int j = 0 ; j < colSize; j++) {
      Serial.print(*((array2DPointer + i * colSize) + j));
      Serial.print(", ");
    }
    Serial.println();
  }
}

void populateData(int* array2DPointer, int rowSize, int colSize) {
  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < colSize; j++) {
      // Multiply the current row by the number of columns to
      // get the appropriate offset.
      array2DPointer[i * colSize + j] = (i * j);
    }
  }
}
