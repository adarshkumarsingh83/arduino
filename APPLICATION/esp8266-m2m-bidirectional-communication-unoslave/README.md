# ESP8266 Internal Communication 

---- 
![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/esp8266-m2m-bidirectional-communication-unoslave/image/ESP8266-pin%20digram.png)

## Connection

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/esp8266-m2m-bidirectional-communication-unoslave/image/conection.JPG)


```
connect the gnd and 3.3v from 1st uno to 1st esp8266 to the gnd and 3.3v
connect the pin D1 with breadboard resisotor for green led and gnd 
then connect the pin 5  to the resisotor on the 1st breadboard from 1uno 
then connect the red1 led long leg to the resitor and short leg to the common gnd of the 1st breadboard 
then connect the pin 4 to the resisotor on the 1st breadboard from 1uno 
then connect the red2 led long leg to the resitor and short leg to the common gnd of the 1st breadboard 
then connect the pin RX pin of uno to the TX pin of the 1st esp8266
then connect the pin TX pin of uno to the RX pin of the 1st esp8266
then connect the gnd from 1uno to the 1st breadboard 


connect the gnd and 3.3v from 1st uno to 2nd esp8266 to the gnd and 3.3v
connect the pin D1 with breadboard resisotor for green led and gnd 
then connect the pin 5  to the resisotor on the 2nd breadboard from 2nd uno 
then connect the red1 led long leg to the resitor and short leg to the common gnd of the 2nd breadboard 
then connect the pin 4 to the resisotor on the 2nd breadboard from 2nd uno 
then connect the red2 led long leg to the resitor and short leg to the common gnd of the 2nd breadboard 
then connect the pin RX pin of uno to the TX pin of the 2nd esp8266
then connect the pin TX pin of uno to the RX pin of the 2nd esp8266
then connect the gnd from 2nd uno to the 2nd breadboard 


connect the gnd and 3.3v from 1st uno to 2nd esp8266 to the gnd and 3.3v
connect the pin D1 with breadboard resisotor for green led and gnd 
then connect the pin 5  to the resisotor on the 3rd breadboard from 3rd uno 
then connect the red1 led long leg to the resitor and short leg to the common gnd of the 3rd breadboard 
then connect the pin 4 to the resisotor on the 3rd breadboard from 3rd uno 
then connect the red2 led long leg to the resitor and short leg to the common gnd of the 3rd breadboard 
then connect the pin RX pin of uno to the TX pin of the 3rd esp8266
then connect the pin TX pin of uno to the RX pin of the 3rd esp8266
then connect the gnd from 3rd uno to the 3rd breadboard 


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

