#include "wifi_manager.h"
#include <WiFi.h>

const char* ssid = "YOUR_WIFI";
const char* pass = "YOUR_PASS";

WiFiServer server(80);

void initWiFi() {
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    server.begin();
}

void handleClient() {
    WiFiClient client = server.available();
    if (!client) return;

    String req = client.readStringUntil('\r');

    // Debug
    Serial.println(req);

    // Example routes
    if (req.indexOf("/light1_on") != -1) digitalWrite(27, HIGH);
    if (req.indexOf("/light1_off") != -1) digitalWrite(27, LOW);

    if (req.indexOf("/fan1_on") != -1) digitalWrite(25, HIGH);
    if (req.indexOf("/fan1_off") != -1) digitalWrite(25, LOW);

    client.println("HTTP/1.1 200 OK\nContent-Type: text/plain\n\nOK");
    client.stop();
}