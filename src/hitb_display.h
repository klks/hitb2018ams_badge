#pragma once

extern int button_cancel_state;

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "qrcode.h"

// If using software SPI (the default case):
#define OLED_MOSI  PA7
#define OLED_CLK   PA5
#define OLED_DC    PB1
#define OLED_CS    PB11
#define OLED_RESET PB10

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup_display(){
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  display.setTextWrap(false);
}

void wake_display(){
  display.dim(false);
}

void sleep_display(){
  display.clearDisplay();
  display.dim(true);
  display.display();
}

boolean delay_interuptable(int wait_time){
  for(int i=0; i < wait_time; i++){
    if(button_cancel_state) return false;
    delay(1);
  }
  return true;
}

//https://github.com/ricmoo/QRCode/blob/master/examples/QRCode/QRCode.ino
void display_qrcode(const char *data){
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(3)];

  qrcode_initText(&qrcode, qrcodeData, 3, ECC_HIGH, data);
  
  display.clearDisplay();
  display.fillRect(35, 0, 62, 64, WHITE);
  int x_offset = 37, y_offset = 3;
  for(uint8_t y = 0; y < qrcode.size; y++){
    for(uint8_t x = 0; x < qrcode.size; x++){
      if(qrcode_getModule(&qrcode, x, y)){
        //display.drawPixel(x_offset + x, y_offset + y, BLACK);
        display.drawPixel(x_offset + (x*2), y_offset + (y*2), BLACK);
        display.drawPixel(x_offset +(x*2)+1, y_offset + (y*2), BLACK);
        display.drawPixel(x_offset + (x*2)+1, y_offset + (y*2)+1, BLACK);
        display.drawPixel(x_offset + (x*2), y_offset + (y*2)+1, BLACK);
      }
    }
  }
  display.display();
  while(delay_interuptable(1000));
  delay(200); //Let buttons settle down
}

