//
// Created by rudra on 15-02-2026.
//
#include <Arduino.h>
#include "config.h"
#include "relay.h"

void relayInit() {
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
}

void relayOn() {
    digitalWrite(RELAY_PIN, HIGH);
}

void relayOff() {
    digitalWrite(RELAY_PIN, LOW);
}