#include <Arduino.h>
#include "modules/light.h"
#include "modules/fan.h"
#include "modules/door.h"
#include "sensors/pir.h"
#include "sensors/ultrasonic.h"
#include "modules/rfid.h"
#include "utils/wifi_manager.h"
#include "config.h"

void setup() {
    Serial.begin(115200);

    initLights();
    initFans();
    initDoors();
    initPIR();
    initRFID();
    initWiFi();
}

void loop() {

    // 🌐 Web control
    handleClient();

    // 🚪 Door (Ultrasonic)
    if (getDistance(TRIG1, ECHO1) < 50) {
        openDoor(0);
        delay(3000);
        closeDoor(0);
    }

    // 🔐 RFID Door
    if (checkRFID()) {
        openDoor(1);
        delay(3000);
        closeDoor(1);
    }

    // 💡 Motion Lights
    if (detectMotion(PIR1)) setLight(0, HIGH);
    else setLight(0, LOW);

    if (detectMotion(PIR2)) setLight(1, HIGH);
    else setLight(1, LOW);

    delay(200);
}