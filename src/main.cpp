/*
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 * YWROBOT
 *Compatible with the Arduino IDE 1.0
 *Library version:1.1
 */
// #include <Wire.h> 
// #include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Stifler_i2c_display.h>

//Пример для подключения дисплея по шине I2C
//
//Тип подключения дисплея: 1 - по шине I2C, 2 - десятиконтактное. Обязательно указывать ДО подключения библиотеки
//Если этого не сделать, при компиляции возникнет ошибка: "LCD type connect has not been declared"
// #define _LCD_TYPE 1
// #include <LCD_1602_RUS_ALL.h>

// LCD_1602_RUS lcd(0x27, 16, 2);

uint8_t symbol_one[8] = {
  B01000,
  B10101,
  B01010,
  B00100,
  B01000,
  B10010,
  B00101,
  B00010
};
uint8_t symbol_two[8] = {
  B00100,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000,
  B00000
};

byte cels[] = {
  B00111,
  B01000,
  B10000,
  B10000,
  B10000,
  B10000,
  B01000,
  B00111
};

byte cels_1[] = {
  B00010,
  B00101,
  B00010,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

Stifler_display lcd;

void setup() {
  lcd.init();
  lcd.print_cels();
// lcd.init(); //Инициализация LCD (по умолчанию для ESP8266: 4 - SDA, 5 - SCL)
//   //lcd.init(0, 2); //ESP8266-01 I2C: 0 - SDA, 2 - SCL

//   // Печать сообщения на LCD
//   lcd.backlight();
//   lcd.setCursor(6, 0);
//   lcd.print("Свои");
//   lcd.setCursor(2, 1);
//   lcd.print("символы:");
//   lcd.setCursor(10, 1);
//   lcd.print("°C");

  // //Переназначаем свои символы - с индексами 6 и 7
  // lcd.createChar(1, cels_1);
  // lcd.createChar(2, cels);
  // lcd.createChar(3, symbol_two);
  // lcd.createChar(4, symbol_one);
  // lcd.setCursor(12, 1);
  // lcd.write(1);
  // lcd.setCursor(13, 1);
  // lcd.write(2);
  // lcd.setCursor(14, 1);
  // lcd.write(4);
  // lcd.setCursor(15, 1);
  // lcd.write(3);
}

void loop() {
  
}
