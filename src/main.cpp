#include <Arduino.h>
#include "relay.h"
#include "motion.h"
#include "wifi_server.h"

void setup() {
// write your initialization code here
    relayInit();
    motionInit();
    wifiInit();
}

void loop() {
// write your code here
    motionCheck();
    wifiHandle();
}