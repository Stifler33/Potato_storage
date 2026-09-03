#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>


class Stifler_display{
    public:
    uint8_t symbol_humidity[8] = {
        B00100,
        B01110,
        B11111,
        B11111,
        B01110,
        B00000,
        B00000,
        B00000,
    };
    LCD_1602_RUS lcd;
    Stifler_display();
    void init();
    void print_cels();
    void print_heading();
    void on_backlight();
    void off_backlight();
    void print_temp(float temp);
    void print_humidity(float humidity);
    
};