#include "door.h"
#include <ESP32Servo.h>

Servo doorServo[2];
int servoPins[2] = {19, 4};

void initDoors() {
    for (int i = 0; i < 2; i++) {
        doorServo[i].attach(servoPins[i]);
        doorServo[i].write(0);
    }
}

void openDoor(int id) {
    doorServo[id].write(90);
}

void closeDoor(int id) {
    doorServo[id].write(0);
}