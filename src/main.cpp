#include <Arduino.h>
#include <Stifler_i2c_display.h>

Stifler_display lcd;

void setup() {
  lcd.init();
  lcd.on_backlight();
  lcd.print_heading();
  lcd.print_cels();
  lcd.print_temp(23.6);
  lcd.print_humidity(50.5);
  Serial.begin(115200);
}

void loop() {
  for(float i = 26.3; i < 80; i++){
    lcd.print_temp(i);
    delay(1000);
  }
}
