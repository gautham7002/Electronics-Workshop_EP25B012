#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("Humidity Reading:");
  Serial.println(h);
  Serial.println("Temperature Reading:");
  Serial.println(t);
  Serial.println();
}
