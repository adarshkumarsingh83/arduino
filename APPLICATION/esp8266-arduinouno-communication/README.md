

## connections detsils 
![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/esp8266-arduinouno-communication/connections.JPG)

```
connect pin13 and pin 12 from arduino to the 220oms resistors on breadboard 
connect the green led long leg to the pin 12 connection on breadboard 
connect the red led long leg to the pin 13 connection on breadboard 
conect the gnd from arduino to the -ve line of the breadboard where short leg of the led are connected 

take nodemcu/esp8266 connect the gnd/-ve from breadboard to the gnd of the nodemcu/esp8266
take the tx pin of the nodemcu/esp8266 and connect to the rx pin of the arduino 
take the rx pin of the nodemcu/esp8266 and connect to the tx pin of the arduino 
```

### Esp8266 endpoints testing url 

* $ curl "http://192.168.0.185/led-operation?type=led&pin=13&state=on"
```
{ 'type': 'led','pin':'13','state':'on','status':'ON'}
```
* $ curl "http://192.168.0.185/led-operation?type=led&pin=13&state=off"
```
{ 'type': 'led','pin':'13','state':'off','status':'OFF'}
```
* $ curl "http://192.168.0.185/led-operation?type=led&pin=12&state=on"
```
{ 'type': 'led','pin':'12','state':'on','status':'ON'}
```
* $ curl "http://192.168.0.185/led-operation?type=led&pin=12&state=off"
```
{ 'type': 'led','pin':'12','state':'off','status':'OFF'}
```