/**
 *    ControlDM11A88 - Simple DM11A88 8x8 led matrix library for ESP8266.
 *    Copyright (c) 2022 Massimiliano Chinni
 */

#include "ControlDM11A88.h"

ControlDM11A88::ControlDM11A88(int diPin, int clkPin, int latPin)
{
    DI_PIN = diPin;
    CLK_PIN = clkPin;
    LAT_PIN = latPin;

    pinMode(DI_PIN, OUTPUT);
    pinMode(CLK_PIN, OUTPUT);
    pinMode(LAT_PIN, OUTPUT);

    clearDisplay();
}

void ControlDM11A88::clearDisplay()
{
    ControlDM11A88::myShiftOut(DI_PIN, CLK_PIN, LSBFIRST, B11111111);
    ControlDM11A88::myShiftOut(DI_PIN, CLK_PIN, LSBFIRST, B00000000);
    digitalWrite(LAT_PIN, LOW);
    digitalWrite(LAT_PIN, HIGH);
}

void ControlDM11A88::myShiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
    uint8_t i;

    for (i = 0; i < 8; i++)  {
        if (bitOrder == LSBFIRST)
            digitalWrite(dataPin, !!(val & (1 << i)));
        else
            digitalWrite(dataPin, !!(val & (1 << (7 - i))));

        digitalWrite(clockPin, LOW);
        digitalWrite(clockPin, HIGH);
    }
}

void ControlDM11A88::setRow(int row, uint8_t value)
{
    digitalWrite(LAT_PIN, LOW);
    ControlDM11A88::myShiftOut(DI_PIN, CLK_PIN, LSBFIRST, ~(B00000000 | 1 << row));
    ControlDM11A88::myShiftOut(DI_PIN, CLK_PIN, LSBFIRST, value);
    digitalWrite(LAT_PIN, HIGH);
}
