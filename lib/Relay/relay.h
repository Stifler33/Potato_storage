#include <Arduino.h>

class Potato_Relay_Base{
    public:
        Potato_Relay_Base(uint8_t _pin);
        uint8_t pin;
        float up_limit;
        float down_limit;
        void loop(float value_for_compare);
        void on();
        void off();
};

class Potato_Relay{
    public:
        Potato_Relay(uint8_t pin_temp, uint8_t pin_humidity, uint8_t pin_fan);
        Potato_Relay_Base temp;
        Potato_Relay_Base humidity;
        Potato_Relay_Base fan;
        void loop(float value_ror_temp, float value_for_humidity, float value_for_fan);
};