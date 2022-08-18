#include <ControlDM11A88.h>

// Parameters: DI_PIN, CLK_PIN, LAT_PIN, numDevicesConnected
ControlDM11A88 lc(D7, D8, D5, 2);

int addr;
uint8_t row;
uint8_t dataToShow[][8] = {
    {B00111100, B01111110, B01100110, B01100110, B01100110, B01100110, B01111110, B00111100},
    {B00011000, B00111000, B01111000, B11011000, B00011000, B00011000, B01111110, B01111110},
};

void setup()
{
}

void loop()
{
    for (addr=0; addr<lc.getDeviceCount(); addr++) {
        for (row=0; row<8; row++) {
            lc.setRow(addr, row, dataToShow[addr][row]);
        }
    }
}
