#include "Stifler_i2c_display.h"

Stifler_display::Stifler_display(): lcd(0x27, 16, 2){
    temp=0.0;
    humidity=0.0;
}

void Stifler_display::init(){
    lcd.init();
    lcd.createChar(0, charHumidity);
    on_backlight();
}

void Stifler_display::on_backlight(){
    lcd.backlight();
}

void Stifler_display::off_backlight(){
    lcd.noBacklight();
}

void Stifler_display::update_data(){
    lcd.setCursor(2, 1);
    lcd.print(String(temp));
    lcd.setCursor(10, 1);
    lcd.print(String(humidity));
}

void Stifler_display::show_main(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Current Data");
    lcd.setCursor(0,1);
    lcd.print("C");
    lcd.setCursor(8,1);
    lcd.write(0);
}

void Stifler_display::show_rl_1(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Settings relay 1");
    lcd.setCursor(0, 1);
    lcd.print("onC");
    lcd.write(60);
    lcd.setCursor(7, 1);
    lcd.print("offC");
    lcd.write(62);
}
void Stifler_display::show_rl_2(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Settings relay 2");
    lcd.setCursor(0, 1);
    lcd.print("on");
    lcd.write(0);
    lcd.write(60);
    lcd.setCursor(7, 1);
    lcd.print("off");
    lcd.write(0);
    lcd.write(62);
}
void Stifler_display::show_rl_3(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Settings relay 3");
    lcd.setCursor(0, 1);
    lcd.print("on");
    lcd.write(0);
    lcd.write(60);
    lcd.setCursor(7, 1);
    lcd.print("off");
    lcd.write(0);
    lcd.write(62);
}

void Stifler_display::update_rl_1(int value_on, int value_off){

    if (value_on > 0){
        lcd.setCursor(4,1);
        lcd.print(String(value_on));
        if (value_on == 9){
            lcd.print(" ");
        }
    }

    if (value_off > 0){
        lcd.setCursor(12,1);
        lcd.print(String(value_off));
        if (value_off == 9){
            lcd.print(" ");
        }
    }
}

void Stifler_display::show_indicator(String type){
    if (type == "up"){
        lcd.setCursor(14,1);
        lcd.write(16);
        lcd.setCursor(6, 1);
    }
    if (type == "down"){
        lcd.setCursor(6, 1);
        lcd.write(16);
        lcd.setCursor(14,1);
    }
    lcd.write(127);
}
