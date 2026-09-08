#include "relay.h"

Potato_Relay_Base::Potato_Relay_Base(uint8_t _pin){
    pin = _pin;
    pinMode(pin, OUTPUT);
}

void Potato_Relay_Base::loop(float value_for_compare){
    if (value_for_compare > up_limit){
        on();
    }
    if (value_for_compare < down_limit){
        off();
    }
}

void Potato_Relay_Base::on(){
    digitalWrite(pin, HIGH);
}

void Potato_Relay_Base::off(){
    digitalWrite(pin, LOW);
}

Potato_Relay::Potato_Relay(uint8_t pin_temp, uint8_t pin_humidity, uint8_t pin_fan): 
temp(pin_temp), 
humidity(pin_humidity),
fan(pin_fan)
{}

void Potato_Relay::loop(float value_for_temp, float value_for_humidity, float value_for_fan){
    temp.loop(value_for_temp),
    humidity.loop(value_for_humidity);
    fan.loop(value_for_fan);
}
