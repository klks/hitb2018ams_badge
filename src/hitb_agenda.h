extern Adafruit_SSD1306 display;
extern int button_up_state;
extern int button_down_state;
extern int button_ok_state;
extern int button_cancel_state;

int agenda_cur_pos = 0;

class MyAgendaRenderer : public MenuComponentRenderer {
public:
    void render(Menu const& menu) const {
      if(agenda_cur_pos > menu.get_num_components() ) agenda_cur_pos = menu.get_num_components()-1;
      if(0 > agenda_cur_pos) agenda_cur_pos = 0;

      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(40,0);
      display.print("Agenda");
      /*display.print(" (");
      display.print(cur_pos);
      display.print(")");*/
      display.drawLine(0, 10, 128, 10, WHITE);

      for(int i= ((agenda_cur_pos/5) * 5), j=0; i <menu.get_num_components(); ++i, ++j){
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
MyAgendaRenderer agenda_renderer;
MenuSystem *p_ms_agenda;



void agenda_handle_buttons(){
  if(button_up_state || button_left_state){
    p_ms_agenda->prev();
    agenda_cur_pos -= 1;
  }
  else if(button_right_state || button_down_state){
    p_ms_agenda->next();
    agenda_cur_pos += 1;
  }
  else if(button_cancel_state){
    p_ms_agenda->back();
    agenda_cur_pos = 0;
    p_ms_agenda->reset();
  }
  else if(button_ok_state){
    p_ms_agenda->select();
  }
  p_ms_agenda->display();
}

void on_agenda_null_selected(MenuComponent* p_menu_component) {
}

//Links Menu selection
void on_agenda_agenda_selected(MenuComponent* p_menu_component){
  display_qrcode("https://goo.gl/aG9iQC");
}
void show_agenda(){
  agenda_cur_pos = 0;
  MenuSystem ms_agenda(agenda_renderer);
  p_ms_agenda = &ms_agenda;

  //Time
  MenuItem mm_mi_date_12("_2018.04.12_", &on_agenda_null_selected);
  MenuItem mm_mi_date_13("_2018.04.13_", &on_agenda_null_selected);
  MenuItem mm_mi_atime0730_0900("__0730-0900__", &on_agenda_null_selected);
  MenuItem mm_mi_atime0800_0915("__0800-0915__", &on_agenda_null_selected);
  MenuItem mm_mi_atime0900_0915("__0900-0915__", &on_agenda_null_selected);
  MenuItem mm_mi_atime0915_1000("__0915-1000__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1000_1045("__1000-1045__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1045_1145("__1045-1145__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1045_1245("__1045-1245__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1130_1200("__1130-1200__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1145_1215("__1145-1215__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1145_1245("__1145-1245__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1200_1230("__1200-1230__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1215_1245("__1215-1245__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1230_1300("__1230-1300__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1245_1400("__1245-1400__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1400_1500("__1400-1500__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1400_1600("__1400-1600__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1500_1530("__1500-1530__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1500_1600("__1500-1600__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1530_1600("__1530-1600__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1600_1630("__1600-1630__", &on_agenda_null_selected);     
  MenuItem mm_mi_atime1630_1730("__1630-1730__", &on_agenda_null_selected);     
  MenuItem mm_mi_atime1630_1830("__1630-1830__", &on_agenda_null_selected); 
  MenuItem mm_mi_atime1630_1700("__1630-1700__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1700_1730("__1700-1730__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1730_1800("__1730-1800__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1730_1830("__1730-1830__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1800_1830("__1800-1830__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1830_1900("__1830-1900__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1830_2200("__1830-2200__", &on_agenda_null_selected);
  MenuItem mm_mi_atime1830_2030("__1830-2030__", &on_agenda_null_selected);
        
  //date12
  ms_agenda.get_root_menu().add_item(&mm_mi_date_12);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime0730_0900);
  MenuItem mm_mi_d12a00("Registration", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a00);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime0900_0915);
  MenuItem mm_mi_d12a01("Welcome Address", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a01);
  
  ms_agenda.get_root_menu().add_item(&mm_mi_atime0915_1000);
  MenuItem mm_mi_d12a02("Keynote 1", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a02);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1000_1045);
  MenuItem mm_mi_d12a03("Coffee Break", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a03);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1045_1145);
  MenuItem mm_mi_d12a04("T1: Sneaky Elements", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a04);
  MenuItem mm_mi_d12a05("T2: Smashing ETH", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a05);
  MenuItem mm_mi_d12a06("C: Kernel OBJ Absuse", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a06);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1045_1245);
  MenuItem mm_mi_d12a07("L: Intro SDR", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a07);
  
  ms_agenda.get_root_menu().add_item(&mm_mi_atime1145_1215);
  MenuItem mm_mi_d12a08("C: Stegano", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a08);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1145_1245);
  MenuItem mm_mi_d12a09("T1: Brida", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a09);
  MenuItem mm_mi_d12a10("T2: .NET CLR", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a10);
      
  ms_agenda.get_root_menu().add_item(&mm_mi_atime1215_1245);
  MenuItem mm_mi_d12a11("C: Rouge Hosting", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a11);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1245_1400);
  MenuItem mm_mi_d12a12("Lunch Break", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a12);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1400_1500);
  MenuItem mm_mi_d12a13("T1: Ghost Tunnel", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a13);
  MenuItem mm_mi_d12a14("T2: Intel Buildings", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a14);
  MenuItem mm_mi_d12a15("C: ISOLATED DC", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a15);
  
  ms_agenda.get_root_menu().add_item(&mm_mi_atime1400_1600);
  MenuItem mm_mi_d12a16("L: ARM ASM", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a16);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1500_1530);
  MenuItem mm_mi_d12a17("C: Keynterceptor", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a17);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1500_1600);
  MenuItem mm_mi_d12a18("T1: Ticket2Ride", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a18);
  MenuItem mm_mi_d12a19("T2: Invoke-Dosfucation", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a19);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1530_1600);
  MenuItem mm_mi_d12a20("C: DGGING IOT", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a20);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1600_1630);
  MenuItem mm_mi_d12a21("Coffee Break", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a21);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1630_1730);
  MenuItem mm_mi_d12a22("T1: Eating Apple", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a22);
  MenuItem mm_mi_d12a23("T2: Mirror Mirror", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a23);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1630_1730);
  MenuItem mm_mi_d12a24("C: Modern Pentest", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a24);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1700_1730);
  MenuItem mm_mi_d12a25("C: Quantum", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a25);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1730_1830);
  MenuItem mm_mi_d12a26("T1: Fuzzing JS", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a26);
  MenuItem mm_mi_d12a27("T2: The Odd One", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a27);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1800_1830);
  MenuItem mm_mi_d12a28("C: IOT Speakers", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a28);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1830_2200);
  MenuItem mm_mi_d12a29("Facebook", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a29);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1830_2030);
  MenuItem mm_mi_d12a30("HITB Party", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d12a30);

 
  //date13
  ms_agenda.get_root_menu().add_item(&mm_mi_date_13);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime0800_0915);
  MenuItem mm_mi_d13a00("Registration", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a00);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime0915_1000);
  MenuItem mm_mi_d13a01("Keynote 2", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a01);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1000_1045);
  MenuItem mm_mi_d13a02("Coffee Break", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a02);
  
  ms_agenda.get_root_menu().add_item(&mm_mi_atime1045_1145);
  MenuItem mm_mi_d13a03("T1: VBA/Sandbox", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a03);
  MenuItem mm_mi_d13a04("T2: Mallet", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a04);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1045_1245);
  MenuItem mm_mi_d13a05("L: Kernel_Task Port", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a05);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1130_1200);
  MenuItem mm_mi_d13a06("C: Darkness", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a06);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1145_1245);
  MenuItem mm_mi_d13a07("T1: Mind The Gap", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a07);
  MenuItem mm_mi_d13a08("T2: PWN win Kernel", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a08);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1200_1230);
  MenuItem mm_mi_d13a09("C: EasyROP", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a09);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1230_1300);
  MenuItem mm_mi_d13a10("C: PRODSEC", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a10);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1245_1400);
  MenuItem mm_mi_d13a11("Lunch", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a11);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1400_1500);
  MenuItem mm_mi_d13a12("T1: BICHO", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a12);
  MenuItem mm_mi_d13a13("T2: Quantitative", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a13);
  MenuItem mm_mi_d13a14("C: PyREBOX", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a14);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1400_1600);
  MenuItem mm_mi_d13a15("L: Mal Domain", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a15);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1500_1600);
  MenuItem mm_mi_d13a16("T1: CallmeMaybe", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a16);
  MenuItem mm_mi_d13a17("T2: Seems Exp", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a17);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1500_1530);
  MenuItem mm_mi_d13a18("C: TBA", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a18);
 
  ms_agenda.get_root_menu().add_item(&mm_mi_atime1530_1600);
  MenuItem mm_mi_d13a19("C: Call Doctor", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a19);
  
  ms_agenda.get_root_menu().add_item(&mm_mi_atime1600_1630);
  MenuItem mm_mi_d13a20("Coffee Break", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a20);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1630_1730);
  MenuItem mm_mi_d13a21("T1: WMI", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a21);
  MenuItem mm_mi_d13a22("T2: Suborigins", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a22);

  ms_agenda.get_root_menu().add_item(&mm_mi_atime1730_1830);
  MenuItem mm_mi_d13a23("Closing Keynote", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a23);
  ms_agenda.get_root_menu().add_item(&mm_mi_atime1830_1900);
  MenuItem mm_mi_d13a24("Closing Ceremony", &on_agenda_agenda_selected);
  ms_agenda.get_root_menu().add_item(&mm_mi_d13a24);
             
  ms_agenda.display();
  delay(200);   //wait for button press to settle down
  while(delay_interuptable(130)){
    agenda_handle_buttons();
  }
}
