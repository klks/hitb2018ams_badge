extern Adafruit_SSD1306 display;
extern int button_up_state;
extern int button_down_state;
extern int button_ok_state;
extern int button_cancel_state;

int speaker_cur_pos = 0;

class MySpeakerRenderer : public MenuComponentRenderer {
public:
    void render(Menu const& menu) const {
      if(speaker_cur_pos > menu.get_num_components() ) speaker_cur_pos = menu.get_num_components()-1;
      if(0 > speaker_cur_pos) speaker_cur_pos = 0;

      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(40,0);
      display.print("Speakers");
      /*display.print(" (");
      display.print(cur_pos);
      display.print(")");*/
      display.drawLine(0, 10, 128, 10, WHITE);

      for(int i= ((speaker_cur_pos/5) * 5), j=0; i <menu.get_num_components(); ++i, ++j){
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

MySpeakerRenderer speaker_renderer;
MenuSystem *p_ms_speaker;

void speaker_handle_buttons(){
  if(button_up_state || button_left_state){
    p_ms_speaker->prev();
    speaker_cur_pos -= 1;
  }
  else if(button_right_state || button_down_state){
    p_ms_speaker->next();
    speaker_cur_pos += 1;
  }
  else if(button_cancel_state){
    p_ms_speaker->back();
    speaker_cur_pos = 0;
    p_ms_speaker->reset();
  }
  else if(button_ok_state){
    p_ms_speaker->select();
  }
  p_ms_speaker->display();
}

void on_speaker_null_selected(MenuComponent* p_menu_component) {
}

//Links from http://conference.hitb.org/hitbsecconf2018ams/conference/
void on_speaker_spk00_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/t6Rj2i");
}

void on_speaker_spk01_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/4JXixp");
}

void on_speaker_spk02_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/FsPndr");
}

void on_speaker_spk03_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/Mu9rYZ");
}

void on_speaker_spk04_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/jMKepL");
}

void on_speaker_spk05_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/3rx4gw");
}

void on_speaker_spk06_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/SBUJKo");
}

void on_speaker_spk07_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/6iVdTp");
}

void on_speaker_spk08_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/o9eJCm");
}

void on_speaker_spk09_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/7RnpND");
}

void on_speaker_spk10_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/ToUg6z");
}

void on_speaker_spk11_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/zJumdu");
}

void on_speaker_spk12_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/NsEgYV");
}

void on_speaker_spk13_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/ySKpCz");
}

void on_speaker_spk14_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/vLxsxG");
}

void on_speaker_spk15_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/52TqPt");
}

void on_speaker_spk16_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/JSwo9G");
}

void on_speaker_spk17_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/sNNsvG");
}

void on_speaker_spk18_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/zrpqoF");
}

void on_speaker_spk19_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/UAuBCs");
}

void on_speaker_spk20_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/zgMKdm");
}

void on_speaker_spk21_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/k2MCVR");
}

void on_speaker_spk22_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/MzvM26");
}

void on_speaker_spk23_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/BA8fWH");
}

void on_speaker_spk24_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/6mNMmA");
}

void on_speaker_spk25_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/hiavSQ");
}

void on_speaker_spk26_selected(MenuComponent* p_menu_component){
  display_qrcode("goo.gl/QDLFZ3");
}

void on_speaker_spk27_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/FSL6Vr");
}

void on_speaker_spk28_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/QJiTDc");
}

void on_speaker_spk29_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/P6UWrE");
}

void on_speaker_spk30_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/Ea6opM");
}

void on_speaker_spk31_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/NfzEi7");
}

void on_speaker_spk32_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/zqaVWg");
}

void on_speaker_spk33_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/Haa8sF");
}

void on_speaker_spk34_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/Ktwn39");
}

void on_speaker_spk35_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/tWiASe");
}

void on_speaker_spk36_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/tWiASe");
}

void on_speaker_spk37_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/zGqjKd");
}

void on_speaker_spk38_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/x6y2ph");
}

void on_speaker_spk39_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/Bcg3n1");
}

void on_speaker_spk40_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/DmiRux");
}

void on_speaker_spk41_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/bU8wrw");
}

void on_speaker_spk42_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/rcnWgD");
}

void on_speaker_spk43_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/cbWpqo");
}

void on_speaker_spk44_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/waKqv3");
}

void on_speaker_spk45_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/qq5btA");
}

void on_speaker_spk46_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/TC34xn");
}

void on_speaker_spk47_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/8kUMvK");
}

void on_speaker_spk48_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/ZLaQD5");
}

void on_speaker_spk49_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/yviW5a");
}

void on_speaker_spk50_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/mA8d4k");
}

void on_speaker_spk51_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/mpCER3");
}

void on_speaker_spk52_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/euphuk");
}

void on_speaker_spk53_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/Bsdybr");
}

void on_speaker_spk54_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/Dr1bPa");
}

void on_speaker_spk55_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/CRme9j");
}

void on_speaker_spk56_selected(MenuComponent* p_menu_component){
  display_qrcode("goo.gl/g3vtgF");
}

void on_speaker_spk57_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/FhQiAT");
}

void on_speaker_spk58_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/icBVPc");
}

void on_speaker_spk59_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/Worvwh");
}

void on_speaker_spk60_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/KWjZmW");
}

void on_speaker_spk61_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/Ho5mnW");
}

void on_speaker_spk62_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/5ifL5Q");
}

void on_speaker_spk63_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/2a5B2z");
}

void on_speaker_spk64_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/j53rLX");
}

void on_speaker_spk65_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/JhF75z");
}

void on_speaker_spk66_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/5Lp3sr");
}

void on_speaker_spk67_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/4sYbYg");
}

void on_speaker_spk68_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/eN4Jcr");
}

void on_speaker_spk69_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/BmRGVi");
}

void on_speaker_spk70_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/J7Pn2Y");
}

// Names from http://conference.hitb.org/hitbsecconf2018ams/conference/
void show_speaker(){
  speaker_cur_pos = 0;
  MenuSystem ms_speaker(speaker_renderer);
  p_ms_speaker = &ms_speaker;

  MenuItem mm_mi_spk00("_michel-van-eeten", &on_speaker_spk00_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk00);
  MenuItem mm_mi_spk01("_marion-marschalek", &on_speaker_spk01_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk01);
  MenuItem mm_mi_spk02("_jennifer-leggio", &on_speaker_spk02_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk02);
  MenuItem mm_mi_spk03("_amber-baldet", &on_speaker_spk03_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk03);
  MenuItem mm_mi_spk04("_jorge-cuadrado-saez", &on_speaker_spk04_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk04);
  MenuItem mm_mi_spk05("_lukas-weichselbaum", &on_speaker_spk05_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk05);
  MenuItem mm_mi_spk06("_michele-spagnuolo", &on_speaker_spk06_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk06);
  MenuItem mm_mi_spk07("_philip-tsukerman", &on_speaker_spk07_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk07);
  MenuItem mm_mi_spk08("_fernando-arnaboldi", &on_speaker_spk08_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk08);
  MenuItem mm_mi_spk09("_alfonso-munoz", &on_speaker_spk09_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk09);
  MenuItem mm_mi_spk10("_bai-guangdong", &on_speaker_spk10_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk10);
  MenuItem mm_mi_spk11("_david-rodriguez", &on_speaker_spk11_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk11);
  MenuItem mm_mi_spk12("_sheila-ayelen-berta", &on_speaker_spk12_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk12);
  MenuItem mm_mi_spk13("_claudio-caracciolo", &on_speaker_spk13_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk13);
  MenuItem mm_mi_spk14("_zhang-qing", &on_speaker_spk14_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk14);
  MenuItem mm_mi_spk15("_rancho-han", &on_speaker_spk15_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk15);
  MenuItem mm_mi_spk16("_jakob-lell", &on_speaker_spk16_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk16);
  MenuItem mm_mi_spk17("_karsten-nohl", &on_speaker_spk17_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk17);
  MenuItem mm_mi_spk18("_jonathan-levin", &on_speaker_spk18_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk18);
  MenuItem mm_mi_spk19("_rogan-dawes", &on_speaker_spk19_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk19);
  MenuItem mm_mi_spk20("_aviv-grafi", &on_speaker_spk20_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk20);
  MenuItem mm_mi_spk21("_amit-dori", &on_speaker_spk21_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk21);
  MenuItem mm_mi_spk22("_yong-yang", &on_speaker_spk22_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk22);
  MenuItem mm_mi_spk23("_mayra-fuentes", &on_speaker_spk23_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk23);
  MenuItem mm_mi_spk24("_lion-gu", &on_speaker_spk24_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk24);
  MenuItem mm_mi_spk25("_fyodor-yarochkin", &on_speaker_spk25_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk25);
  MenuItem mm_mi_spk26("_piergiovanni-cipolloni", &on_speaker_spk26_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk26);
  MenuItem mm_mi_spk27("_eugene-neyolov", &on_speaker_spk27_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk27);
  MenuItem mm_mi_spk28("_hongjian-cao", &on_speaker_spk28_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk28);
  MenuItem mm_mi_spk29("_yang-song", &on_speaker_spk29_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk29);
  MenuItem mm_mi_spk30("_jeonghoon-shin", &on_speaker_spk30_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk30);
  MenuItem mm_mi_spk31("_areum-lee", &on_speaker_spk31_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk31);
  MenuItem mm_mi_spk32("_jie-fu", &on_speaker_spk32_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk32);
  MenuItem mm_mi_spk33("_chaoran-wang", &on_speaker_spk33_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk33);
  MenuItem mm_mi_spk34("_yong-wang", &on_speaker_spk34_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk34);
  MenuItem mm_mi_spk35("_xiaolong-bai", &on_speaker_spk35_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk35);
  MenuItem mm_mi_spk36("_xiaolong-bai", &on_speaker_spk36_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk36);
  MenuItem mm_mi_spk37("_yunding-jian", &on_speaker_spk37_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk37);
  MenuItem mm_mi_spk38("_daniel-bohannon", &on_speaker_spk38_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk38);
  MenuItem mm_mi_spk39("_vladimir-kropotov", &on_speaker_spk39_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk39);
  MenuItem mm_mi_spk40("_jingchuan-chen", &on_speaker_spk40_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk40);
  MenuItem mm_mi_spk41("_yuxiang-li", &on_speaker_spk41_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk41);
  MenuItem mm_mi_spk42("_huiyu-wu", &on_speaker_spk42_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk42);
  MenuItem mm_mi_spk43("_kunzhe-chai", &on_speaker_spk43_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk43);
  MenuItem mm_mi_spk44("_jun-li", &on_speaker_spk44_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk44);
  MenuItem mm_mi_spk45("_maria-azeria-markst", &on_speaker_spk45_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk45);
  MenuItem mm_mi_spk46("_yu-hong", &on_speaker_spk46_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk46);
  MenuItem mm_mi_spk47("_shikang-xing", &on_speaker_spk47_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk47);
  MenuItem mm_mi_spk48("_federico-dotta", &on_speaker_spk48_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk48);
  MenuItem mm_mi_spk49("_didier-stevens", &on_speaker_spk49_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk49);
  MenuItem mm_mi_spk50("_bernhard-mueller", &on_speaker_spk50_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk50);
  MenuItem mm_mi_spk51("_don-bailey", &on_speaker_spk51_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk51);
  MenuItem mm_mi_spk52("_daniel-uroz", &on_speaker_spk52_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk52);
  MenuItem mm_mi_spk53("_sarah-brown", &on_speaker_spk53_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk53);
  MenuItem mm_mi_spk54("_ricardo-j-rodriguez", &on_speaker_spk54_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk54);
  MenuItem mm_mi_spk55("_thomas-debize", &on_speaker_spk55_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk55);
  MenuItem mm_mi_spk56("_jeremy-brown", &on_speaker_spk56_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk56);
  MenuItem mm_mi_spk57("_ofir-kamil", &on_speaker_spk57_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk57);
  MenuItem mm_mi_spk58("_asaf-cohen", &on_speaker_spk58_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk58);
  MenuItem mm_mi_spk59("_stephen-hilt", &on_speaker_spk59_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk59);
  MenuItem mm_mi_spk60("_ofir-arkin", &on_speaker_spk60_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk60);
  MenuItem mm_mi_spk61("_niels-van-dijkhuizen", &on_speaker_spk61_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk61);
  MenuItem mm_mi_spk62("_yann-allain", &on_speaker_spk62_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk62);
  MenuItem mm_mi_spk63("_steffen-wendzel", &on_speaker_spk63_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk63);
  MenuItem mm_mi_spk64("_xabier-ugarte-pedrero", &on_speaker_spk64_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk64);
  MenuItem mm_mi_spk65("_kyeong-joo-jung", &on_speaker_spk65_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk65);
  MenuItem mm_mi_spk66("_kelvin-wong", &on_speaker_spk66_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk66);
  MenuItem mm_mi_spk67("_ian-kronquist", &on_speaker_spk67_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk67);
  MenuItem mm_mi_spk68("_saif-elsherei", &on_speaker_spk68_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk68);
  MenuItem mm_mi_spk69("_dhia-mahjoub", &on_speaker_spk69_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk69);
  MenuItem mm_mi_spk70("_josh-stroschein", &on_speaker_spk70_selected);
  ms_speaker.get_root_menu().add_item(&mm_mi_spk70);

  ms_speaker.display();
  delay(200);   //wait for button press to settle down
  while(delay_interuptable(130)){
    speaker_handle_buttons();
  }
}
