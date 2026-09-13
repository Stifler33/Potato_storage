#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>

ё

class Stifler_display{
    public:
    byte charHumidity[8] = {
    0x04,
    0x0E,
    0x1F,
    0x1F,
    0x1F,
    0x0E,
    0x00,
    0x00
    };
    LiquidCrystal_I2C lcd;
    Only_Display main;
    Only_Display settings_rl_1;
    Only_Display settings_rl_2;
    Only_Display settings_rl_3;
    float temp;
    float humidity;
    Stifler_display();
    void init();
    void on_backlight();
    void off_backlight();
    void update_data();
    
};