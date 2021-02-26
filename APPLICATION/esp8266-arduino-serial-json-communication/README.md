# ESP8266 Internal Communication With Arduino Uno using ArduinoJson Lib for communication 

---- 
![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/esp8266-arduino-serial-json-communication/image/ESP8266-pin-digram.png)

## Connection

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/esp8266-arduino-serial-json-communication/image/connection.JPG)


```connect the +3.3v and gnd/ -ve to the esp8266 3.3v and gnd pin 
connect the pin D0 of esp8266 to the breadboard then followed by the resistor 
connect the green led long leg to the resistor and other short leg of led to gnd of the esp8266 

connect the tx pin of the esp8266 to the rx pin of the uno 
connect the rx pin of the esp8266 to the tx pin of the uno 


connect the pin 5 from uno the breadboard and then connect the resitor to that in breadboard 
then connect the red led long leg to the other side of the resisot then short leg to the common gnd on breadboard 
connect the pin 4 from uno the breadboard and then connect the resitor to that in breadboard 
then connect the red led long leg to the other side of the resisot then short leg to the common gnd on breadboard 

connect the gnd from arduino uno to the bredboard common gnd line 

```


## To test the ARduino from serial monitor 

* {"type":76,"pin":5,"state":1}  
* {"type":76,"pin":5,"state":1,"opStatus":"ON"}

* {"type":76,"pin":5,"state":0}
* {"type":76,"pin":5,"state":0,"opStatus":"OFF"}

* {"type":76,"pin":4,"state":1}
* {"type":76,"pin":4,"state":1,"opStatus":"ON"}

* {"type":76,"pin":4,"state":0}
* {"type":76,"pin":4,"state":0,"opStatus":"OFF"}