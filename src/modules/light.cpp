// light.cpp
#include "light.h"
#include <Arduino.h>

int lightPins[2] = {27, 26};

void initLights() {
    for (int i = 0; i < 2; i++) {
        pinMode(lightPins[i], OUTPUT);
        digitalWrite(lightPins[i], LOW);
    }
}

void setLight(int id, bool state) {
    digitalWrite(lightPins[id], state);
}