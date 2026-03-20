#include "ultrasonic.h"
#include <Arduino.h>

long getDistance(int trig, int echo) {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    digitalWrite(trig, LOW);
    delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long duration = pulseIn(echo, HIGH, 30000);
    return duration * 0.034 / 2;
}