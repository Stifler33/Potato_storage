#include "Stifler_i2c_display.h"

Stifler_display::Stifler_display(): lcd(0x27, 16, 2){
    
}

void Stifler_display::init(){
    lcd.init();
}

void Stifler_display::print_cels(){
    lcd.backlight();
    lcd.setCursor(1, 1);
    lcd.print("°C");
}