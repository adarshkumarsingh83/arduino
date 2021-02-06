# PCF8574 INTRRUPT EXAMPLE 

---

## CONNECTION 
![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/pcf8574-ir-intrrupt-example/connection-details.JPG)
```
sda scl from arduino to the pcf8574 board sda and scl 
+5v and gnd from arduino to the breadboard then from that pcf8574 board vcc and gnd
+5v and gnd from breadboard to the 1st and 2nd IR sensor vcc and gnd pins on breadboard 
connect 220Oms 2 risistor to breadboard +5v 
another leg ot the reistor will go to the red and greeen led long leg 
pcf8574 pin p0 to the green led short leg 
pcf8574 pin p1 to the red led short leg 
pcf8574 pin p2 to the breadboard to connect the 1st IR sesnor out pin 
pcf8574 pin p3 to the breadboard to connect the 2nd IR sesnor out pin 
pcf8574 pin Int which will connect the pin 2 on arduino uno for intrrupt singal.
```
