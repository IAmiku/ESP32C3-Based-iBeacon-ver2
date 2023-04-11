// Demo based on:
// UTFT_Demo_320x240 by Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
/*

 This sketch uses the GLCD and font 2 only.
 
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */

#include "SPI.h"

#include "TFT_eSPI.h"

#define TFT_GREY 0x7BEF

#define LED_GPIO   18
#define PWM1_Ch    0
#define PWM1_Res   8
#define PWM1_Freq  1000
 
int PWM1_DutyCycle = 225;
int BeginDim=1;

  int buf[318];
  int x, x2;
  int y, y2;
  int r;
  int col = 0;

TFT_eSPI myGLCD = TFT_eSPI();       // Invoke custom library

unsigned long runTime = 0;
void setup()
{
// Setup the LCD
  Serial.begin(115200);
  Serial.print("setup start");
  myGLCD.init();
  myGLCD.setRotation(1);
  Serial.print("47 reached");
  ledcAttachPin(LED_GPIO, PWM1_Ch);
  ledcSetup(PWM1_Ch, PWM1_Freq, PWM1_Res);
  Serial.print("setup done");


}



void loop()
{
    Serial.print("loop being");
if(PWM1_DutyCycle > 255){BeginDim=1;}
if(PWM1_DutyCycle < 1  ){BeginDim=0;}

  if(BeginDim)
  {
    ledcWrite(PWM1_Ch, PWM1_DutyCycle-=1);
  }
  else
  {
    ledcWrite(PWM1_Ch, PWM1_DutyCycle+=1);
  }
  
  Serial.printf("%d\n",PWM1_DutyCycle);



// Draw a moving sinewave
  x=1;
  for (int i=1; i<(317*400); i++) 
  {
    x++;
    if (x==318)
      x=1;
    if (i>318)
    {
      if ((x==159)||(buf[x-1]==119))
        col = TFT_BLUE;
      else
      myGLCD.drawPixel(x,buf[x-1],TFT_BLACK);
    }
    y=119+(sin(((i*1.1)*3.14)/180)*(90-(i / 100)));
    myGLCD.drawPixel(x,y,TFT_BLUE);
    buf[x-1]=y;
  }

  delay(0);

  myGLCD.fillRect(1,15,317,209,TFT_BLACK);
//*/
}



