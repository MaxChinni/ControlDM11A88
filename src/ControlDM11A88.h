/**
 *    ControlDM11A88 - Simple DM11A88 8x8 led matrix library for ESP8266.
 *    Copyright (c) 2022 Massimiliano Chinni
 */

#ifndef ControlDM11A88_h
#define ControlDM11A88_h

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
    #include "pins_arduino.h"
    #include "WConstants.h"
#endif

class ControlDM11A88 {
    private :
        int DI_PIN;
        int CLK_PIN;
        int LAT_PIN;
        unsigned int MAX_DEVICES;
        /* keep track of all the leds status */
        uint8_t status[8][8] = { 0 };

        void myShiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);

    public:
        /**
         * Create a new controler
         * TODO expain params
         * diPin
         * clkPin
         * latPin
         * numDevices
         */
        ControlDM11A88(int diPin, int clkPin, int latPin, int numDevices);

        /**
         * Get the number of devices managed by this object
         */
        int getDeviceCount();

        /**
         * Switch all Leds on the display off. 
         */
        void clearDisplay();

        /**
         * Set all 8 Led's in a row to a new state
         * Params:
         * addr : the address of the display to control (between 0 and MAX_DEVICES)
         * row  : row which is to be set (0..7)
         * value: each bit set to 1 will light up the corresponding Led
         */
        void setRow(int addr, int row, uint8_t value);
};

#endif // ControlDM11A88_h
