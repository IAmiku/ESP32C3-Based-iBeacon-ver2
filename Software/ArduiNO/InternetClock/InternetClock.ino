
#include <WiFi.h>
#include "time.h"
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#define TFT_GREY 0x5AEB

TFT_eSPI tft = TFT_eSPI(); 

const char* ssid     = "2F";
const char* password = "jn009351";



void setup() {
  Serial.begin(115200);

    //LCD
  pinMode(1, OUTPUT);
  digitalWrite(1,HIGH);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  tft.setTextSize(1);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);

  // Connect to Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
    tft.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);

  tft.println("");
  tft.print("Connected to ");
  tft.println(ssid);
  // Init and get the time
  configTime(0, 0, "pool.ntp.org");
  
}

void loop() {
  
  // Print local time
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    tft.println("Failed to obtain time");
    return;
  }
  tft.setCursor(110,220);
  tft.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  
}