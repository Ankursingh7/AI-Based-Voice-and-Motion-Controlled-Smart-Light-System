#include "rfid.h"
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 22

MFRC522 mfrc522(SS_PIN, RST_PIN);

// Replace with your card UID
byte allowedUID[4] = {0xDE, 0xAD, 0xBE, 0xEF};

void initRFID() {
    SPI.begin();
    mfrc522.PCD_Init();
}

bool checkRFID() {
    if (!mfrc522.PICC_IsNewCardPresent()) return false;
    if (!mfrc522.PICC_ReadCardSerial()) return false;

    for (byte i = 0; i < 4; i++) {
        if (mfrc522.uid.uidByte[i] != allowedUID[i])
            return false;
    }
    return true;
}