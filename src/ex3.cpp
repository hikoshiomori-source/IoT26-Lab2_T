

#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

#define HIGH_THRESHOLD 3000
#define LOW_THRESHOLD  2500

bool alertActive = false;


/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
}


/****************************************************/
void loop(void) 
{
    int lightValue = analogRead(LIGHT_SENSOR_PIN);

    if (lightValue > HIGH_THRESHOLD && alertActive == false) 
    {
        alertActive = true;
        Serial.println("ALERT=1");
    }
    else if (lightValue < LOW_THRESHOLD && alertActive == true) 
    {
        alertActive = false;
        Serial.println("ALERT=0");
    }

    delay(300);
}
