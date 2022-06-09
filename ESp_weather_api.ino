#include <Arduino_JSON.h>

#include <HTTPClient.h>

#include <WiFi.h>
#include <HTTPclient.h>
 
const char* ssid = "Slimshady";
const char* password =  "slimshady";
 
const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=Lisbon,pt&APPID=";
const String key = "1f6d98a0663930d239c26f95a2ead755";
 
void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { 
 
    HTTPClient http;
 
    http.begin(endpoint + key); //Specify the URL
    int httpCode = http.GET();  //Make the request
 
    if (httpCode > 0) { 
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); 
  }
 
  delay(30000);
 
}
