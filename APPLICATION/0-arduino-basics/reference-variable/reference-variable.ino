
// declare simple variables
String nameVar;
String emailVar;

// declare reference variables
String& nameRefVar = nameVar;
String& emailRefVar = emailVar;

void setup() {
  Serial.begin(9600);
  nameVar = " adarsh kumar";
  emailVar = "adarsh@kumar";
}

void loop() {
  delay(3000);
  Serial.println();
  Serial.println(nameRefVar);
  Serial.println(emailRefVar);
  displayNameAndEmailVaiRefVariableAsMethodParam(nameVar, emailVar);

  Serial.println();
  String& phoneRefVar = getPhoneNumber();
  Serial.println(phoneRefVar);
}

String& getPhoneNumber() {
  static String phone = "+1888888";
  return phone;
}

void displayNameAndEmailVaiRefVariableAsMethodParam(String& nameRefVarParam, String& emailRefVarParam) {
  Serial.println();
  Serial.print(nameRefVarParam);
  Serial.print(" ");
  Serial.println(emailRefVarParam);
}
