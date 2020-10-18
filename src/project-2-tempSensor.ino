/*
 * Project project-2-tempSensor
 * Description:
 * Author:
 * Date:
 */

SYSTEM_MODE(SEMI_AUTOMATIC);

#include <adxl362.h>

ADXL362 sensor;

int16_t x_value, y_value, z_value, raw_temperature;

int spi_cs_pin = D5;

// setup() runs once, when the device is first turned on.
void setup()
{
    // Put initialization like pinMode and begin functions here.

    Serial.begin(115200);

    sensor.begin(spi_cs_pin); // Setup SPI protocol, issue device soft reset

    sensor.beginMeasure(); // Switch ADXL362 to measure mode

    Serial.println("Project 2: Temperature sensor");
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
    // The core of your code will likely live here.
    
    // Read Sensor Data 
    getRawSensorData();

    // Display to Serial Monitor
    //displayRawSensorData();

    displaySensorTemp(readSensorTempC());
}

void getRawSensorData(void)
{
    // read all three axis in burst to ensure all measurements correspond to same sample time
    sensor.readXYZTData(x_value, y_value, z_value, raw_temperature);
}

void displayRawSensorData(void)
{
    Serial.print("XVALUE=");
    Serial.print(x_value);
    
    Serial.print("\tYVALUE=");
    Serial.print(y_value);
    
    Serial.print("\tZVALUE=");
    Serial.print(z_value);
    
    Serial.print("\tTEMPERATURE=");
    Serial.println(raw_temperature);

    delay(1000);
}

float readSensorTempC(void)
{
    float temperature_C;
    
    temperature_C = (float)raw_temperature * 0.065;

    return temperature_C;
}

void displaySensorTemp(float temperature_C)
{
    static char messageBuffer[255];

    snprintf(messageBuffer, sizeof(messageBuffer), "Temperature %f C\n", temperature_C);

    Serial.print(messageBuffer);

    delay(1000);
}
