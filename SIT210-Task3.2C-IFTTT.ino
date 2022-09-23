#include <WiFiNINA.h>
#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

//please enter your sensitive data in the Secret tab
char ssid[] = "vivo 1901";                // your network SSID (name)
char pass[] = "123456789";                // your network password (use for WPA, or use as key for WEP)

WiFiClient client;

char   HOST_NAME[] = "maker.ifttt.com";
String PATH_NAME   = "/trigger/sunlight_present/with/key/eK9JrzYkkmJeYDci9okp7DJatKmoiOsjJTnTHg3MI02"; // change your EVENT-NAME and YOUR-KEY
String queryString = "?value1=57&value2=25";

String PATH_NAME1   = "/trigger/sunlight_absent/with/key/eK9JrzYkkmJeYDci9okp7DJatKmoiOsjJTnTHg3MI02"; // change your EVENT-NAME and YOUR-KEY

int sunlight_absent = 0;

void setup() {
  WiFi.begin(ssid, pass); // Connecting to Wifi
  
  Serial.begin(9600);
  
  Wire.begin();
  
  lightMeter.begin(); // Initializing the light sensor
  
  while(!Serial);

}

void loop() {
  
  float lux = lightMeter.readLightLevel();

  //Serial.print(lux);
  
  if (lux < 100 && sunlight_absent == 0)
  {
    sunlight_absent = 1;
    send_sunlight_absent();
  }
  else if (lux > 100 && sunlight_absent == 1)
  {
    sunlight_absent = 0;
    send_sunlight_present();
  }
  
}

void send_sunlight_present()
{
  if (client.connect(HOST_NAME, 80)){
    Serial.println("Connected to server");
  }
  else {
    Serial.println("Connection Failed");
  }
  
  client.println("GET " + PATH_NAME + queryString + " HTTP/1.1");
  client.println("Host: " + String(HOST_NAME));
  client.println("Connection: close");
  client.println();
  
  while(client.connected()){
    if (client.available()){
      char c = client.read();
      Serial.print(c);
    }
  }
  
  client.stop();
  Serial.println();
  Serial.println("disconnected");
}

void send_sunlight_absent()
{
  if (client.connect(HOST_NAME, 80)){
    Serial.println("Connected to server");
  }
  else {
    Serial.println("Connection Failed");
  }
  
  client.println("GET " + PATH_NAME1 + queryString + " HTTP/1.1");
  client.println("Host: " + String(HOST_NAME));
  client.println("Connection: close");
  client.println();
  
  while(client.connected()){
    if (client.available()){
      char c = client.read();
      Serial.print(c);
    }
  }
  
  client.stop();
  Serial.println();
  Serial.println("disconnected"); 
}
