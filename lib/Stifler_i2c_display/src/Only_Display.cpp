#include "Stifler_i2c_display.h"

void Only_Display::show(){
    lcd->clear();
    lcd->setCursor(0,0);
    lcd->print(text_heading);
    lcd->setCursor(0, 1);
    lcd->print(text_value_1);
    lcd->setCursor(8, 1);
    lcd->print(text_value_2);
}

void Only_Display::print_value(float value_1, float value_2){
    lcd->setCursor(2, 1);
    lcd->print(String(value_1));
    lcd->setCursor(9, 1);
    lcd->print(String(value_2));
}