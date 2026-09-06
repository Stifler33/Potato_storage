#include <Arduino.h>
#include <Stifler_i2c_display.h>
#include <EncButton.h>

Stifler_display lcd;

#define SW 2
#define CLK 8
#define DT 7
EncButton eb(DT, CLK, SW);
float temp_potato = 5.6;
float sets_temp_up = 0.0;
uint8_t counter_menu = 0;
uint8_t counter_sets = 0;

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

void setup() {
  lcd.init();
  lcd.humidity = 53.2;
  lcd.temp = 23.6;
  lcd.menu_main();
  Serial.begin(115200);
}
bool flag_ = false;
void loop() {
  eb.tick();

  if (eb.hold()){
    // Serial.println("hold button");

    counter_sets++;
    if (counter_sets > sets_down){
      counter_sets = sets_up;
    }

    switch (counter_sets)
    {
    case sets_up:
      Serial.println("sers_up");
      break;
    
    case sets_down:
      Serial.println("sets_down");
      break;

    default:
      break;
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
      lcd.menu_main();
      break;

    case menu_rl_1:
      lcd.menu_relay_1();
      break;

    case menu_rl_2:
      lcd.menu_relay_2();
      break;

    case menu_rl_3:
      lcd.menu_relay_3();
      break;
    
    default:
      break;
    }
  }


}