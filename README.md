# lab1-tempSensor

## Task 1

Connect your Particle Argon board to the ADXL362 accesory board

## Task 2

After cloning project https://github.com/iot-newhaven/lab1-tempsensor.git compile local application and flash local to the board.

## Task 2b

Add the following functions to `lab1-tempSensor.ino` file

```c
float readSensorTempC(void)
{
    unsigned char rawTempData[2] = {0, 0};
    short         signedTemp = 0;
    float         tempCelsius = 0;

    rawTempData[0] = (char)Temperature;

    rawTempData[1] = (char)(Temperature >> 8);
    
    signedTemp = (short)(rawTempData[1] << 8) + rawTempData[0];
    
    tempCelsius = (float)signedTemp * 0.065;

    return tempCelsius;
}

void displaySensorTemp(float tempCelsius)
{
    static char messageBuffer[255];

    snprintf(messageBuffer, sizeof(messageBuffer), "Temperature %f C\n", tempCelsius);

    Serial.print(messageBuffer);

    delay(1000);
}
```

Modify your `loop()` function as shown below

```c
void loop()
{
    // The core of your code will likely live here.
    
    // Read Sensor Data 
    getRawSensorData();

    // Display to Serial Monitor
    //displayRawSensorData();

    displaySensorTemp(readSensorTempC());
    
}
```


