# ESP8266 Internal Communication 

---- 
![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/esp8266-multinode-bidirectional-communication-espnow-lib/image/ESP8266-pin%20digram.png)

## Connection

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/esp8266-multinode-bidirectional-communication-espnow-lib/image/conection.JPG)


```
connect the gnd from 1st esp8266 to the gnd of the breadboard 1st 
then connect the pin D1 whish is pin 5  to the resisotor on the breadboard
then connect the red1 led long leg to the resitor and short leg to the common gnd of the breadboard 
then connect the pin D2 which is pin 4 to the resisotor on the breadboard 
then connect the red2 led long leg to the resitor and short leg to the common gnd of the breadboard 
then connect the pin RX which is pin 3 to the resisotor on the breadboard 
then connect the green led long leg to the resitor and short leg to the common gnd of the breadboard 

connect the gnd from 2st esp8266 to the gnd of the breadboard 2st 
then connect the pin D1 whish is pin 5  to the resisotor on the breadboard
then connect the red1 led long leg to the resitor and short leg to the common gnd of the breadboard 
then connect the pin D2 which is pin 4 to the resisotor on the breadboard 
then connect the red2 led long leg to the resitor and short leg to the common gnd of the breadboard 
then connect the pin RX which is pin 3 to the resisotor on the breadboard 
then connect the green led long leg to the resitor and short leg to the common gnd of the breadboard 

connect the gnd from 3st esp8266 to the gnd of the breadboard 3st 
then connect the pin D1 whish is pin 5  to the resisotor on the breadboard
then connect the red1 led long leg to the resitor and short leg to the common gnd of the breadboard 
then connect the pin D2 which is pin 4 to the resisotor on the breadboard 
then connect the red2 led long leg to the resitor and short leg to the common gnd of the breadboard 
then connect the pin RX which is pin 3 to the resisotor on the breadboard 
then connect the green led long leg to the resitor and short leg to the common gnd of the breadboard 


```

## Note 
```
# steps
find the mac address of the esp8266 and then change add into the list of mac address in code 
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
prefix with each hex value with 0x and replace with ":" with "," comma 
1devicd  84:0D:8E:85:F8:1D => 0x84,0x0D,0x8E,0x85,0xF8,0x1D
2devicd  84:CC:A8:B1:5B:FB => 0x84,0xCC,0xA8,0xB1,0x5B,0xFB
3devide  84:CC:A8:B1:42:6C  => 0x84,0xCC,0xA8,0xB1,0x42,0x6C


# Process for Mac Address finder 
uploading the mac-address-finder code to esp8266, open the Serial Monitor at a baud rate of 115200. 
Press the on-board RESET or EN button.

```

