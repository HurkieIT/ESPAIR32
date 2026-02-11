#include <Arduino.h>
#include "net/wifi-scan.h"
#include "net/scanconfig.h"
#include "config/config.h"

scanconfig config;

void setup() {
    Serial.begin(DEBUG_BAUDRATE);
    //Hier worden de configuraties ingesteld die in de mainloop gebruikt gaaan worden. Hieronder roep ik de gemaakte struct aan met Boolean waarden en de twee unsigned integers, deze worden statisch gebruikt om geupdate te worden in de main loop. 
    pinMode(LED_SCAN_PIN, OUTPUT);
    digitalWrite(LED_SCAN_PIN, LOW); // start uit (als active-high)


    Serial.println("Wifi Scanner Start");
}

void loop() {
    NetworkScan(config);
    delay(config.scanIntervalMs);

}
