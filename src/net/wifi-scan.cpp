#include <Arduino.h>
#include <WiFi.h>
#include "net/wifi-scan.h"

static void ClearTerminal()
{
    Serial.print("\033[2J");  // clear screen
    Serial.print("\033[H");   // cursor home
}

void NetworkScan(const scanconfig& config) {

    //digitalWrite(LED_SCAN_PIN, HIGH);  // scan start -> LED aan

    //Switch wifi module op de ESP32 naar de station mode, dit zorgt ervoor dat de ESP32 zich als een client gedraagt en vrij verbinding kan maken met netwerken.
    //Vervolgens wordt er een disconnect afgedwongen om ervoor te zorgen dat er geen verbindingen actief zijn tijdens de daadwerkelijke scan. De reden hiervoor is dat de ESP32 maar 1 netwerkinterface in zijn bezit heeft.
    //Bron: https://docs.espressif.com/projects/arduino-esp32/en/latest/api/wifi.html
    
    ClearTerminal();
    WiFi.mode(WIFI_STA);
    WiFi.disconnect(true);
    delay(100);

    WiFi.scanDelete();

    int numNetworks = WiFi.scanNetworks(false, config.showHidden);

    //Hier wordt er gecontroleerd met een if statement of er wel netwerken beschikbaar zijn, is het aantal netwerken kleiner of gelijk aan 0, dan krijg je "No Networks Found" te zien.
    if (numNetworks <= 0)
    {
        Serial.print("No Networks Found");
        return;
    }

    //Binnen deze For statement worden de gevonden netwerken geprint en op de seriele monitor getoont.
    //Daarbij worden de naam, Signaal sterkte, kanaal en Encryptie methode vertoont.

    int limit = (numNetworks < config.maxNetworks) ? numNetworks : config.maxNetworks;

    for (int i = 0; i < limit; i++)
    {
        Serial.print("Network Name: ");
        Serial.print(WiFi.SSID(i));

        Serial.print(" | RSSI: ");
        Serial.print(WiFi.RSSI(i));

        Serial.print(" | Channel: ");
        Serial.print(WiFi.channel(i));

        Serial.print(" | Encryption: ");
            if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
                Serial.print("Open");
            } else if (WiFi.encryptionType(i) == WIFI_AUTH_WEP) {
                Serial.print("WEP");
            } else if (WiFi.encryptionType(i) == WIFI_AUTH_WPA_PSK) {
                Serial.print("WPA");
            } else if (WiFi.encryptionType(i) == WIFI_AUTH_WPA2_PSK) {
                Serial.print("WPA2");
            } else if (WiFi.encryptionType(i) == WIFI_AUTH_WPA_WPA2_PSK) {
                Serial.print("WPA/WPA2");
            } else if (WiFi.encryptionType(i) == WIFI_AUTH_WPA3_PSK) {
                Serial.print("WPA3");
            } else {
                Serial.print("Unknown");
            }
            Serial.println();
            Serial.println("________________________________________________");

            //digitalWrite(LED_SCAN_PIN, LOW);   // scan klaar  -> LED uit
    }
}