

## connections detsils 
![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/esp8266-pcf8574-arduino-uno-mega-leds/connections.JPG)

```
connect the scl and sda line from uno/mega to the 1st pcf8574 sda and scl lines 
connect the +5ve and gnd from  uno/mega to the pcf8574 vcc and sda lines 
connect the 2nd pcf8574 to the 1st pcf8574 and so on till last 8 board 
from the last pcf8574 take vcc line and connect to the breadboard +5v line 
take the p0 to p7 from each pcf8574 to the breadboard 
then connect the resistor to all the p0 to p7 input from each of the pcf8574 boards 
then connect the common annod led short led to the resitors 
and long leg ot the led will be connect to the +ve line of the breadboard 

take nodemcu/esp8266 connect the gnd/-ve from uno/mega to the gnd of the nodemcu/esp8266
take the tx pin of the nodemcu/esp8266 and connect to the rx pin of the arduino 
take the rx pin of the nodemcu/esp8266 and connect to the tx pin of the arduino 
```

### Esp8266 endpoints testing url 

* $ curl "http://192.168.0.185/led-operation?type=led&led=1&state=on"
```
{ 'type': 'led','board':'0','pin':'0','state':'on','status':'on'}
```
* $ curl "http://192.168.0.185/led-operation?type=led&led=1&state=off"
```
{ 'type': 'led','board':'0','pin':'0','state':'on','status':'off'}
```