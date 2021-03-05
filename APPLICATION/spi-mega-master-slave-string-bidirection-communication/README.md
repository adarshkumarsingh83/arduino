# SPI ARDUINO MEGA MASTER SLAVE BI-DIRECTION COMMUNICATION 

---

## connectionss 

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-mega-master-slave-string-bidirection-communication/image/connections.JPG)


```
connect pin 50 of 1st mega to the pin 50 of 2nd mega 
connect pin 51 of 1st mega to the pin 51 of 2nd mega 
connect pin 52 of 1st mega to the pin 52 of 2nd mega 
connect pin 53 of 1st mega to the pin 53 of 2nd mega 

connect the pin 7 of 1st mega to breadboard 
conect the gnd of 1st mega to common gnd of hte breadboard 
connect the ristor to the pin 7 on  the breadboard 
conect the other leg of resigot ot the long leg of led 
connect the other short leg of the led ot the common gnd 


connect the pin 7 of 2nd mega to breadboard 
conect the gnd of 2nd mega to common gnd of hte breadboard 
connect the ristor to the pin 7 on  the breadboard 
conect the other leg of resigot ot the long leg of led 
connect the other short leg of the led ot the common gnd 


NOTE:: if single breadboard then both mega gnd to the same coommon gnd line 
other wise connect the gnd from 1st mega to the gnd of the 2nd mega direct for common gnd line 
```


### To Open Two arduino sperate ide on mac
* $ open -n -a Arduino
	* -n = open new instance even when one is already running
	* -a xxx = open application xxx

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-mega-master-slave-string-bidirection-communication/image/serial-monitors.png)