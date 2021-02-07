# PCF8674 CHAIN WITH IR INTRRUPT 

--- 



* CONNECTION DETAILS 

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/pcf8574-chain-ir-intrrupt-lib-example/connection-details.JPG)

```
sda scl from arduino to the pcf8574 board sda and scl 
+5v and gnd from arduino to the breadboard then from that pcf8574 1st board vcc and gnd
pcf8574 2nd board will be connected to backside ot the pcf8574 1st board 
+5v and gnd from breadboard to the 1st and 2nd IR sensor vcc and gnd pins on breadboard 
connect 220Oms 2 risistor to breadboard +5v line
another leg ot the reistor will go to the red and greeen led long leg 
1st pcf8574 pin p0 to the green led short leg 
1st pcf8574 pin p1 to the red led short leg 
1st pcf8574 pin p6 to the breadboard to connect the 1st IR sesnor out pin 
1st pcf8574 pin p7 to the breadboard to connect the 2nd IR sesnor out pin 
1st pcf8574 pin Int which will connect the breadboard 

2st pcf8574 pin p0 to the green led short leg 
2st pcf8574 pin p1 to the red led short leg 
2st pcf8574 pin p6 to the breadboard to connect the 1st IR sesnor out pin 
2st pcf8574 pin p7 to the breadboard to connect the 2nd IR sesnor out pin 
2st pcf8574 pin Int which will connect the breadboard 

not Int pin from all the board must be connected or align in one column  in breadboard 
now one connection from the same column of the Int pin from bread board to the pin 2 on arduino uno for intrrupt singal.
so that any intrrupt from any pcf8574 in chain have common Int connection which can notify the arduino for Intrrupt 

```