// Includes
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

// Types
using Lane = uint8_t[40];
using Matrix = Lane[40];

// Variables
const Matrix matrix = {};
WiFiUDP udpClient;

// Methods
void setup() {
  Serial.begin(921600);
  WiFi.begin("<SSID>", "<PSWD>");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Trying to connect...");
    delay(1000);
  }
}

void loop() {
  udpClient.beginPacket("<SERVER IP>", "<SERVER PORT>");
  udpClient.write('s');
  udpClient.endPacket();

  udpClient.beginPacket("<SERVER IP>", "<SERVER PORT>");
  udpClient.write(
      (const uint8_t*)matrix,
      sizeof(matrix)
      );
  udpClient.endPacket();
  delay(1);
}