//https://github.com/rogerclarkmelbourne/Arduino_STM32/blob/master/STM32F1/libraries/WS2812B/examples/WS2812B_test/WS2812B_test.ino
#pragma once
#include <WS2812B.h>

#define NUM_LEDS 6
#define STRIP_PIN PB15
WS2812B strip = WS2812B(NUM_LEDS);


void leds_off() {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
    delay(1); //If you dont do this, light may not all obey
  }
}

boolean intro_random(){
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if(random(2) == 0) {
      strip.setPixelColor(i, strip.Color(random(256),random(256),random(256)));
    }
    else{
      strip.setPixelColor(i, 0);
    }
    strip.show();
    boolean ret = delay_interuptable(3);
    if(!ret) return false;
  }
  return true;
}

boolean colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    boolean ret = delay_interuptable(wait);
    if(!ret) return false;
  }
  return true;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85)
  {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  else
  {
    if (WheelPos < 170)
    {
      WheelPos -= 85;
      return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    else
    {
      WheelPos -= 170;
      return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
  }
}

void rainbowCycle2(uint16_t wait)
{
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++)
  { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay_interuptable(wait);
  }
}

void rainbowCycle(uint8_t wait, uint8_t ctr)
{
  uint16_t i, j;

  for (i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + ctr) & 255));
  }
  strip.show();
  delay(wait);
}

void setup_leds() {
  strip.begin();
  strip.show();
}

// Led special effects triggered when radio frequency is received

void led_rf() {

  int color_brightness = 0;
  int led_action = 0;
  int color_len = 1;
  int led_count = 0;
  bool led_flag=false;
  while (!led_flag) {
    colorWipe(strip.Color(color_brightness, 0, 0), 10);
    if (color_brightness > 100) {
      led_action = 1;
      //led_count = led_count + 1;
    } else if (color_brightness < 2) {
      led_action = 2;
      led_count ++;
      //Serial1.println(led_count);
    }
    if (led_action == 1) {
      color_brightness -=   2;
    } else if (led_action == 2) {
      color_brightness +=   2;
    }
    if (led_count > 3) {
      //Serial1.println(led_count);
      led_flag = true;
      colorWipe(strip.Color(0, 0, 0), 0);
    }
  }
  colorWipe(strip.Color(0, 0, 0), 0);
}
