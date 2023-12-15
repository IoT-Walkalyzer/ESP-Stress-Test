// Includes
#include <Arduino.h>
#include <WiFi.h>
#include <mqtt_client.h>

// Types
using Lane = uint8_t[40];
using Matrix = Lane[40];

// Variables
const Matrix matrix = {};
const esp_mqtt_client_config_t mqttConf = {
        .host = "<MQTT HOST>",
        .port = 1883,
        .client_id = "esp-wroom-32",
        .buffer_size = 1600
};
esp_mqtt_client_handle_t mqttClient;

// Methods
void setup() {
    Serial.begin(921600);
    WiFi.begin("<SSID>", "<PSWD>");

    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("Trying to connect...");
        delay(1000);
    }

    mqttClient = esp_mqtt_client_init(&mqttConf);
    esp_mqtt_client_start(mqttClient);
}

void loop() {
    esp_mqtt_client_publish(
            mqttClient,
            "stressTest",
            (const char*)matrix,
            sizeof(matrix),
            0,
            0
    );
}
