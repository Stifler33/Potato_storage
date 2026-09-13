#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
// #define _LCD_TYPE 1
// #include <LCD_1602_RUS_ALL.h>

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
    float temp;
    float humidity;
    Stifler_display();
    void init();
    void on_backlight();
    void off_backlight();
    void update_data();
    void show_main();
    void show_rl_1();
    void show_rl_2();
    void show_rl_3();
    void update_rl_1(int value_on=0, int value_off=0);
    void show_indicator(String type);
    
};