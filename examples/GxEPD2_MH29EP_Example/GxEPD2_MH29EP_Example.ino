#include <GxEPD2_3C.h> 
#include "GxEPD2_MH29EP.h"

#define MAX_DISPLAY_BUFFER_SIZE 800
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= (MAX_DISPLAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8) ? EPD::HEIGHT : (MAX_DISPLAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8))

GxEPD2_3C<GxEPD2_MH29EP, MAX_HEIGHT(GxEPD2_MH29EP)> display(GxEPD2_MH29EP(/*CS=*/10, /*DC=*/8, /*RST=*/9, /*BUSY=*/7));

void setup()
{
  display.init();
  // comment out next line to have no or minimal Adafruit_GFX code
  display.setTextColor(GxEPD_BLACK);
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    // comment out next line to have no or minimal Adafruit_GFX code
    display.print("Hello World!");
  }
  while (display.nextPage());

  delay(1000);
  display.clearScreen();
  display.hibernate();
}

void loop() {};
