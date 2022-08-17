#include <ControlDM11A88.h>
#include <Ticker.h>

// Parameters: DI_PIN, CLK_PIN, LAT_PIN
ControlDM11A88 lc(D7, D8, D5);

void timeStep();

int timeCounter = 0;
Ticker timePassing = Ticker(timeStep, 1000, 0, MILLIS);

uint8_t i;
uint8_t frames[][8] = {
    {B00111100, B01111110, B01100110, B01100110, B01100110, B01100110, B01111110, B00111100},
    {B00011000, B00111000, B01111000, B11011000, B00011000, B00011000, B01111110, B01111110},
    {B00111100, B01111110, B01000110, B00001100, B00011000, B00110000, B01111110, B01111110},
    {B00111110, B01111110, B01000110, B00011100, B00111110, B00000110, B01111110, B01111110},
    {B00011100, B00111100, B01101100, B11001100, B11111110, B11111110, B00001100, B00001100},
    {B01111110, B01111110, B01100000, B01111110, B00111110, B00000110, B01111110, B01111110},
    {B01111110, B01111110, B01100000, B01111110, B01111110, B01100110, B01111110, B01111110},
    {B01111110, B01111110, B00000110, B00001100, B00011000, B00110000, B00110000, B00110000},
    {B00111100, B01111110, B01100110, B00111100, B00111100, B01100110, B01111110, B00111100},
    {B00111100, B01111110, B01100110, B01111110, B01111110, B00000110, B01111110, B01111100},
};
uint8_t curDisplay[8] = { 0 };

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
    for (i=0; i<8; i++) {
        curDisplay[i] = frames[timeCounter][i];
    }
    timeCounter = (timeCounter + 1) % (sizeof(frames) / sizeof(frames[0]));
}

void refreshDisplay()
{
    for (i=0; i<8; i++) {
        lc.setRow(i, curDisplay[i]);
    }
}
