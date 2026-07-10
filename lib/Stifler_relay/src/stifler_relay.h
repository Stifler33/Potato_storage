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
            uint8_t pin;
            void on();
            void off();
            bool state;
        };

        class Hot{
            public:
            uint8_t pin;
            void on();
            void off();
            bool state;
        };

        class Humidity{
            public:
            uint8_t pin;
            void on();
            void off();
            bool state;
        };

        Humidity humidity;
        Hot hot;
        Ventilation ventilation;
};