#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_SCK 7
#define TFT_MOSI 11
#define MISO 9
#define TFT_CS   12
#define TFT_DC   14
#define TFT_RST  8

//#define TFT_DC 9
//#define TFT_CS 10
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  Serial.begin(115200);
 // Serial.println("Shapes on Nucleo-32 SPI अरविन्द पाटील ...");
  delay(500);
 // Serial.println("इस कोड की रचना अरविन्द द्वारा 17/11/23 ");
  delay(1000);

  tft.begin();

  // Draw a color gradient square with reducing size
  drawColorGradientSquare();

  // Add text by Arvind Patil in yellow color
  tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(10, 280);
  tft.print("Arvind 23/1/24");
  tft.setTextColor(ILI9341_CYAN);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.print("square gradient");

tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(10, 55);
  tft.print("ATPDNC11@GMAIL.COM");



}

void drawColorGradientSquare() {
  int centerX = 120;
  int centerY = 160;
  int initialSize = 120;
  int sizeStep = 10;

  // Draw the square with reducing size using interpolated colors
  for (int size = initialSize; size > 0; size -= sizeStep) {
    int halfSize = size / 2;
    
    for (int x = centerX - halfSize; x <= centerX + halfSize; x++) {
      for (int y = centerY - halfSize; y <= centerY + halfSize; y++) {
        int distanceX = abs(x - centerX);
        int distanceY = abs(y - centerY);
        int maxDistance = max(distanceX, distanceY);
        
        int color = colorRangeMap(maxDistance, 0, halfSize, ILI9341_RED, ILI9341_BLUE);

        tft.drawPixel(x, y, color);
      }
    }
  }
}

int colorRangeMap(int value, int in_min, int in_max, int out_min, int out_max) {
  return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop() {
  // Your main code here
}
