#include "Stifler_i2c_display.h"

Stifler_display::Stifler_display(): lcd(0x27, 16, 2){
    
}

void Stifler_display::init(){
    lcd.init();
    lcd.createChar(6, symbol_humidity);
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