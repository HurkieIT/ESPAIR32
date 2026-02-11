#include <arduino.h>
#include <WiFi.h>
#include <Wire.h>
// OLED lib kies je later (Adafruit SSD1305/SSD1306 of U8g2)

const int BTN_SELECT = 19;
const int BTN_DOWN   = 18;
const int BTN_BACK   = 16;
const int BTN_OK     = 17;

const bool BUTTON_ACTIVE_LOW = true;
const int  BUTTON_PIN_MODE   = INPUT_PULLUP;

unsigned long lastScan = 0;
const unsigned long SCAN_INTERVAL_MS = 5000;