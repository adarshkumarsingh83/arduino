# SPI ARDUINO UNO MASTER SLAVE BI-DIRECTION COMMUNICATION 

---

## connectionss 

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-arduino-uno-to-arduino-master-slave/image/connections.JPG)


![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-arduino-uno-to-arduino-master-slave/image/spi-arduino-uno-connections.jpg)

```
connect pin 13 of 1st uno to the pin 13 of 2nd uno 
connect pin 12 of 1st uno to the pin 12 of 2nd uno 
connect pin 13 of 1st uno to the pin 11 of 2nd uno 
connect pin 10 of 1st uno to the pin 10 of 2nd uno 

connect the pin 7 of 1st uno to breadboard 
conect the gnd of 1st uno to common gnd of hte breadboard 
connect the ristor to the pin 7 on  the breadboard 
conect the other leg of resigot ot the long leg of led 
connect the other short leg of the led ot the common gnd 


connect the pin 7 of 2nd uno to breadboard 
conect the gnd of 2nd uno to common gnd of hte breadboard 
connect the ristor to the pin 7 on  the breadboard 
conect the other leg of resigot ot the long leg of led 
connect the other short leg of the led ot the common gnd 


NOTE:: if single breadboard then both uno gnd to the same coommon gnd line 
other wise connect the gnd from 1st uno to the gnd of the 2nd uno direct for common gnd line 
```


### To Open Two arduino sperate ide on mac
* $ open -n -a Arduino
	* -n = open new instance even when one is already running
	* -a xxx = open application xxx

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-arduino-uno-to-arduino-master-slave/image/serial-monitors.png)