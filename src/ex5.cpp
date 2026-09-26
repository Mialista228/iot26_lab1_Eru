#include "Arduino.h"

#define BUTTON_PIN 25
#define LIGHT_PIN 33
#define LED_PIN 12

void setup(void)
{
    Serial.begin(115260);

    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}

void loop(void)
{
    if (digitalRead(BUTTON_PIN) == HIGH)
    {

        int lightVal = analogRead(LIGHT_PIN);

        Serial.println("snapshot=" + String(lightVal));

        analogWrite(LED_PIN, HIGH);
        delay(100);
        analogWrite(LED_PIN, LOW);

        while (digitalRead(BUTTON_PIN) == HIGH)
        {
            delay(10);
        }
    }
}