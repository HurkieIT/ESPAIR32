#include <Arduino.h>
#include <Wifi.h>
#include "wifi-scan.h"

void NetworkScan(const scanconfig& config) {

    WiFi.mode(WIFI_STA);
    WiFi.disconnect(true);
    delay(100);

    WiFi.scanDelete();

    int numNetworks = Wifi.scanNetworks(false, config.showHidden);

    for (int i = 0; i < numNetworks && i < config.maxNetworks; i++)
    {
        Serial.print("Network Name: ");
        Serial.print(WiFi.SSID(i));

        Serial.print(" | RSSI: ");
        Serial.print(WiFi.RSSI(i));

        Serial.print(" | Channel: ");
        Serial.print(WiFi.channel(i));

        Serial.println("________________________________________________");
    }
}