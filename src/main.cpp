#include <Arduino.h>
#include <stifler_relay.h>

Stifler_relay rl(3, 5, 9);
void setup() {
  TCCR2B = 0b00000001;
  TCCR2A = 0b00000001;

  TCCR0B = 0b00000001;
  TCCR0A = 0b00000001;

}

void loop() {

}