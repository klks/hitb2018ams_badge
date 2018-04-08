#pragma once
extern Adafruit_SSD1306 display;
extern int button_up_state;
extern int button_down_state;
extern int button_ok_state;
extern int button_cancel_state;

int sponsor_cur_pos = 0;

class MySponsorRenderer : public MenuComponentRenderer {
public:
    void render(Menu const& menu) const {
      if(sponsor_cur_pos > menu.get_num_components() ) sponsor_cur_pos = menu.get_num_components()-1;
      if(0 > sponsor_cur_pos) sponsor_cur_pos = 0;
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(40,0);
      display.print("Sponsors");
      /*display.print(" (");
      display.print(cur_pos);
      display.print(")");*/
      display.drawLine(0, 10, 128, 10, WHITE);
      
      for(int i= ((sponsor_cur_pos/5) * 5), j=0; i <menu.get_num_components(); ++i, ++j){
        MenuComponent const* cp_m_comp = menu.get_menu_component(i);
        if(cp_m_comp->is_current())
        {
          display.setCursor(0, 15 + (j*10));
          display.print(">");
        }
        display.setCursor(10, 15 + (j*10));
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
MySponsorRenderer sponsor_renderer;
MenuSystem *p_ms_sponsor;

void sponsor_handle_buttons(){
  if(button_up_state || button_left_state){
    p_ms_sponsor->prev();
    sponsor_cur_pos -= 1;
  }
  else if(button_right_state || button_down_state){
    p_ms_sponsor->next();
    sponsor_cur_pos += 1;
  }
  else if(button_cancel_state){
    p_ms_sponsor->back();
    sponsor_cur_pos = 0;
    p_ms_sponsor->reset();
  }
  else if(button_ok_state){
    p_ms_sponsor->select();
  }
  p_ms_sponsor->display();
}

void on_sponsor_null_selected(MenuComponent* p_menu_component) {
}

void show_sponsors(){
  sponsor_cur_pos = 0;
  MenuSystem ms_sponsor(sponsor_renderer);
  p_ms_sponsor = &ms_sponsor;

  //Event Organizer
  MenuItem mm_mi_null_1("_Organizer_", &on_sponsor_null_selected);
  MenuItem mm_mi_hitb("HITB", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_1);
  ms_sponsor.get_root_menu().add_item(&mm_mi_hitb);

  //Support and Endorsed By
  MenuItem mm_mi_null_2("_Endorsed by_", &on_sponsor_null_selected);
  MenuItem mm_mi_hsd("HSD", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_2);
  ms_sponsor.get_root_menu().add_item(&mm_mi_hsd);

  //Gold Sponsors
  MenuItem mm_mi_null_3("_Gold Sponsors_", &on_sponsor_null_selected);
  MenuItem mm_mi_ms("Microsoft", &on_sponsor_null_selected);
  MenuItem mm_mi_dm("Darkmatter", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_3);
  ms_sponsor.get_root_menu().add_item(&mm_mi_ms);
  ms_sponsor.get_root_menu().add_item(&mm_mi_dm);

  //Silver Sponsors
  MenuItem mm_mi_null_4("_Silver Sponsors_", &on_sponsor_null_selected);
  MenuItem mm_mi_ar("Applied Risk", &on_sponsor_null_selected);
  MenuItem mm_mi_bs("Beyond Security", &on_sponsor_null_selected);
  MenuItem mm_mi_fb("Facebook", &on_sponsor_null_selected);
  MenuItem mm_mi_gl("Google", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_4);
  ms_sponsor.get_root_menu().add_item(&mm_mi_ar);
  ms_sponsor.get_root_menu().add_item(&mm_mi_bs);
  ms_sponsor.get_root_menu().add_item(&mm_mi_fb);
  ms_sponsor.get_root_menu().add_item(&mm_mi_gl);

  //Commsec Sponsor
  MenuItem mm_mi_null_5("_Commsec Sponsor_", &on_sponsor_null_selected);
  MenuItem mm_mi_ns("NIXU Security", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_5);
  ms_sponsor.get_root_menu().add_item(&mm_mi_ns);

  //CTF Main Sponsor
  MenuItem mm_mi_null_6("_CTF Main Sponsor_", &on_sponsor_null_selected);
  MenuItem mm_mi_su("S-Unit", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_6);
  ms_sponsor.get_root_menu().add_item(&mm_mi_su);

  //CTF Prize Sponsor
  MenuItem mm_mi_null_7("_CTF Prize Sponsor_", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_7);
  ms_sponsor.get_root_menu().add_item(&mm_mi_dm); //Darkmatter repeat
  
  //Bronze Sponsor
  MenuItem mm_mi_null_8("_Bronze Sponsor_", &on_sponsor_null_selected);
  MenuItem mm_mi_zd("Zerodium", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_8);
  ms_sponsor.get_root_menu().add_item(&mm_mi_zd);

  //Connectivity Partner
  MenuItem mm_mi_null_9("_Connectivity Partners_", &on_sponsor_null_selected);
  MenuItem mm_mi_an("Aruba", &on_sponsor_null_selected);
  MenuItem mm_mi_jn("Juniper", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_9);
  ms_sponsor.get_root_menu().add_item(&mm_mi_an);
  ms_sponsor.get_root_menu().add_item(&mm_mi_jn);
  
  //Media Partners
  MenuItem mm_mi_null_10("_Media Partners_", &on_sponsor_null_selected);
  MenuItem mm_mi_vi("Virtually Informed", &on_sponsor_null_selected);
  MenuItem mm_mi_cm("CISO Mag", &on_sponsor_null_selected);
  MenuItem mm_mi_mh("Mundo Hacker", &on_sponsor_null_selected);
  MenuItem mm_mi_or("O'Reilly", &on_sponsor_null_selected);
  MenuItem mm_mi_cw("Computerworld", &on_sponsor_null_selected);
  MenuItem mm_mi_ww("Webwereld", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_10);
  ms_sponsor.get_root_menu().add_item(&mm_mi_vi);
  ms_sponsor.get_root_menu().add_item(&mm_mi_cm);
  ms_sponsor.get_root_menu().add_item(&mm_mi_mh);
  ms_sponsor.get_root_menu().add_item(&mm_mi_or);
  ms_sponsor.get_root_menu().add_item(&mm_mi_cw);
  ms_sponsor.get_root_menu().add_item(&mm_mi_ww);
  
  //Additional Support
  MenuItem mm_mi_null_11("_Extra Support_", &on_sponsor_null_selected);
  MenuItem mm_mi_nv("nVIDIA", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_11);
  ms_sponsor.get_root_menu().add_item(&mm_mi_nv);

  //Friends of HITB
  MenuItem mm_mi_null_12("_Friends of HITB_", &on_sponsor_null_selected);
  MenuItem mm_mi_sh("Security Happenings", &on_sponsor_null_selected);
  MenuItem mm_mi_nsp("No Starch Press", &on_sponsor_null_selected);
  MenuItem mm_mi_gh("Garage4Hackers", &on_sponsor_null_selected);
  MenuItem mm_mi_wc("WICS", &on_sponsor_null_selected);
  MenuItem mm_mi_pl("peerlyst", &on_sponsor_null_selected);
  MenuItem mm_mi_vl("Vulnerability Labs", &on_sponsor_null_selected);
  MenuItem mm_mi_ow("OWASP", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_12);
  ms_sponsor.get_root_menu().add_item(&mm_mi_sh);
  ms_sponsor.get_root_menu().add_item(&mm_mi_nsp);
  ms_sponsor.get_root_menu().add_item(&mm_mi_gh);
  ms_sponsor.get_root_menu().add_item(&mm_mi_wc);
  ms_sponsor.get_root_menu().add_item(&mm_mi_pl);
  ms_sponsor.get_root_menu().add_item(&mm_mi_vl);
  ms_sponsor.get_root_menu().add_item(&mm_mi_ow);

  //Partner Events
  MenuItem mm_mi_null_13("_Partner Events_", &on_sponsor_null_selected);
  MenuItem mm_mi_bx("BEVX", &on_sponsor_null_selected);
  MenuItem mm_mi_ic("infosec city", &on_sponsor_null_selected);
  MenuItem mm_mi_bhd("Blackhoodie", &on_sponsor_null_selected);
  MenuItem mm_mi_bsb("BSides Budapest", &on_sponsor_null_selected);
  MenuItem mm_mi_nc("Nullcon", &on_sponsor_null_selected);
  MenuItem mm_mi_cc("Confidence", &on_sponsor_null_selected);
  MenuItem mm_mi_44("44 Con", &on_sponsor_null_selected);
  MenuItem mm_mi_ss("SyScan", &on_sponsor_null_selected);
  MenuItem mm_mi_hc("Hitcon", &on_sponsor_null_selected);
  MenuItem mm_mi_phd("PHD", &on_sponsor_null_selected);
  MenuItem mm_mi_tc("Troopers", &on_sponsor_null_selected);
  MenuItem mm_mi_zn("Zero Nights", &on_sponsor_null_selected);
  MenuItem mm_mi_cb("Code Blue", &on_sponsor_null_selected);
  ms_sponsor.get_root_menu().add_item(&mm_mi_null_13);
  ms_sponsor.get_root_menu().add_item(&mm_mi_bx);
  ms_sponsor.get_root_menu().add_item(&mm_mi_ic);
  ms_sponsor.get_root_menu().add_item(&mm_mi_bhd);
  ms_sponsor.get_root_menu().add_item(&mm_mi_bsb);
  ms_sponsor.get_root_menu().add_item(&mm_mi_nc);
  ms_sponsor.get_root_menu().add_item(&mm_mi_cc);
  ms_sponsor.get_root_menu().add_item(&mm_mi_44);
  ms_sponsor.get_root_menu().add_item(&mm_mi_ss);
  ms_sponsor.get_root_menu().add_item(&mm_mi_hc);
  ms_sponsor.get_root_menu().add_item(&mm_mi_phd);
  ms_sponsor.get_root_menu().add_item(&mm_mi_tc);
  ms_sponsor.get_root_menu().add_item(&mm_mi_zn);
  ms_sponsor.get_root_menu().add_item(&mm_mi_cb);

  ms_sponsor.display();
  delay(200);   //wait for button press to settle down
  while(delay_interuptable(130)){
    sponsor_handle_buttons();
  }
}
