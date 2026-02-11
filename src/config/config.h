//Binnen deze configuratie header worden alle standaarden gedefinieerd die gebruikt kunnen worden binnen het project, deze zullen veel al over wifi gerelateerde zaken gaan en enkele debugs zullen hier ook aanwezig zijn.
//Doormiddel van deze opdracht wordt dit bestand maar een keer geincludeerd binen het project, dit zorgt dat er geen dubbele definities worden gebruikt. Bron: https://en.wikipedia.org/wiki/Pragma_once#:~:text=In%20the%20C%20and%20C,once%20in%20a%20single%20compilation.

#pragma once

#define WIFI_SCAN_INTERVAL_MS        5000
#define WIFI_MAX_NETWORKS            30
#define WIFI_SORT_BY_RSSI            true
#define WIFI_SHOW_HIDDEN             true
#define WIFI_SHOW_ENCRYPTION         true
#define WIFI_ONLY_24GHZ              true
// toekomst #define WIFI_SHOW_BSSID              true

#define DEBUG_SERIAL                 true
#define DEBUG_BAUDRATE               115200

//Schijnbaar als je een OLED scherm gebruikt, moet je deze defineren omdat anders het scherm flikkert en niet goed werkt.
//Bron: https://forum.arduino.cc/t/oled-ssd1306-flickering/1040319

#define SCREEN_WIDTH                  128
#define SCREEN_HEIGHT                 64
#define UI_ITEMS_PER_PAGE             5


