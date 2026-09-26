#include "Arduino.h"

#define LIGHT_PIN 33
#define LED_BLUE 14
#define LED_GREEN 27
#define LED_YELLOW 12
#define LED_RED 26

void setup(void)
{
    Serial.begin(115260);

    pinMode(LIGHT_PIN, INPUT);

    pinMode(LED_BLUE, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);

    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
}

void loop(void)
{
    int value = analogRead(LIGHT_PIN);

    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);

    if (value <= 1023)
    {
        digitalWrite(LED_BLUE, HIGH);
        Serial.println("band=BLUE");
    }
    else if (value <= 2047)
    {
        digitalWrite(LED_YELLOW, HIGH);
        Serial.println("band=YELLOW");
    }
    else if (value <= 3071)
    {
        digitalWrite(LED_GREEN, HIGH);
        Serial.println("band=GREEN");
    }
    else if (value <= 4095)
    {
        digitalWrite(LED_RED, HIGH);
        Serial.println("band=RED");
    }

    delay(500);
}