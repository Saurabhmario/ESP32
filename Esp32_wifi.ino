#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

const char* ssid = "Slimshady";
const char* password = "slimshady";
void setup() {
  Serial.begin(115200);
WiFi.begin(ssid, password);
Serial.print("Connecting to wifi");
while (WiFi.status() != WL_CONNECTED){
  Serial.print(".");
  delay(500);
}
Serial.println("\nCoonected to the Wifi");
Serial.print("IP address: ");
Serial.println(WiFi.localIP());
}
void loop() {
  if((WiFi.status() ==WL_CONNECTED)){
    Serial.println("You can try to ping me");
    delay(5000);
  }
  else{
Serial.println("Connection lost");
  }}
