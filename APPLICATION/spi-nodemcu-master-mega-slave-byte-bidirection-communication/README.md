# SPI NODE MCU MASTER AND MEGA SLAVE BI-DIRECTION COMMUNICATION 

---

## connectionss 

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-nodemcu-master-mega-slave-byte-bidirection-communication/image/connections.JPG)

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-nodemcu-master-mega-slave-byte-bidirection-communication/image/ESP8266-pin-digram.png)

  ## PIN FOR COMMUNICATION IN NODE MCU
  ```
  SCK =  D5 GPIO14 (HSCKL)
  MISO = D6 GPIO15 (HMISO)
  MOSI = D7 GPIO16 (HMOSI)
  SS =   D8 /GPIO 17(HCS)
```

 ## PIN FOR COMMUNICATION IN ARDUINO MEGA
 ```
  MISO = 50 or ICSP-1
  MOSI = 51 or ICSP-4
  SCK = 52 or ICSP-3
  SS = 53
```
 ## PIN MAPPING
 ```
  NODE MCU MASTER    MEGA SLAVE
  D5                  52
  D6                  50
  D7                  51
  D8                  53
  GND                 GND
 ```

```
connect pin 52 of  mega to the pin D5 of Node mcu
connect pin 50 of  mega to the pin D6 of Node mcu
connect pin 51 of  mega to the pin D7 of Node mcu
connect pin 53 of  mega to the pin D8 of Node mcu
connect the gnd of  mega to the gnd of the Node mcu 

then connect the gnd from mega the common breadboard gnd line 
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

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/spi-nodemcu-master-mega-slave-byte-bidirection-communication/image/serial-monitors.png)