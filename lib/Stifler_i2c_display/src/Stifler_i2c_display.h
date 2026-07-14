#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>

class Stifler_display{
    public:
    LCD_1602_RUS lcd;
    Stifler_display();
    void init();
    void print_cels();
    
};