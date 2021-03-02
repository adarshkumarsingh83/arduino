#include "Father.h"
#include "Mother.h"
#include "Child.h"

GrandParent parent;
Father father;
Mother mother;
Child child;

void setup() {
  Serial.begin(9600);

  parent = GrandParent("Grand Singh");
  parent.setGrandParentProperty("gold ");

  father = Father("Father Singh", parent);
  father.setGrandParentProperty("gold ");

  mother = Mother("Mother Singh", parent);
  mother.setGrandParentProperty("gold ");

  child = Child("Child Singh", father, mother, parent);

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
