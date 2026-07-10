/**
 * v1.0
 * Здесь реализована работа с реле
 */

#include <stifler_relay.h>
#include <GTimer.h>


GTimer<millis> kick(100, false, GTMode::Timeout);


Stifler_relay::Stifler_relay(int pin_hot, int pin_ventilation, int pin_humidity){
    humidity.state = false;
    hot.state = false;
    ventilation.state = false;
    humidity.pin = pin_humidity;
    hot.pin = pin_hot;
    ventilation.pin = pin_ventilation;
    pinMode(pin_hot, OUTPUT);
    pinMode(pin_humidity, OUTPUT);
    pinMode(pin_ventilation, OUTPUT);

}

void Stifler_relay::begin(){ 
    
}

void Stifler_relay::Hot::on(){
    if (!state){
        state = true;
        analogWrite(pin, 255);
        kick.start();
    } 
}

void Stifler_relay::Hot::off(){
    if (state){
        state = false;
        analogWrite(pin, 0);
    } 
}

void Stifler_relay::Humidity::on(){
    if (!state){
        state = true;
        analogWrite(pin, 255);
        kick.start();
    } 
}

void Stifler_relay::Humidity::off(){
    if (state){
        state = false;
        analogWrite(pin, 0);
    } 
}

void Stifler_relay::Ventilation::on(){
    if (!state){
        state = true;
        analogWrite(pin, 255);
        kick.start();
    } 
}

void Stifler_relay::Ventilation::off(){
    if (state){
        state = false;
        analogWrite(pin, 0);
    } 
}

void Stifler_relay::loop(){
    if (kick){
        if (hot.state){
            analogWrite(hot.pin, 150);
        }
        if (humidity.state){
            analogWrite(humidity.pin, 150);
        }
        if (ventilation.state){
            analogWrite(ventilation.pin, 150);
        }
    }
}
