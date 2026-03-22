#include "arduino_secrets.h"
/* 


  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float skin_Temp;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include <Wire.h>

#define SDA_PIN 6
#define SCL_PIN 7
#define MAX30205_ADDR 0x48

unsigned long lastRead = 0;
const unsigned long readInterval = 2000; // 2 seconds

void setup() {
  Serial.begin(115200);
  delay(1500);
  
  // Initialize I2C
  Wire.begin(SDA_PIN, SCL_PIN, 100000);
  delay(100);
  
  // Initialize Arduino IoT Cloud
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
}

void loop() {
  ArduinoCloud.update();
  
  if (millis() - lastRead >= readInterval) {
    lastRead = millis();
    
    // Read temperature and update cloud variable
    skin_Temp = readTemperature();
    
    Serial.print("Temperature: ");
    Serial.println(skin_Temp);
  }
}

float readTemperature() {
  // Request temperature reading
  Wire.beginTransmission(MAX30205_ADDR);
  Wire.write(0x00);
  Wire.endTransmission(false);
  
  // Read 2 bytes
  Wire.requestFrom(MAX30205_ADDR, 2);
  
  if (Wire.available() >= 2) {
    uint8_t msb = Wire.read();
    uint8_t lsb = Wire.read();
    
    // Combine and convert (mask off extended format bits if present)
    uint16_t raw = ((uint16_t)msb << 8) | lsb;
    raw = raw & 0x3FFF;  // Mask off top 2 bits (extended format)
    
    // Convert to Celsius (1 LSB = 0.00390625°C)
    return raw * 0.00390625;
  }
  
  return 0.0;
}