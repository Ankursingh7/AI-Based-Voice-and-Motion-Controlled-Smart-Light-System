//
// Created by rudra on 20-03-2026.
//
// fan.cpp
#include "fan.h"
#include <Arduino.h>

int fanPins[2] = {25, 33};

void initFans() {
    for (int i = 0; i < 2; i++) {
        pinMode(fanPins[i], OUTPUT);
        digitalWrite(fanPins[i], LOW);
    }
}

void setFan(int id, bool state) {
    digitalWrite(fanPins[id], state);
}