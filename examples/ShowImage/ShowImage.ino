#include <GxEPD2_3C.h>
#include <GxEPD2_MH29EP.h>
#include "BitmapWaveshare.h"

#define MAX_DISPLAY_BUFFER_SIZE 800
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= (MAX_DISPLAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8) ? EPD::HEIGHT : (MAX_DISPLAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8))

GxEPD2_3C<GxEPD2_MH29EP, MAX_HEIGHT(GxEPD2_MH29EP)> display(GxEPD2_MH29EP(/*CS=*/10, /*DC=*/8, /*RST=*/9, /*BUSY=*/7));

void setup()
{
  Serial.begin(115200);
  display.init(115200);
  display.drawImage(BitmapWaveshare_black, BitmapWaveshare_red, 0, 0, 128, 296, false, false, true);
  delay(2000);
  display.clearScreen();
  display.powerOff();
  Serial.println("setup done");
}

void loop()
{
}