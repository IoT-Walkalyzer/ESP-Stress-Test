// Includes
#include <Arduino.h>

// Types
using Lane = uint8_t[40];
using Matrix = Lane[40];

// Variables
const uint8_t laneSize = sizeof(Lane);
const Matrix matrix = {};

// Methods
void setup() {
    Serial.begin(921600);
}

void loop() {
    Serial.write('s'); // Start of matrix Header

    for (const Lane& lane : matrix)
        Serial.write((const uint8_t*)lane, laneSize);
}