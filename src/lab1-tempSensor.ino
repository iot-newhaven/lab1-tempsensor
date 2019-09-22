/*
 * Project lab1-tempSensor
 * Description:
 * Author:
 * Date:
 */

SYSTEM_MODE(SEMI_AUTOMATIC);

#include <adxl362.h>

ADXL362 sensor;

int16_t temp;

int16_t XValue, YValue, ZValue, Temperature;

// setup() runs once, when the device is first turned on.
void setup()
{
    // Put initialization like pinMode and begin functions here.

    Serial.begin(115200);

    sensor.begin(SS); // Setup SPI protocol, issue device soft reset

    sensor.beginMeasure(); // Switch ADXL362 to measure mode

    Serial.println("Lab1: temp sensor");
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
    // The core of your code will likely live here.
    
    // Read Sensor Data 
    getRawSensorData();

    // Display to Serial Monitor
    displayRawSensorData();
}

void getRawSensorData(void)
{
    // read all three axis in burst to ensure all measurements correspond to same sample time
    sensor.readXYZTData(XValue, YValue, ZValue, Temperature);
}

void displayRawSensorData(void)
{
    Serial.print("XVALUE=");
    Serial.print(XValue);
    
    Serial.print("\tYVALUE=");
    Serial.print(YValue);
    
    Serial.print("\tZVALUE=");
    Serial.print(ZValue);
    
    Serial.print("\tTEMPERATURE=");
    Serial.println(Temperature);

    delay(100);
}
