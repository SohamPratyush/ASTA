#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
        Serial.begin(9600);
        SPI.begin();
        mfrc522.PCD_Init();
}

void loop() {
        MFRC522::MIFARE_Key key;
        for (byte i = 0; i < 6; i++) {
                key.keyByte[i] = 0xFF;
        }
        if ( ! mfrc522.PICC_IsNewCardPresent()) {
                return;
        }
        if ( ! mfrc522.PICC_ReadCardSerial()) {
                return;
        }
        Serial.print("Card UID:");
        for (byte i = 0; i < mfrc522.uid.size; i++) {
                Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                Serial.print(mfrc522.uid.uidByte[i], DEC);
        } 
        Serial.println();
        byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
        Serial.print("PICC type: ");
        Serial.println(mfrc522.PICC_GetTypeName(piccType));
        if (        piccType != MFRC522::PICC_TYPE_MIFARE_MINI 
                &&        piccType != MFRC522::PICC_TYPE_MIFARE_1K
                &&        piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
                return;
        }
}
