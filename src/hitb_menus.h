#pragma once
//#define ENABLE_DIAGNOSTICS true
extern Adafruit_SSD1306 display;
extern int button_up_state;
extern int button_down_state;
extern int button_left_state;
extern int button_right_state;
extern int button_ok_state;
extern int button_cancel_state;

#include <MenuSystem.h>
#include "hitb_leds.h"
#include "game_metro_defenders.h"
#include "hitb_agenda.h"
#include "hitb_secret.h"
#include "hitb_speakers.h"
#include "hitb_sponsors.h"

#ifdef ENABLE_DIAGNOSTICS
  #include "hitb_diagnostics.h"
#endif

int cur_pos = 0;
long inactivity_counter = millis();
long inactivity_timeout = 15000;

class MyRenderer : public MenuComponentRenderer {
public:
    void render(Menu const& menu) const {
      if(cur_pos > menu.get_num_components() ) cur_pos = menu.get_num_components()-1;
      if(0 > cur_pos) cur_pos = 0;
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(32,0);
      display.print("HITB2018AMS");
      /*display.print(" (");
      display.print(cur_pos);
      display.print(")");*/
      display.drawLine(0, 10, 128, 10, WHITE);
      
      for(int i= ((cur_pos/5) * 5), j=0; i <menu.get_num_components(); ++i, ++j){
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
MyRenderer my_renderer;

//Callback functionality
void on_nullcallback_selected(MenuComponent* p_menu_component) {
}

//Agenda Menu
void on_agenda_selected(MenuComponent* p_menu_component) {
  show_agenda();
}

//About Menu
void on_about_selected(MenuComponent* p_menu_component) {
  about_starfiled();
}

//Speakers Menu
void on_speakers_selected(MenuComponent* p_menu_component) {
  show_speaker();
}

//Sponsors Menu
void on_sponsors_selected(MenuComponent* p_menu_component) {
  show_sponsors();
   delay(200);  //Let buttons settle down
}

//Games Menu selection
void on_game_metro_defenders_selected(MenuComponent* p_menu_component){
  play_metro_defenders();
}

//Links Menu selection
void on_links_landing_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/gQCJ3N");
}

void on_source_code_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/jZBabq");
}

#ifdef ENABLE_DIAGNOSTICS
void on_diagnostics_selected(MenuComponent* p_menu_component){
  show_diagnostics();
}
#endif

// Menu variables
MenuSystem ms(my_renderer);
//Menu mm("");
MenuItem mm_mi_agenda("Agenda", &on_agenda_selected);
MenuItem mm_mi_speakers("Speakers", &on_speakers_selected);
MenuItem mm_mi_sponsors("Sponsors", &on_sponsors_selected);
//MenuItem mm_mi_notifications("Notifcations", &on_nullcallback_selected);
MenuItem mm_mi_secret("Secret Menu", &show_secret_menu);
MenuItem mm_mi_about("About", &on_about_selected);
#ifdef ENABLE_DIAGNOSTICS
MenuItem mm_mi_diagnostics("Diagnostics", &on_diagnostics_selected);
#endif

Menu mu_games("Games");
MenuItem mu_games_metro_defenders("Metro Defenders", &on_game_metro_defenders_selected);

Menu mu_links("Links");
MenuItem mu_links_landiing("HITB2018AMS", &on_links_landing_selected);
MenuItem mu_source_code("Source Code", &on_source_code_selected);

void setup_menus(){
    ms.get_root_menu().add_item(&mm_mi_agenda);
    ms.get_root_menu().add_item(&mm_mi_speakers);
    ms.get_root_menu().add_item(&mm_mi_sponsors);
    //ms.get_root_menu().add_item(&mm_mi_notifications);

    //Links
    ms.get_root_menu().add_menu(&mu_links);
    mu_links.add_item(&mu_links_landiing);
    mu_links.add_item(&mu_source_code);

    //Games
    ms.get_root_menu().add_menu(&mu_games);
    mu_games.add_item(&mu_games_metro_defenders);
   
    ms.get_root_menu().add_item(&mm_mi_secret);
    ms.get_root_menu().add_item(&mm_mi_about);
    #ifdef ENABLE_DIAGNOSTICS
    ms.get_root_menu().add_item(&mm_mi_diagnostics);
    #endif
}

void handle_buttons(){
  if(button_up_state || button_left_state){
    ms.prev();
    cur_pos -= 1;
    inactivity_counter = millis();
  }
  else if(button_down_state || button_right_state){
    ms.next();
    cur_pos += 1;
    inactivity_counter = millis();
  }
  else if(button_cancel_state){
    ms.back();
    cur_pos = 0;
    ms.reset();
    inactivity_counter = millis();
  }
  else if(button_ok_state){
    ms.select();
    inactivity_counter = millis();
  }
  if( (millis() - inactivity_counter ) < inactivity_timeout ) {
    wake_display();
    ms.display();
  }
}

void show_menus(){
  handle_buttons();
  if( (millis() - inactivity_counter ) > inactivity_timeout){
    sleep_display();
    return;
   }
    
  ms.display();
  delay_interuptable(130);
}

