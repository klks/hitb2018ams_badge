#pragma once
extern Adafruit_SSD1306 display;
extern boolean enable_diagnostics;
extern int button_up_state;
extern int button_down_state;
extern int button_left_state;
extern int button_right_state;
extern int button_ok_state;
extern int button_cancel_state;
extern WS2812B strip;

int _cur_pos;

class MyDiagnosticsRenderer : public MenuComponentRenderer {
public:
    void render(Menu const& menu) const {
      if(_cur_pos > menu.get_num_components() ) _cur_pos = menu.get_num_components()-1;
      if(0 > _cur_pos) _cur_pos = 0;
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(32,0);
      display.print("Diagnostics");
      display.drawLine(0, 10, 128, 10, WHITE);
      
      for(int i= ((_cur_pos/5) * 5), j=0; i <menu.get_num_components(); ++i, ++j){
        MenuComponent const* cp_m_comp = menu.get_menu_component(i);
        if(cp_m_comp->is_current())
        {
          display.setCursor(5, 15 + (j*10));
          display.print(">");
        }
        display.setCursor(15, 15 + (j*10));
        display.print(cp_m_comp->get_name());
      }
      display.display();
    }

    void render_menu_item(MenuItem const& menu_item) const {
    }

    void render_back_menu_item(BackMenuItem const& menu_item) const {
    }

    void render_numeric_menu_item(NumericMenuItem const& menu_item) const {
    }

    void render_menu(Menu const& menu) const {
    }
};
MyDiagnosticsRenderer diag_renderer;
MenuSystem ms_diag(diag_renderer);
  
void diag_handle_buttons(){
  if(button_up_state || button_left_state){
    ms_diag.prev();
    _cur_pos -= 1;
  }
  else if(button_down_state || button_right_state){
    ms_diag.next();
    _cur_pos += 1;
  }
  else if(button_cancel_state){
    ms_diag.back();
    _cur_pos = 0;
    ms_diag.reset();
  }
  else if(button_ok_state){
    ms_diag.select();
  }
  ms_diag.display();
}

void on_test_lcd_selected(MenuComponent* p_menu_component) {
  display.clearDisplay();
  for (int16_t i=0; i<display.height(); i+=2) {
    display.drawCircle(display.width()/2, display.height()/2, i, WHITE);
    display.display();
  }
  delay(2000);
  
  display.clearDisplay();
  uint8_t color = 1;
  for (int16_t i=0; i<display.height()/2; i+=3) {
    // alternate colors
    display.fillRect(i, i, display.width()-i*2, display.height()-i*2, color%2);
    display.display();
    color++;
  }
  delay(2000);

  display.clearDisplay();
  for (int16_t i=0; i<min(display.width(),display.height())/2; i+=5) {
    display.drawTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, WHITE);
    display.display();
  }
  delay(2000);

  display.clearDisplay();
  color = WHITE;
  for (int16_t i=0; i<display.height()/2-2; i+=2) {
    display.fillRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
  }
  delay(2000);
}

void on_test_led_selected(MenuComponent* p_menu_component) {
  display.clearDisplay();
  display.setCursor(5, 30);
  display.println("Cancel to exit...");
  display.display();

  //strip.setBrightness(10);
  while(!button_cancel_state){
    //rainbowCycle2(10);
    led_rf();
  }
  leds_off();
}

void on_test_button_selected(MenuComponent* p_menu_component) {
  int cancel_count = 0;

  while(cancel_count != 2){
    display.clearDisplay();
    display.setCursor(0, 0);
        
      if (button_ok_state){
        display.println("OK HIGH");
        cancel_count = 0;
      }
      else {
        display.println("OK LOW");
      }

      if (button_cancel_state){
        display.println("ESC HIGH");
        cancel_count += 1;
      }
      else {
        display.println("ESC LOW");
      }

      if (button_down_state){
        display.println("DOWN HIGH");
        cancel_count = 0;
      }
      else {
        display.println("DOWN LOW");
      }

      if (button_up_state){
        display.println("UP HIGH");
        cancel_count = 0;
      }
      else {
        display.println("UP LOW");
      }

      if (button_left_state){
        display.println("LEFT HIGH");
        cancel_count = 0;
      }
      else {
        display.println("LEFT LOW");
      }

      if (button_right_state){
        display.println("RIGHT HIGH");
        cancel_count = 0;
      }
      else {
        display.println("RIGHT LOW");
      }
    display.display();
    delay(130);
  }
}
/*
void on_test_ir_selected(MenuComponent* p_menu_component) {
}

void on_test_rf_selected(MenuComponent* p_menu_component) {
  uint8_t buf[60];
  uint8_t buflen = sizeof(buf);

  display.clearDisplay();
  display.setCursor(5, 20);
  display.println("Waiting for message...");
  display.setCursor(5, 30);
  display.println("Cancel to exit...");
  display.display();
  
  while(!button_cancel_state){
    memset(buf, 0, sizeof(buf));
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      if(buf[0] == 0x13 && buf[1] == 0x37){
        display.clearDisplay();
        display.setCursor(0, 20);
        display.print((const char*)&buf[2]);
        display.display();
        delay_interuptable(1);
      }
      delay_interuptable(10);
    }
  }
}
*/

void show_diagnostics(){
  MenuItem mm_mi_test_lcd("LCD Test", &on_test_lcd_selected);
  MenuItem mm_mi_test_led("LED Test", &on_test_led_selected);
  MenuItem mm_mi_test_button("Button Test", &on_test_button_selected);
  //MenuItem mm_mi_test_ir("IR Test", &on_test_ir_selected);
  //MenuItem mm_mi_test_rf("RF Test", &on_test_rf_selected);

  ms_diag.get_root_menu().add_item(&mm_mi_test_lcd);
  ms_diag.get_root_menu().add_item(&mm_mi_test_led);
  ms_diag.get_root_menu().add_item(&mm_mi_test_button);
  //ms_diag.get_root_menu().add_item(&mm_mi_test_ir);
  //ms_diag.get_root_menu().add_item(&mm_mi_test_rf);

  ms_diag.display();
  delay(200);   //wait for button press to settle down
  while(1){
    diag_handle_buttons();
    delay(130);
  }
}

