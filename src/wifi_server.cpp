//
// Created by rudra on 15-02-2026.
//
#include <WiFi.h>
#include "config.h"
#include "relay.h"

static WiFiServer server(80);

void wifiInit() {
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {}
    server.begin();
}

void wifiHandle() {
    WiFiClient client = server.available();
    if (!client) return;

    String req = client.readStringUntil('\r');

    if (req.indexOf("/on") != -1) relayOn();
    if (req.indexOf("/off") != -1) relayOff();

    client.println("HTTP/1.1 200 OK\nContent-Type: text/plain\n\nOK");
    client.stop();
}