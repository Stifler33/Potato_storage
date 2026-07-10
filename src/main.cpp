#include <Arduino.h>
#include <stifler_relay.h>
#include <GTimer.h>

GTimer<millis> pause(1000, true, GTMode::Interval);

Stifler_relay rl(3, 11, 10);
void setup() {
  
  // Пины D3 и D11 - 31.4 кГц
  TCCR2B = 0b00000001;  // x1
  TCCR2A = 0b00000001;  // phase correct

  // Пины D9 и D10 - 31.4 кГц
  TCCR1B = 0b00000001;  // x1 phase correct
  TCCR1A = 0b00000001;  // 8bit
  
}

void loop() {
  rl.loop();
  if (pause){
    if (!rl.hot.state){
      rl.hot.on();
    }else{
      rl.hot.off();
    }
  }
}