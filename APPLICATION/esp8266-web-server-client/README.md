# Esp8266 web server and client example 

---


### below lib are in lib directory of poc 
- ESPAsyncWebServer
- ESPAsync TCP
- Adding lib into Arduino IDE 
	- Arduino IDE -> Sketch > Include Library > Add .ZIP library


### Connection 
```
connect gnd from Esp8266 to the breadboard common gnd 
then take a connection from D0 to the breadboard 
then connect the long leg of led to the D0 connection on breadboard 
then connect the short leg of the led to the common Gnd of the breadboard 

# SERVER NODE
	start the server first 
	look for the ip address in the wifi router entries 
	then test the endpoints by hitting 

FOR LED ON 
	http://192.168.0.141/led-on
FOR LED OFF 
	http://192.168.0.141/led-off

# CLIENT NODE 
	take the server ip address and change the ip address in the client stetch in serverLedOn and serverLedOff variable 
```