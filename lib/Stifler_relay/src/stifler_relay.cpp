/**
 * v1.0
 * Здесь реализована работа с реле
 */

#include <stifler_relay.h>


GTimer<millis> kick(100, false, GTMode::Timeout);


Stifler_relay::Stifler_relay(int pin_hot, int pin_ventilation, int pin_humidity){
    humidity.state = false;
    hot.state = false;
    ventilation.state = false;
    pinMode(pin_hot, OUTPUT);
    pinMode(pin_humidity, OUTPUT);
    pinMode(pin_ventilation, OUTPUT);

}

void Stifler_relay::begin(){    
    
}

void Stifler_relay::Hot::on(){
    if (!state){
        state = true;
        ledcAttachPin(pin::rl::end, ch_pwm::rl);
        ledcWrite(ch_pwm::rl, pwm_duty::max);
        kick.start();
    } 
}

void Stifler_relay::Hot::off(){
    if (state){
        state = false;
        ledcDetachPin(pin::rl::end);        
    } 
}

void Stifler_relay::Humidity::on(){
    if (!state){
        state = true;
        ledcAttachPin(pin::rl::pu, ch_pwm::rl);
        ledcWrite(ch_pwm::rl, pwm_duty::max);
        kick.start();
    } 
}

void Stifler_relay::Humidity::off(){
    if (state){
        state = false;
        ledcDetachPin(pin::rl::pu);
    } 
}

void Stifler_relay::Ventilation::on(){
    if (!state){
        state = true;
        ledcAttachPin(pin::rl::plus, ch_pwm::rl);
        ledcWrite(ch_pwm::rl, pwm_duty::max);
        kick.start();
    } 
}

void Stifler_relay::Ventilation::off(){
    if (state){
        state = false;
        ledcDetachPin(pin::rl::plus);    
    } 
}

void Stifler_relay::loop(){
    if (kick){
        ledcWrite(ch_pwm::rl, pwm_duty::relay);
    }
}
