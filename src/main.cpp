#include <Arduino.h>
#include <Stifler_i2c_display.h>
#include <EncButton.h>

Stifler_display lcd;

#define SW 2
#define CLK 8
#define DT 7
EncButton eb(DT, CLK, SW);
float temp_potato = 5.6;
void setup() {
  lcd.init();
  lcd.humidity = 53.2;
  lcd.temp = 23.6;
  lcd.menu_main();
  Serial.begin(115200);
}

void loop() {
  eb.tick();
  if (eb.release()){
    Serial.println(eb.getClicks());
  }

}
