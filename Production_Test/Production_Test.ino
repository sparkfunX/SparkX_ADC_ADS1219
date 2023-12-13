/*
  Production test for the ADS1219 ADC.

  This is the code we use at SparkFun to test the Qwiic ADS1219.

  By: Paul Clark
  SparkFun Electronics
  Date: 2023/12/11
  SparkFun code, firmware, and software is released under the MIT License.
  Please see LICENSE.md for further details.

  Hardware Connections:
  IoT RedBoard --> ADS1219
  QWIIC        --> QWIIC

  Open the serial monitor at 115200 baud to see the test results.

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/23455 - Qwiic ADS1219 1x1
*/

// You will need the SparkFun Toolkit. Click here to get it: http://librarymanager/All#SparkFun_Toolkit

#include <SparkFun_ADS1219.h> // Click here to get the library: http://librarymanager/All#SparkFun_ADS1219

SfeADS1219ArdI2C myADC;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  delay(1000); // Allow time for the microcontroller to start up

  Serial.begin(115200); // Begin the Serial console
  while (!Serial)
  {
    delay(100); // Wait for the user to open the Serial Monitor
  };
  Serial.println("SparkFun ADS1219 Production Test");
}

void loop()
{
  delay(250); // Try every 0.25 seconds

  Wire.begin();

  Wire.beginTransmission(0x40); // Detect ADS1219 on address 0x40
  if (Wire.endTransmission() != 0)
  {
    digitalWrite(LED_BUILTIN, LOW);
    Wire.end();
    Serial.println(F("Error: nothing detected on address 0x40"));
    return;
  }
  
  if (myADC.begin() == false) // Initialize ADC
  {
    digitalWrite(LED_BUILTIN, LOW);
    Wire.end();
    Serial.println(F("Error: .begin failed"));
    return;
  }

  myADC.setInputMultiplexer(ADS1219_CONFIG_MUX_SHORTED); // Read the voltage with AINP and AINN shorted to AVDD / 2

  for (int samples = 0; samples < 5; samples++) // Read the voltage 5 times to avoid any start-up noise
  {
    myADC.startSync(); // Start a single-shot conversion.

    int tries = 0;
    while ((myADC.dataReady() == false) && (tries < 25)) // Check if the conversion is complete.
    {
      delay(10); // The conversion is not complete. Wait a little to avoid pounding the I2C bus.
      tries++;
    }
  
    if (tries >= 25) // Check if we got data ready
    {
      digitalWrite(LED_BUILTIN, LOW);
      Wire.end();
      Serial.println(F("Error: no DRDY"));
      return;
    }

    if (!myADC.readConversion()) // Read the conversion result from the ADC. Store it internally.
    {
      digitalWrite(LED_BUILTIN, LOW);
      Wire.end();
      Serial.println(F("Error: readConversion failed"));
      return;
    }
  }

  int32_t sample = myADC.getConversionRaw(); // Get the raw ADC value. Note: this is NOT adjusted for gain.

  if (sample > 100)
  {
    digitalWrite(LED_BUILTIN, LOW);
    Wire.end();
    Serial.print(F("Error: ADC voltage too high: "));
    Serial.println(sample);
    return;
  }

  if (sample < -100)
  {
    digitalWrite(LED_BUILTIN, LOW);
    Wire.end();
    Serial.print(F("Error: ADC voltage too low: "));
    Serial.println(sample);
    return;
  }

  // All good!
  digitalWrite(LED_BUILTIN, HIGH);
  Wire.end();
  Serial.println(F("ADS1219 detected! Test passed! Check the PWR LED is on"));
}
