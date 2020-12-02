/***
 * 
 * Sensor will take time to read data and to show on console 
 * 
 */

#include <dht11.h>

dht11 DHT11;
#define DHT11PIN 2
void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {

  int status = DHT11.read(DHT11PIN);
  
  Serial.println(status);
  
  if (status == DHTLIB_OK) {
    Serial.println();
    Serial.print("Humidity:");// Print a message of "Humidity: 
    Serial.print((float)DHT11.humidity, 2);// Print a message of "Humidity: 
    Serial.print(" % "); // Print the unit of the centigrade temperature 
    Serial.println();

    Serial.print("Temp:    ");// Print a message of "Temp: 
    Serial.print((float)DHT11.temperature, 2);// Print a centigrade temperature 
    Serial.print(" C "); // Print the unit of the centigrade temperature 

  } else {
    Serial.println("Error in Reading Data From Sensor");
  }
  delay(1000);
}
