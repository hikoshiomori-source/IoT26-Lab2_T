

#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

int samples[10];


/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
}


/****************************************************/
void loop(void) 
{
    for (int i = 0; i < 10; i++) 
    {
        samples[i] = analogRead(LIGHT_SENSOR_PIN);
    }

    int minValue = samples[0];
    int maxValue = samples[0];
    long sum = 0;

    for (int i = 0; i < 10; i++) 
    {
        if (samples[i] < minValue) 
        {
            minValue = samples[i];
        }
        if (samples[i] > maxValue) 
        {
            maxValue = samples[i];
        }
        sum = sum + samples[i];
    }

    int average = sum / 10;

    Serial.print("min=");
    Serial.print(minValue);
    Serial.print(" max=");
    Serial.print(maxValue);
    Serial.print(" avg=");
    Serial.println(average);

    delay(1000);
}
