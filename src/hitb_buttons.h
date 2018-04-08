//Buttons
#define button_up_pin PB4
#define button_down_pin PB3
#define button_left_pin PB5
#define button_right_pin PA15
#define button_ok_pin PA0
#define button_cancel_pin PA2

int button_up_state = LOW;
long button_up_ldt=millis();
int button_down_state = LOW;
long button_down_ldt=millis();
int button_left_state = LOW;
long button_left_ldt=millis();
int button_right_state = LOW;
long button_right_ldt=millis();
int button_ok_state = LOW;
long button_ok_ldt=millis();
int button_cancel_state = LOW;
long button_cancel_ldt=millis();

long debounceDelay = 50;

void button_ok_interrupt(){
  if( (millis() - button_ok_ldt ) > debounceDelay){
    button_ok_state = !button_ok_state;
    button_ok_ldt = millis();
  }
}

void button_cancel_interrupt(){
  if( (millis() - button_cancel_ldt ) > debounceDelay){
    button_cancel_state = !button_cancel_state;
    button_cancel_ldt = millis();
  }
}

void button_down_interrupt(){
  if( (millis() - button_down_ldt ) > debounceDelay){
    button_down_state = !button_down_state;
    button_down_ldt = millis();
  }
}

void button_up_interrupt(){
  if( (millis() - button_up_ldt ) > debounceDelay){
    button_up_state = !button_up_state;
    button_up_ldt = millis();
  }
}

void button_left_interrupt(){
  if( (millis() - button_left_ldt ) > debounceDelay){
    button_left_state = !button_left_state;
    button_left_ldt = millis();
  }
}

void button_right_interrupt(){
  if( (millis() - button_right_ldt ) > debounceDelay){
    button_right_state = !button_right_state;
    button_right_ldt = millis();
  }
}

void setup_buttons(){
  pinMode(button_up_pin, INPUT_PULLUP);
  pinMode(button_down_pin, INPUT_PULLUP);
  pinMode(button_left_pin, INPUT_PULLUP);
  pinMode(button_right_pin, INPUT_PULLUP);
  pinMode(button_ok_pin, INPUT_PULLDOWN);
  pinMode(button_cancel_pin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(button_up_pin), button_up_interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button_down_pin), button_down_interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button_left_pin), button_left_interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button_right_pin), button_right_interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button_ok_pin), button_ok_interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button_cancel_pin), button_cancel_interrupt, CHANGE);
}
