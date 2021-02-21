# PCF8574 COMMON ANNON LED TEST 

---

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/pcf8574-common-annod-led/connection.JPG)

### Connections

```
connect sda and scl from arduino to the pcf8574 sda and scl pin 
take +5v and gnd from arduino to the pcf8574 vcc and gnd pin 
from pcf8574 board pin p0 to p5 connect to the breadboard 6 resistors 
connect the 2 connom annod leds to the resistos short led 
log leg of the led will connect to the positive +ve of the breadboard 
take pcf8574 other end vcc and connect to the breadboard +ve 

# led pin sequence 
       p0 green_1
       p1 yellow_1
       p2 red_1
       p3 green_1
       p4 yellow_1
       p5 red_1
```