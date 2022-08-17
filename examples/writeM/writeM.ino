#include <ControlDM11A88.h>

// Parameters: DI_PIN, CLK_PIN, LAT_PIN
ControlDM11A88 lc(D7, D8, D5);

uint8_t i;
uint8_t led[] = {
    B10000010,
    B11000110,
    B10101010,
    B10010010,
    B10000010,
    B10000010,
    B10000010,
    B10000010
};

void setup()
{
}

void loop()
{
    for (i=0; i<8; i++) {
        lc.setRow(i, led[i]);
    }
}
