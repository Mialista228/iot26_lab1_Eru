#include "Arduino.h"

#define GREEN_LED_PIN 27
#define BTN_PIN 25

bool cache = false;

void setup(void)
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BTN_PIN, INPUT);
    Serial.begin(115260);
}

void loop(void)
{
    bool btnVal = digitalRead(BTN_PIN);
    if (btnVal == HIGH)
    {
        digitalWrite(GREEN_LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(GREEN_LED_PIN, LOW);
    }
    delay(10);
    if (cache != btnVal)
    {
        if (cache == true)
            Serial.println("GREEN=0");
        else
            Serial.println("GREEN=1");
        cache = btnVal;
    }
}