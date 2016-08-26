/* Barometer Click Demo
 *  
 * Read the pressure and temperature.
 * 
 * The click defaults to address 1. If you want to change to address 0
 * you will need to provice the new address (0x5C) to the baro.begin()
 * function below as "baro.begin(0x5C);".
 */

#include <Wire.h>
#include <BarometerClick.h>

BarometerClick baro;

void setup() {
    Serial.begin(115200);
    baro.begin();
}

void loop() {
    Serial.printf("Pressure: %6.2f hPa, Temperature: %6.2f C\r\n", 
        baro.readPressure(), baro.readTemperature());
    delay(1000);
}
