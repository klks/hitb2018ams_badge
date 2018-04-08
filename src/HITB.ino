#include <SPI.h>
#include <Wire.h>
#include "hitb_display.h"
#include "hitb_intro.h"
#include "hitb_menus.h"
#include "hitb_buttons.h"
#include "hitb_leds.h"
#include "hitb_flash.h"
#include "hitb_rf.h"

void setup(){
  randomSeed(analogRead(PA3));
  afio_cfg_debug_ports(AFIO_DEBUG_NONE);    //If this is enabled, upload can only be done via serial
  //afio_cfg_debug_ports(AFIO_DEBUG_SW_ONLY);
  
  setup_display();  //Setup display oled
  setup_buttons();  //Setup buttons
  setup_menus();    //Setup Menu items
  setup_leds();     //Setup LED's
  setup_flash();    //Setup SPI Flash
  setup_rf();       //Setup SYN480R RF

  // init done
  hitb_intro();
}

void loop() {
  process_rf();
  show_menus();
}
