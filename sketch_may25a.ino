#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting...");
  
  if (!bme.begin(0x76)) {
    if (!bme.begin(0x77)) {
      Serial.println("BME280 not found! Check wiring.");
      while (1);
    }
  }
  Serial.println("BME280 found!");
}

void loop() {
  Serial.print("Temperature: ");
  Serial.print(bme.readTemperature() * 9/5 + 32);
  Serial.println(" F");
  
  Serial.print("Humidity: ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");
  
  Serial.print("Pressure: ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");
  
  Serial.println("---");
  delay(2000);
}
