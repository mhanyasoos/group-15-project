/* 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float mCPtemp;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include <Adafruit_MCP9808.h>
#include <Wire.h>

#define SDA_PIN 6
#define SCL_PIN 7

Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();  // Declare sensor

void setup() {
  Serial.begin(115200);
  delay(2000);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  // Start I2C
  Wire.begin(SDA_PIN, SCL_PIN);

  // Start sensor
  if (!tempsensor.begin(0x18)) {
    Serial.println("Couldn't find MCP9808! Check wiring.");
    while (1);
  }

  Serial.println("MCP9808 Found!");
}

void loop() {
  ArduinoCloud.update();

  // Read temperature into cloud variable
  mCPtemp = tempsensor.readTempC();

  Serial.print("Temperature: ");
  Serial.print(mCPtemp);
  Serial.println(" Â°C");

  delay(5000);
}
