#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "DHT.h"

#define DHTPIN 5
#define DHTTYPE DHT11

MDNSResponder mdns;

const char* ssid = "Huang Family Network";
const char* password = "SJHH#100";

ESP8266WebServer server(80);
String webpage = "";
DHT dht(DHTPIN, DHTTYPE);

void setup(void) {
  // put your setup code here, to run once:
  dht.begin();
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  server.on("/read", [](){
    float t = dht.readTemperature();
    char result[14] = "";
    dtostrf(t, 0, 1, result);
    webpage = "Temperature: ";
    webpage += result;
    webpage += " degrees Celcius";
    server.send(200, "text/html", webpage);
    delay(1);
  });
  server.begin();
  Serial.println("HTTP Server started. ");
  
}

void loop(void) {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
