#include <Wire.h>
#include <Adafruit_PN532.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define SDA_PIN 21
#define SCL_PIN 22

Adafruit_PN532 nfc(-1, -1);

// WiFi
const char* ssid = "Airbox-0118";
const char* password = "6SL5FsAtWAjh";

// Firebase base URL
String baseURL = "https://mini-projet-embarque-default-rtdb.firebaseio.com/products/";

String lastUID = "";
unsigned long lastTime = 0;

void setup() {
  Serial.begin(115200);

  Wire.begin(SDA_PIN, SCL_PIN);

  nfc.begin();

  if (!nfc.getFirmwareVersion()) {
    Serial.println("PN532 not found");
    while (1);
  }

  nfc.SAMConfig();

  // WiFi connect
  WiFi.begin(ssid, password);
  Serial.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nGOOD STATION READY");
}

void loop() {

  uint8_t uid[7];
  uint8_t uidLength;

  if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength)) {

    String currentUID = "";

    for (int i = 0; i < uidLength; i++) {
      if (uid[i] < 0x10) currentUID += "0";
      currentUID += String(uid[i], HEX);
    }

    currentUID.toUpperCase();

    if (currentUID != lastUID && millis() - lastTime > 2000) {

      lastUID = currentUID;
      lastTime = millis();

      Serial.print("GOOD PRODUCT: ");
      Serial.println(currentUID);

      if (WiFi.status() == WL_CONNECTED) {

        HTTPClient http;

        String url = baseURL + currentUID + ".json";

        http.begin(url);
        http.addHeader("Content-Type", "application/json");

        String payload =
          "{\"status\":\"GOOD\",\"station\":\"GOOD_LINE\"}";

        int code = http.PUT(payload);

        Serial.print("Firebase response: ");
        Serial.println(code);

        http.end();
      }
    }

    delay(1000);
  }
}