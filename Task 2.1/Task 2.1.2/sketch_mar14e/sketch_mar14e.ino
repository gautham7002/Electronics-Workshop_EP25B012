#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ssid";
const char* password = "password";

WebServer server(80);

const int ledPin = 2;  


String webpage = "<!DOCTYPE html><html>\
<head><title>ESP32 LED Control</title></head>\
<body style='text-align:center;'>\
<h1>ESP32 Web Server</h1>\
<p><a href='/on'><button style='font-size:20px'>ON</button></a></p>\
<p><a href='/off'><button style='font-size:20px'>OFF</button></a></p>\
</body></html>";


void handleRoot() {
  server.send(200, "text/html", webpage);
}


void handleOn() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/html", webpage);
}


void handleOff() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/html", webpage);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

 
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();
}