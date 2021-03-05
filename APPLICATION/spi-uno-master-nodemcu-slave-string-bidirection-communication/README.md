# SPI NODE MCU AS MASTER AND ARDUINO UNO SLAVE BI-DIRECTION STRING DATA COMMUNICATION 

---

## connectionss 

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-uno-master-nodemcu-slave-string-bidirection-communication/image/connections.JPG)

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-uno-master-nodemcu-slave-string-bidirection-communication/image/ESP8266-pin-digram.png)

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-uno-master-nodemcu-slave-string-bidirection-communication/image/spi-nodemcu-arduino-uno-connections.png)

```
connect pin 13 of  uno to the pin D5 of Node mcu
connect pin 12 of  uno to the pin D6 of Node mcu
connect pin 13 of  uno to the pin D7 of Node mcu
connect pin 10 of  uno to the pin D8 of Node mcu
connect the gnd of  uno to the gnd of the Node mcu 


then connect the gnd from uno the common breadboard gnd line 
connect the pin 7 from uno to the breadboard 
then connect the resistor to the pin 7 connect in breadboard 
then connect the long leg of the led to the resistor 
then connect the short leg of the led to the breadboard gnd line 


connect the D1/gpio 5 pin from nodemcu to the breadbboard 
then connect the resitor to the D1/gpio 5 pin in breadboard 
then connect the long leg of the led to the resistor 
then connect the short leg of the led to the breadboard gnd line 

```


### To Open Two arduino sperate ide on mac
* $ open -n -a Arduino
	* -n = open new instance even when one is already running
	* -a xxx = open application xxx

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-uno-master-nodemcu-slave-string-bidirection-communication/image/serial-monitors.png)