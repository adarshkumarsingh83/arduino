# SUART NODEMCU MASTER MEGA SLAVE SERAIL BI-DIRECTIONAL COMMUNICATION 

----

# connections 

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/suart-nodemcu-mega/image/espMega-1x.png)

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/suart-nodemcu-mega/image/connections.JPG)

```
# Pin in nodemcu 
 D2 = SRX,
 D1 = STX

 # Pin in mega
 18 = TX1
 19 = RX1

 connect the Nodemcu D1 to the mega 19 pin 
 connect the Nodemcu D2 to the mega 18 pin 
 connect the gnd from nodemcu to the mega gnd 

 connect the pin 7 from mega to the bredboard and folowed by resistor then long leg of the led 
 connect the gnd from mega to the common gnd of the bredbaord then connect the short leg of led to the common gnd 

connect the pin D0 from nodemcu to the bredboard and folowed by resistor then long leg of the led 
connect the gnd from nodemcu to the common gnd of the bredbaord then connect the short leg of led to the common gnd 

```

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/suart-nodemcu-mega/image/serial-monitor.png)