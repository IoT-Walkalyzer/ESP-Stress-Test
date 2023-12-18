// Includes
#include <Arduino.h>
#include <BluetoothSerial.h>

// Types
using Lane = uint8_t[40];
using Matrix = Lane[40];

// Variables
const uint8_t laneSize = sizeof(Lane);
const Matrix matrix = {};
BluetoothSerial SerialBT;

// Methods
void setup() {
    Serial.begin(921600);
    SerialBT.begin("iotStressTest");
}

void loop() {
    SerialBT.write('s'); // Start of matrix Header

    for (const Lane& lane : matrix)
        SerialBT.write((const uint8_t*)lane, laneSize);
}