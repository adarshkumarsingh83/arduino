
const float pieValue = 3.14159265;
float sinValue;
float cosValue;
float counter;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (counter = 0; counter <= 2 * pieValue; counter = counter + .01) {
    sinValue = sin(counter);
    cosValue = cos(counter);
    Serial.print(sinValue);
    Serial.print(",");
    Serial.println(cosValue);
  }
}
