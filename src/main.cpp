#include <Arduino.h>
#include <Stifler_i2c_display.h>
#include <EncButton.h>
#include <relay.h>
#include <EEPROM.h>
#include <Adafruit_AHTX0.h>
#include <GTimer.h>

GTimer<millis> delay_aht(500, true, GTMode::Interval);

Adafruit_AHTX0 aht;

// Potato_Relay rl(1, 2, 3);

#define ADR_RL_1_UP 0
#define ADR_RL_1_DOWN 2
#define ADR_RL_2_UP 4
#define ADR_RL_2_DOWN 6
#define ADR_RL_3_UP 8
#define ADR_RL_3_DOWN 10

Stifler_display lcd;
#define SW 2
#define CLK 8
#define DT 7

EncButton eb(DT, CLK, SW);
float temp_potato = 5.6;
float sets_temp_up = 0.0;

uint8_t counter_menu = 0;
uint8_t counter_sets = 0;

int16_t value_rl_1_up = 0;
int16_t value_rl_1_down = 0;

int16_t value_rl_2_up = 0;
int16_t value_rl_2_down = 0;

int16_t value_rl_3_up = 0;
int16_t value_rl_3_down = 0;

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
  aht.begin();

  EEPROM.get(ADR_RL_1_UP, value_rl_1_up);
  EEPROM.get(ADR_RL_1_DOWN, value_rl_1_down);

  EEPROM.get(ADR_RL_2_UP, value_rl_2_up);
  EEPROM.get(ADR_RL_2_DOWN, value_rl_2_down);

  EEPROM.get(ADR_RL_3_UP, value_rl_3_up);
  EEPROM.get(ADR_RL_3_DOWN, value_rl_3_down);
}

bool flag_ = false;

void loop() {
  eb.tick();

  if (counter_menu == menu_main){
    lcd.update_data();
    if (delay_aht){
      sensors_event_t humidity, temp;
      aht.getEvent(&humidity, &temp);

      lcd.temp = temp.temperature;
      lcd.humidity = humidity.relative_humidity;
    }
  }

  if (eb.hold()){
    counter_sets++;
    if (counter_sets > sets_down){
      counter_sets = sets_up;
    }
    if (counter_menu > menu_main){
      select_sets();
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
      EEPROM.put(ADR_RL_3_UP, value_rl_3_up);
      EEPROM.put(ADR_RL_3_DOWN, value_rl_3_down);
      lcd.show_main();
      break;

    case menu_rl_1:
      lcd.show_rl_1();
      select_sets();
      lcd.update_rl(value_rl_1_up, value_rl_1_down);
      break;

    case menu_rl_2:
      EEPROM.put(ADR_RL_1_UP, value_rl_1_up);
      EEPROM.put(ADR_RL_1_DOWN, value_rl_1_down);
      lcd.show_rl_2();
      select_sets();
      lcd.update_rl(value_rl_2_up, value_rl_2_down);
      break;

    case menu_rl_3:
      EEPROM.put(ADR_RL_2_UP, value_rl_2_up);
      EEPROM.put(ADR_RL_2_DOWN, value_rl_2_down);
      lcd.show_rl_3();
      select_sets();
      lcd.update_rl(value_rl_3_up, value_rl_3_down);
      break;
    
    default:
      break;
    }
  }

  if (eb.turn()) {

    if (counter_sets == sets_up){

      if (counter_menu == menu_rl_1){
        value_rl_1_up += eb.dir();
        lcd.update_rl(value_rl_1_up); 
      }

      if (counter_menu == menu_rl_2){
        value_rl_2_up += eb.dir();
        lcd.update_rl(value_rl_2_up); 
      }

      if (counter_menu == menu_rl_3){
        value_rl_3_up += eb.dir();
        lcd.update_rl(value_rl_3_up); 
      }

    }

    if (counter_sets == sets_down){

      if (counter_menu == menu_rl_1){
        value_rl_1_down += eb.dir();
        lcd.update_rl(0, value_rl_1_down);
      }

      if (counter_menu == menu_rl_2){
        value_rl_2_down += eb.dir();
        lcd.update_rl(0, value_rl_2_down);
      }

      if (counter_menu == menu_rl_3){
        value_rl_3_down += eb.dir();
        lcd.update_rl(0, value_rl_3_down);
      }

    }

    if (value_rl_1_up < 0){
      value_rl_1_up = 0;
    }
    if (value_rl_2_up < 0){
      value_rl_2_up = 0;
    }
    if (value_rl_3_up < 0){
      value_rl_3_up = 0;
    }

    if (value_rl_1_down < 0){
      value_rl_1_down = 0;
    }
    if (value_rl_2_down < 0){
      value_rl_2_down = 0;
    }
    if (value_rl_3_down < 0){
      value_rl_3_down = 0;
    }

  }
}