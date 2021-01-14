### offical website 
- https://www.arduino.cc/

### document 
- https://www.arduino.cc/reference/en/

---
# Basic Code 
```
void setup(){
//   one time activity executed only once 
}


void loop() {
//   repeated time activity executed repeatedly  
}


#to output to the usb port 
Serial.begin(9600); 

#to Print on the usb 
Serial.print("Time:");
```

---

## Data Type 
---

### void 
- boolean =>
  - (true , false)

- char => 

- unsigned char => (occupies one byte of memory)

- byte =>
  - (8-bit unsigned number, from 0 to 255)

- int => 
  - (stores a 16-bit (2-byte) -32,768 to 32,767 )

- Unsigned int =>
  - ( store a 2 byte value, 0 to 4,294,967,295)

- word =>
  - (On Uno and ATMEGA it stores a 16-bit unsigned number, On Due and Zero stores a 32-bit unsigned number)

- Long=>
  - (32 bits (4 bytes), from -2,147,483,648 to 2,147,483,647)

- Unsigned Long=>
  - (32 bits (4 bytes). unsigned longs will not store negative numbers, making their range from 0 to 4,294,967,295)

- short => 
  - (On all Arduinos (ATMega and ARM based), a short stores a 16-bit (2-byte) range of -32,768 to 32,767) 

- float=>
  - 3.4028235E+38 and as low as -3.4028235E+38. They are stored as 32 bits (4 bytes)

- double=>
  - same as the float, with no gain in precision
  - Uno and other ATMEGA based boards, Double precision floating-point number occupies four bytes
  - On the Arduino Due, doubles have 8-byte (64 bit) precision

---

## Variable Type 
---
### @ Inside a function or a block, which is called local variables.
### @ In the definition of function parameters, which is called formal parameters.
### @ Outside of all functions, which is called global variables.

```

dataType variableName ; Global variable declaration
void setup () {

}

void loop () {
   dataType variableName ; Local variable declaration
}

int functionName(dataType variableName){ //formal parameter 

  return 0;
} 

```


---

## Enums 
---

### Declaration
```
enum State {
  ON,
  OFF
};
```
### Usage 
```
 State button = State.ON;

  switch (button) {

  case ON:
       [do something...]
    break;
  case OFF;
       [do something else...]
    break;

 }

```


---

## USEFULS 
---

### to include the other lib files 
```
#include <Servo.h>
```
### to define the name constant 
```
#define constantName value
```

### goto statment 
```
label labelName;
goto labelName;
```


---

## Loops
---

### While loop 
```
while(expression) {
   Block of statements;
}
```

### do while loop 
```
do { 
   Block of statements; 
} 
while (expression);
```
### for loop 
```
for ( initialize; control; increment or decrement) {
   // statement block
}
```

### loop nesting 
```
for ( initialize ;control; increment or decrement) {
   // statement block
   for ( initialize ;control; increment or decrement) {
      // statement block
   }
}
```

### infinite loop
- Using for loop
```
for (;;) {
   // statement block
}
```

- Using while loop
```
while(1) {
   // statement block
}
```

- Using do…while loop
```
do {
   Block of statements;
} 
while(1);
```

---
## Conditions
---

### if statement 
```
if (expression) {
   Block of statements;
}
```

### if else statement 
```
if (expression) {
   Block of statements;
}
else {
   Block of statements;
}
```

### if else if statement 
```
if (expression_1) {
   Block of statements;
}

else if(expression_2) {
   Block of statements;
}
.
.
.

else {
   Block of statements;
}

```

### switch 
```
switch (variable) { 
   case label:
   // statements
   break;
}

case label: { 
   // statements
   break;
}

default: { 
   // statements
   break;
}
```

### Conditional Operrator 
```
expression1 ? expression2 : expression3
```

---

## Operator
---

### Arithmetic Operators
- assignment operator	=	Stores the value to the right of the equal sign in the variable to the left of the equal sign.	A = B
- addition	+	Adds two operands	A + B will give 30
- subtraction	-	Subtracts second operand from the first	A - B will give -10
- multiplication	*	Multiply both operands	A * B will give 200
- division	/	Divide numerator by denominator	B / A will give 2
- modulo	%	Modulus Operator and remainder of after an integer division	B % A will give 0



### Comparison Operators
- equal to	==	Checks if the value of two operands is equal or not, if yes then condition becomes true.	(A == B) is not true
- not equal to	!=	Checks if the value of two operands is equal or not, if values are not equal then condition becomes true.	(A != B) is true
- less than	<	Checks if the value of left operand is less than the value of right operand, if yes then condition becomes true.	(A < B) is true
- greater than	>	Checks if the value of left operand is greater than the value of right operand, if yes then condition becomes true.	(A > B) is not true
- less than or equal to	<=	Checks if the value of left operand is less than or equal to the value of right operand, if yes then condition becomes true.	(A <= B) is true
- greater than or equal to	>=	Checks if the value of left operand is greater than or equal to the value of right operand, if yes then condition becomes true.	(A >= B) is not true

### Boolean Operators
- and	&&	Called Logical AND operator. If both the operands are non-zero then then condition becomes true.	(A && B) is true
- or	||	Called Logical OR Operator. If any of the two operands is non-zero then then condition becomes true.	(A || B) is true
- not	!	Called Logical NOT Operator. Use to reverses the logical state of its operand. If a condition is true then Logical NOT operator will make false.	!(A && B) is false

### Bitwise Operators
- and	&	Binary AND Operator copies a bit to the result if it exists in both operands.	(A & B) will give 12 which is 0000 1100
- or	|	Binary OR Operator copies a bit if it exists in either operand	(A | B) will give 61 which is 0011 1101
- xor	^	Binary XOR Operator copies the bit if it is set in one operand but not both.	(A ^ B) will give 49 which is 0011 0001
- not	~	Binary Ones Complement Operator is unary and has the effect of 'flipping' bits.	(~A ) will give -60 which is 1100 0011
- shift left	<<	Binary Left Shift Operator. The left operands value is moved left by the number of bits specified by the right operand.	A << 2 will give 240 which is 1111 0000
- shift right	>>	Binary Right Shift Operator. The left operands value is moved right by the number of bits specified by the right operand.	A >> 2 will give 15 which is 0000 1111


### Compound Operators
- increment	++	Increment operator, increases integer value by one	A++ will give 11
- decrement	--	Decrement operator, decreases integer value by one	A-- will give 9
- compound addition	+=	Add AND assignment operator. It adds right operand to the left operand and assign the result to left operand	B += A is equivalent to B = B+ A
- compound subtraction	-=	Subtract AND assignment operator. It subtracts right operand from the left operand and assign the result to left operand	B -= A is equivalent to B = B - A
- compound multiplication	*=	Multiply AND assignment operator. It multiplies right operand with the left operand and assign the result to left operand	B*= A is equivalent to B = B* A
- compound division	/=	Divide AND assignment operator. It divides left operand with the right operand and assign the result to left operand	B /= A is equivalent to B = B / A
- compound modulo	%=	Modulus AND assignment operator. It takes modulus using two operands and assign the result to left operand	B %= A is equivalent to B = B % A
- compound bitwise or	|=	bitwise inclusive OR and assignment operator	A |= 2 is same as A = A | 2
- compound bitwise and	&=	Bitwise AND assignment operator	A &= 2 is same as A = A & 2


----

## Functions
---

### function Declaration 
```
returnType functionName(dataType argName ....... ){

       //statements.....
       
  returnValue;
}
```

### Function call
   
```
   dataType varName = functionName(argumentValue ..... );
```

---
   
### EXAMPLE 1

```
int sumFunction (int x, int y) // function declaration {
   return x+y; // return the value
}

void setup () {
   Statements // group of statements
}

void loop () {
   int result = sumFunction (5,6) ; // function call
}
   
```

---

### EXAMPLE 2
```
int sumFunction (int x, int y);  // function prototype

void setup () {
   Statements // group of statements
}

void loop () {
   int result = sumFunction (5,6) ; // function call
}

int sumFunction (int x, int y) // function declaration {
   return x+y; // return the value
}

```

---
## Arrays
---

- dataType arrayName [ arraySize ] ;

- dataType arrayName[ arraySize ] = { dataTypeLiteranlValues ......... } ;


---
## String 
---
 - String stringVariableName = "STRING LITRALS";
 
 - .toUpperCase()
 - .length()
 - .replace()


---
## Time 
---
- delay (ms) ; //delay by argumented milliseconds
- delayMicroseconds (us) ; // delay by argumented microseconds
- millis () ; // return current milliseconds
- micros () ; // return current  microseconds

---
## I/O Functions
---
- Pins Configured as INPUT
  -pinMode(pinNumber,INPUT)
- Pins Configured as OUTPUT
  - pinMode(pinNumber,OUTPUT)
- digitalWrite() Function
  - digitalWrite (pinNumber ,value);   
  - value − HIGH, or LOW.
- analogRead( ) function
  - int var = analogRead(pinNumber);     

---
### SAMPLES 
----
```
void setup() {
  Serial.begin(9600);
}


void loop() {
   char input = readByteData();
   String  inputString= readString();
   int input = readInteger();
}

char readByteData(){
  char byteInput = 0;
  
  if (Serial.available() > 0) {    
     byteInput = Serial.read();    
  
    // check if a number was received
    if ((byteInput >= '0')) {
      Serial.print("Number received: ");
      Serial.println(byteInput);
    } else {
      Serial.println("Not a number.");
    }
  }    
  return byteInput;
}

String readString(){

  Serial.println("Enter your name.");     
  while (Serial.available()==0){    
  }  
  String  inputString = Serial.readString(); 

  return inputString;
}

int readInteger(){
 Serial.println("Enter your int value.");     
  while (Serial.available()==0){    
  }  
  String  input = Serial.readString(); 
  return input.toInt()
}

```

---
## CHAR FUNCTIONS  
---
- 	int isdigit( int c )
  - Returns 1 if c is a digit and 0 otherwise.

- int isalpha( int c )
  - Returns 1 if c is a letter and 0 otherwise.

- int isalnum( int c )
  - Returns 1 if c is a digit or a letter and 0 otherwise.

- int isxdigit( int c )
  - Returns 1 if c is a hexadecimal digit character and 0 otherwise.
  - (See Appendix D, Number Systems, for a detailed explanation of binary, octal, decimal and hexadecimal numbers.)

- int islower( int c )
  - Returns 1 if c is a lowercase letter and 0 otherwise.

- int isupper( int c )
  - Returns 1 if c is an uppercase letter; 0 otherwise.

- int isspace( int c )
  - Returns 1 if c is a white-space character—newline ('\n'), space
  - (' '), form feed ('\f'), carriage return ('\r'), horizontal tab ('\t'), or vertical tab ('\v')—and 0 otherwise.

- int iscntrl( int c )
  - Returns 1 if c is a control character, such as newline ('\n'), form feed ('\f'), carriage return ('\r'), horizontal tab ('\t'), vertical tab ('\v'), alert ('\a'), or backspace ('\b')—and 0 otherwise.

- int ispunct( int c )
  - Returns 1 if c is a printing character other than a space, a digit, or a letter and 0 otherwise.

- int isprint( int c )
  - Returns 1 if c is a printing character including space (' ') and 0 otherwise.

- int isgraph( int c )
  - Returns 1 if c is a printing character other than space (' ') and 0 otherwise.


---
## Pointer Access Operators 
---
- dataType *pointerVariableName;
```
int *agePointer;
int age = 58; 
agePointer = &age;
```
