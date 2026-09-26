#include "Arduino.h"

#define LED_BLUE 14

void setup(void)
{
    Serial.begin(115260);

    pinMode(LED_BLUE, OUTPUT);
    digitalWrite(LED_BLUE, LOW);
}

void loop(void)
{
    if (Serial.available() > 0)
    {
        char cmd = Serial.read();

        if (cmd == 'B')
        {
            digitalWrite(LED_BLUE, HIGH);
            Serial.println("BLUE=1");
        }
        else if (cmd == 'b')
        {
            digitalWrite(LED_BLUE, LOW);
            Serial.println("BLUE=0");
        }
    }
}