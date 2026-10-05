

#include "Arduino.h"

#define RED_LED_PIN    26
#define GREEN_LED_PIN  27
#define BLUE_LED_PIN   14
#define YELLOW_LED_PIN 12

int chasePins[6] = {
    RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN,
    BLUE_LED_PIN, YELLOW_LED_PIN, GREEN_LED_PIN
};

const char *chaseNames[6] = {
    "RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN"
};

int stepIndex = 0;


/****************************************************/
void setup(void) 
{
    Serial.begin(115200);

    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
}


/****************************************************/
void loop(void) 
{
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);

    digitalWrite(chasePins[stepIndex], HIGH);

    Serial.print("chase=");
    Serial.println(chaseNames[stepIndex]);

    stepIndex = stepIndex + 1;
    if (stepIndex >= 6) 
    {
        stepIndex = 0;
    }

    delay(150);
}
