#include "Stifler_i2c_display.h"

Stifler_display::Stifler_display(): lcd(0x27, 16, 2){
    temp=0.0;
    humidity=0.0;
    main.lcd = &lcd;
    main.name_display = "main";
    main.text_heading = "Текущие данные";
    main.text_value_1 = "C";
    main.text_value_2 = "H";
}

void Stifler_display::init(){
    lcd.init();
    lcd.createChar(6, symbol_humidity);
    on_backlight();
}

void Stifler_display::print_cels(){
    lcd.setCursor(0, 1);
    lcd.print("C");
}

void Stifler_display::on_backlight(){
    lcd.backlight();
}

void Stifler_display::off_backlight(){
    lcd.noBacklight();
}

void Stifler_display::print_heading(){
    lcd.setCursor(0,0);
    lcd.print("Текущие данные");
}

void Stifler_display::print_temp(float temp){
    lcd.setCursor(2, 1);
    lcd.print(String(temp));
}

void Stifler_display::print_humidity(float humidity){
    lcd.setCursor(8, 1);
    lcd.write(6);
    lcd.setCursor(9, 1);
    lcd.print(String(humidity));
}

void Stifler_display::menu_main(){
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Текущие данные");

    lcd.setCursor(0, 1);
    lcd.print("C");

    lcd.setCursor(8, 1);
    lcd.createChar(6, symbol_humidity);
    lcd.write(6);

    update_data();
}

void Stifler_display::menu_relay_1(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Настройки реле 1");
}

void Stifler_display::menu_relay_2(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Настройки реле 2");
}

void Stifler_display::menu_relay_3(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Настройки реле 3");
}



void Stifler_display::update_data(){
    lcd.setCursor(2, 1);
    lcd.print(String(temp));

    // lcd.setCursor(8, 1);
    // lcd.write(6);

    lcd.setCursor(9, 1);
    lcd.print(String(humidity));
}