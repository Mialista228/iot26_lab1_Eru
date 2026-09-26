#include "Arduino.h"

#define LIGHT 33

void setup(void)
{
    pinMode(LIGHT, INPUT);
    Serial.begin(115260);
}

void loop(void)
{
    delay(500);
    int light = analogRead(LIGHT);
    Serial.println("raw=" + String(light));
}