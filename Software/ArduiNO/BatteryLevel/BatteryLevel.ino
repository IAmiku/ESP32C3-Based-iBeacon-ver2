#include "FS.h"

#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library
#include <TFT_eWidget.h>           // Widget library

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

// This is the file name used to store the calibration data
// You can change this to create new calibration files.
// The SPIFFS file name must start with "/".
#define CALIBRATION_FILE "/TouchCalData1"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //LCD
  pinMode(1, OUTPUT);
  digitalWrite(1,HIGH);
  // Initialise the TFT screen
  tft.init();
  // Set the rotation
  tft.setRotation(0);
  // Clear the screen
  tft.setTextColor(0xFFFF,0x0000,true);
  tft.fillRectHGradient(0, 0, tft.width(), tft.height(), 0xF000, 0x000F);
}

void loop() {
  // put your main code here, to run repeatedly:
    //float batteryLevel = map(analogRead(0), 0.0f, 4095.0f, 0, 100);
    float batteryLevel=map(abs(float(analogRead(0))),1650.0f,2950.0f,0.0f,100.0f); //no battery, 1V with 1650    1.77test 4.17btt with 3000
    tft.setTextDatum(0);
    tft.println(batteryLevel);
    tft.setCursor(0,0);

}
