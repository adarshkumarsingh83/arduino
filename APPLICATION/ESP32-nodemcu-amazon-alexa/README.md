# ESP8266 

--- 
![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/ESP32-nodemcu-google-assit/ESP8266-pin%20digram.png)

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/ESP32-nodemcu-google-assit/esp8266-pin-digram.png)


## HELP URL 
* https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers/all#drivers-if-you-need-them

## DRIVER URL 
* https://www.silabs.com/documents/public/software/Mac_OSX_VCP_Driver.zip

## Insttallation 
```
for mac use applle usb connector or compatable connector  

 Download the direr for MAC ch340 
 after down and insallation check in the Device Manger the Port for the ESP8266 

 then visit the url https://github.com/esp8266/Arduino
 copy the 
 then in arduino IDE 

Start Arduino and open ->  Preferences window.
Enter Url 
https://arduino.esp8266.com/stable/package_esp8266com_index.json 
into the File > Preferences > Additional Boards Manager URLs field of the Arduino IDE. You can add multiple URLs, separating them with commas.

Open Boards Manager from Tools > Board menu and install esp8266 platform from community version 

then select the Board Manager -> esp8266 board -> NodeMce 1.0 (ESP-12E Module)

then Test from the File -> Example -> ESP8266 -> Blink 

```


# for solving the errror on bigsur mac os 
### https://forum.arduino.cc/index.php?topic=702144.0

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/ESP32-nodemcu-google-assit/esp3266-mac-bigsur-issue-solution.png)

```

1.- Open ~/Library/Arduino15/packages/esp8266/hardware/esp8266/2.7.4/tools/pyserial/serial/tools/list_ports_osx.py
2.- Comment out lines 29 and 30 and append these lines:
   iokit = ctypes.cdll.LoadLibrary('/System/Library/Frameworks/IOKit.framework/IOKit')
   cf = ctypes.cdll.LoadLibrary('/System/Library/Frameworks/CoreFoundation.framework/CoreFoundation')
```

# Code must look like this now 
```
kit = ctypes.cdll.LoadLibrary(ctypes.util.find_library('IOKit'))
#cf = ctypes.cdll.LoadLibrary(ctypes.util.find_library('CoreFoundation'))
iokit = ctypes.cdll.LoadLibrary('/System/Library/Frameworks/IOKit.framework/IOKit')
cf = ctypes.cdll.LoadLibrary('/System/Library/Frameworks/CoreFoundation.framework/CoreFoundation')
```

## Blynk git repo for blynk lib 
- https://github.com/blynkkk/blynk-library/releases
```
We can download the "source code zip" file of the lib from above url and add to the arduino ide 

Arduino IDE -> Sketch -> Include lib -> add zip lib 
```

## Connections 
```
connect the Gnd to the bradboard Gnd from the ESP8266 nodemcu 
connect the red and green led short led to the Gnd of the bredboard 
connect the pin D0 to the red and D1 to the Green long leg of the led 
```

## ESP8266 code must be uploded 
	* provide the "WIFI-NETWORK-NAME", "WIFI-NETWORK-PWD" and "TOKEN-RECIEVED-IN-EMAIL" 
	* wifi must be same as the esp8266 and the blynk app device 
```
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "TOKEN-RECIEVED-IN-EMAIL";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WIFI-NETWORK-NAME";
char pass[] = "WIFI-NETWORK-PWD";

void setup() {
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop() {
  Blynk.run();
}
```

## Blynk App 
```
Download the Blynk app and loging with the google id 
NOTE: google id must be useful for getting the token from Blynk app to configure the ESP8266 
Create aproject provide a name to the project 
then add the 2 button in Blynk app by click on the project 
then provide the name and pin to the button 
for red D0 and for Green D1 pin 
and save them then 
play the button from top corner 
then press the button red and green to test the app 
```


### To configure the Google assit 
- https://ifttt.com/

```
Sign up with the GMAIL which is used in blynk add so that google assit will find the voice directly from mobile 
note in mobile in blynk and in ifttt.com must use the same google account for inter data communicaitons 

once login into the ifttt.com goto create applet 
we have to add "if" and "then" information in applet 

if => add => choose a service => alexa -> say simple phrase -> provide the phrase we want to say 
we have to provide it in 3 different ways then what must be acknoledgement of that then -> create 

then => add => webhook -> make a web request -> then we have to provide the url -> method -> content type -> body -> creation action 

then -> connected the slide button 

@ NOTE WE HAVE TO DO IT FOR ON AND OFF FOR SAME TYPE OF ACTION 


# service url which must be configure in ifttt.com applet 
	http://<IP>/<token-in-email>/update/PIN

# To know the Blynk Server Ip address 
	$ Ping blynk-cloud.com

# for finding pins 
	PIN mapping from ESP8266 with the Ifttt 
	ESP8266  => Web service PIN 
	PIN D0 => D16 
	PIN D1 => D5 
	PIN D2 => D4
	PIN D3 => D0
	PIN D4 => D2
	PIN D5 => D14
	PIN D6 => D12
	PIN D7 => D13
	PIN D8 => D14

FOR ON CMD FOR RED LED 
	URL => http://45.55.96.146/7r4TbcUmOpUcaqibJh7LHl4nbpSebzCT/update/D16
	HTTP METHOD => PUT 
	CONTENT TYPE => application/json 
	BODY => ["1"] 

FOR OFF CMD FOR RED LED 
	URL => http://45.55.96.146/7r4TbcUmOpUcaqibJh7LHl4nbpSebzCT/update/D16
	HTTP METHOD => PUT 
	CONTENT TYPE => application/json 

```