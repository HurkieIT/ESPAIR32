//Input file voor alle buttons en pinouts
#include <Arduino.h>

//Wireless (WIFI + BT) Support Library
#include <wireless.h>

//MQTT Scan Support Library
#include  <mqtt-client.h>

//LoRa Support Library
#include <lora.h>


#pragma once //hiermee wordt iedere header file maar eenmalig opgenomen



#define Button_SELECT_PIN 19
#define Button_DOWN_PIN   18
#define Button_BACK_PIN   16
#define Button_OK_PIN     17
#define BUTTON_PIN_MODE   INPUT_PULLUP  // INPUT, INPUT_PULLUP, INPUT_PULLDOWN

#define BUTTON_ACTIVE_LOW        true  // per button press, als de button niet LOW is, telt het als een press.

void static setupInputPins() 
{
    pinMode(Button_SELECT_PIN, BUTTON_PIN_MODE);
    pinMode(Button_DOWN_PIN, BUTTON_PIN_MODE);
    pinMode(Button_BACK_PIN, BUTTON_PIN_MODE);
    pinMode(Button_OK_PIN, BUTTON_PIN_MODE);
}