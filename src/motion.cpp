//
// Created by rudra on 15-02-2026.
//
#include <Arduino.h>
#include "config.h"
#include "relay.h"

static unsigned long lastMotion = 0;
static bool lightOnState = false;

void motionInit() {
    pinMode(PIR_PIN, INPUT);
}

void motionCheck() {
    if (digitalRead(PIR_PIN)) {
        relayOn();
        lightOnState = true;
        lastMotion = millis();
    }

    if (lightOnState && millis() - lastMotion > 30000) {
        relayOff();
        lightOnState = false;
    }
}