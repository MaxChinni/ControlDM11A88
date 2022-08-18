#include <ControlDM11A88.h>
#include <Ticker.h>

// Parameters: DI_PIN, CLK_PIN, LAT_PIN
ControlDM11A88 lc(D7, D8, D5, 1);

void timeStep();

int timeCounter = 0;
Ticker timePassing = Ticker(timeStep, 3000, 0, MILLIS);

uint8_t i;
uint8_t frames[][8] = {
    // umbrella
    { B00000000, B00100100, B01111110, B11011011, B01111110, B00100100, B01100110, B00000000 },
    // alien
    { B00000000, B00011000, B00111100, B01111110, B11111111, B00010000, B00010000, B00011000 },
    // letter M
    { B01000001, B01100011, B01010101, B01001001, B01000001, B01000001, B01000001, B01000001 },
};
uint8_t status[8] = { 0 };

void setup()
{
    timePassing.start();
}

void loop()
{
    refreshDisplay();
    timePassing.update();
}

void timeStep()
{
    timeCounter = (++timeCounter) % (sizeof(frames) / sizeof(frames[0]));

    for (i=0; i<8; i++) {
        status[i] = frames[timeCounter][i];
    }
}

void refreshDisplay()
{
    for (i=0; i<8; i++) {
        lc.setRow(0, i, status[i]);
    }
}
