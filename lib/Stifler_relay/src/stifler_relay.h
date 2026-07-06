#pragma once
#include <Arduino.h>
class Stifler_relay{
    public:
        Stifler_relay(int pin_hot, int pin_ventilation, int pin_humidity);
        //Инициализируем PWM
        void begin();
        //Необходимо постоянно вызывать в цикле
        void loop();
        class Ventilation{
            public:
            void on();
            void off();
            bool state;
        };

        class Hot{
            public:
            void on();
            void off();
            bool state;
        };

        class Humidity{
            public:
            void on();
            void off();
            bool state;
        };

        Humidity humidity;
        Hot hot;
        Ventilation ventilation;
    private:
    uint8_t pin_ventilation;
    uint8_t pin_humidity;
    uint8_t pin_hot;
        
};