#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  // Initialize the serial communication
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Hello, ESP32!");
}

void loop() {
  
}
