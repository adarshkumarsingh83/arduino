# SPI UNO MASTER AND ARDUINO MEGA SLAVE BI-DIRECTION COMMUNICATION 

---

## connectionss 

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-uno-master-mega-slave-string-bidirection-communication/image/connections.JPG)


![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-uno-master-mega-slave-string-bidirection-communication/image/spi-mega-arduino-uno-connections.png)

```
connect pin 13 of  uno to the pin 52 of MEGA
connect pin 12 of  uno to the pin 50 of MEGA
connect pin 11 of  uno to the pin 51 of MEGA
connect pin 10 of  uno to the pin 53 of MEGA
connect the gnd of uno to the gnd of the MEGA

then connect the gnd from uno the common breadboard gnd line 
connect the pin 7 from uno to the breadboard 
then connect the resistor to the pin 7 connect in breadboard 
then connect the long leg of the led to the resistor 
then connect the short leg of the led to the breadboard gnd line 


connect the D1/gpio 5 pin from MEGA to the breadbboard 
then connect the resitor to the D1/gpio 5 pin in breadboard 
then connect the long leg of the led to the resistor 
then connect the short leg of the led to the breadboard gnd line 
```


### To Open Two arduino sperate ide on mac
* $ open -n -a Arduino
	* -n = open new instance even when one is already running
	* -a xxx = open application xxx

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-uno-master-mega-slave-string-bidirection-communication/image/serial-monitors.png)