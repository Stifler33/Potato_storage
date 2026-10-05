#include <Arduino.h>
#include <Stifler_i2c_display.h>
#include <EncButton.h>
#include <relay.h>

// Potato_Relay rl(1, 2, 3);
Stifler_display lcd;
#define SW 2
#define CLK 8
#define DT 7
EncButton eb(DT, CLK, SW);
float temp_potato = 5.6;
float sets_temp_up = 0.0;
uint8_t counter_menu = 0;
uint8_t counter_sets = 0;

int value_rl_1_up = 0;
int value_rl_1_down = 0;

enum{
  sets_up,
  sets_down
};

enum{
  menu_main,
  menu_rl_1,
  menu_rl_2,
  menu_rl_3
};

// enum{
//   unselect,
//   select_rl_1,
//   select_rl_2
// };

void select_sets(){
    switch(counter_sets)
  {
    case sets_up:
      lcd.show_indicator("up");
      break;
    case sets_down:
      lcd.show_indicator("down");
      break;
    default:
      break;
  }
}

void setup() {
  lcd.init();
  lcd.humidity = 53.2;
  lcd.temp = 23.6;
  Serial.begin(115200);
  lcd.show_main();
  // lcd.update_rl_1(5, 10);
  // lcd.show_main();
  // lcd.update_data();
}

bool flag_ = false;

void loop() {
  eb.tick();

  if (eb.hold()){
    counter_sets++;
    if (counter_sets > sets_down){
      counter_sets = sets_up;
    }
    if (counter_menu > menu_main){
      switch(counter_sets)
      {
        case sets_up:
          lcd.show_indicator("up");
          break;
        case sets_down:
          lcd.show_indicator("down");
          break;
        default:
          break;
      }
    }
  }
  
  if (eb.click()){
    counter_menu += 1;
    if(counter_menu > menu_rl_3){
      counter_menu = menu_main;
    }

    switch (counter_menu)
    {
    case menu_main:
      lcd.show_main();
      break;

    case menu_rl_1:
      lcd.show_rl_1();
      break;

    case menu_rl_2:
      lcd.show_rl_2();
      break;

    case menu_rl_3:
      lcd.show_rl_3();
      break;
    
    default:
      break;
    }
  }

  if (eb.turn()) {
    Serial.print("turn: dir ");
    Serial.print(eb.dir());
    Serial.print(", fast ");
    Serial.print(eb.fast());
    Serial.print(", counter ");
    Serial.println(eb.counter);
    switch (counter_menu)
    {
    case menu_rl_1:

      if (counter_sets == sets_up){
        value_rl_1_up += eb.dir();
        lcd.update_rl_1(value_rl_1_up);        
      }

      if (counter_sets == sets_down){
        value_rl_1_down += eb.dir();
        lcd.update_rl_1(0, value_rl_1_down);
      }
      break;
    
    default:
      break;
    }
  }

}