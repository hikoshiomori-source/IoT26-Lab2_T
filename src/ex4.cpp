

#include "Arduino.h"

#define RED_LED_PIN    26
#define GREEN_LED_PIN  27
#define BLUE_LED_PIN   14
#define YELLOW_LED_PIN 12

#define BUTTON_PIN 25

int pressCount = 0;
int lastButtonState = LOW;


/****************************************************/
void showLeds(int howMany) 
{
    digitalWrite(RED_LED_PIN,    (howMany >= 1) ? HIGH : LOW);
    digitalWrite(GREEN_LED_PIN,  (howMany >= 2) ? HIGH : LOW);
    digitalWrite(YELLOW_LED_PIN, (howMany >= 3) ? HIGH : LOW);
    digitalWrite(BLUE_LED_PIN,   (howMany >= 4) ? HIGH : LOW);
}


/****************************************************/
void setup(void) 
{
    Serial.begin(115200);

    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);

    pinMode(BUTTON_PIN, INPUT);

    showLeds(pressCount);
}


/****************************************************/
void loop(void) 
{
    int buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == HIGH && lastButtonState == LOW) 
    {
        pressCount = pressCount + 1;
        if (pressCount > 4) 
        {
            pressCount = 0;
        }

        Serial.print("count=");
        Serial.println(pressCount);

        showLeds(pressCount);

        delay(50);
    }

    lastButtonState = buttonState;

    delay(10);
}
