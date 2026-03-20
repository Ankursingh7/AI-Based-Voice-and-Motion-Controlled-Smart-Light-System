#include "pir.h"
#include <Arduino.h>

void initPIR() {
    pinMode(14, INPUT);
    pinMode(12, INPUT);
}

bool detectMotion(int pin) {
    return digitalRead(pin);
}