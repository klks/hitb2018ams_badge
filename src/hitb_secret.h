extern Adafruit_SSD1306 display;
extern int button_up_state;
extern int button_down_state;
extern int button_left_state;
extern int button_right_state;
extern int button_ok_state;
extern int button_cancel_state;

void show_secret_menu(MenuComponent* p_menu_component) {
  int code_count = 0;
  char access_code[10];
  display.setTextSize(1);

  display.clearDisplay();
  display.setCursor(10,30);
  display.print("Entering...");
  display.display();

  delay(1000);   //Wait for button state clearup
  memset(access_code, 0, sizeof(access_code));

  while(code_count != 6){
    display.clearDisplay();
    display.setCursor(10,30);
    display.print("Code: ");
    display.print(access_code);

    if(button_up_state){
      access_code[code_count] = 'U';
      code_count += 1;
    }
    else if(button_down_state){
      access_code[code_count] = 'D';
      code_count += 1;
    }
    else if(button_left_state){
      access_code[code_count] = 'L';
      code_count += 1;
    }
    else if(button_right_state){
      access_code[code_count] = 'R';
      code_count += 1;
    }
    else if(button_ok_state){
      access_code[code_count] = 'O';
      code_count += 1;
    }
    else if(button_cancel_state){
      access_code[code_count] = 'C';
      code_count += 1;
    }

    display.display();
    delay(100);
  }

  display.clearDisplay();
  if(strcmp(access_code, "OOOOOO") == 0){
    display_qrcode("/*REDACTED*/");
    display.display();
  }
  else{
    display.setCursor(10,30);
    display.print("ACCESS DENIED!!! :(");
    display.display();
    delay_interuptable(5000);
  }

}
