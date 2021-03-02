#include "Father.h"
#include "Mother.h"
#include "Child.h"

Father father;
Mother mother;
Child child;

void setup() {
  Serial.begin(9600);
  father = Father("Father Singh");
  mother = Mother("Mother Singh");

  child = Child("Child Singh", father, mother);
  child.setFatherProperty("house");
  child.setMotherProperty("land");
  child.setChildProperty("car");
}

void loop() {
  delay(3000);
  //father.setFatherProperty("house");
  //father.displayFather();

  //mother.setMotherProperty("land");
  //mother.displayMother();


  child.displayChild();
}
