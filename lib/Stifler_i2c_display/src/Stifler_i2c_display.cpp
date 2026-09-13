#include "Stifler_i2c_display.h"

Stifler_display::Stifler_display(): lcd(0x27, 16, 2){
    temp=0.0;
    humidity=0.0;
    main.lcd = &lcd;
    main.name_display = "main";
    main.text_heading = "Current data";
    main.text_value_1 = "C";
    main.text_value_2 = "H";
    settings_rl_1.name_display = "rl_1";
    settings_rl_1.text_heading = "settings rl 1";
    settings_rl_1.text_value_1 = "C";
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

    // lcd.setCursor(8, 1);
    // lcd.write(6);

    lcd.setCursor(9, 1);
    lcd.print(String(humidity));
}