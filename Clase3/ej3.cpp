#include <iostream>
#include <string>
using namespace std;

class Peripheral{
    bool enabled;
    protected:
        string pin;
        Peripheral(string pin): pin(pin), enabled(false){}
    public:
        virtual void Display() = 0;
        void enable(){
            enabled = true;
        }
        void disable(){
            enabled = false;
        }
        bool is_enabled(){
            return enabled;
        }
};
class PWM : public Peripheral {
    float frequency;
    float duty_cycle;
    public:
        PWM(string pin,float freq, float duty): Peripheral(pin), frequency(freq), duty_cycle(duty){}
        void Display() override{
            std::cout << "Peripheral: PWM , pin : " << pin << endl;
        }
        void set_frequency(float freq){
            frequency = freq;
        }
        void set_duty(float duty){
            duty_cycle = duty;
        }
        float get_frequency(){
            return frequency;
        }
        float get_duty(){
            return duty_cycle;
        }
};
int main(){
    PWM pwm("PA0",5000,50);
    cout << pwm.get_duty() << endl;
    cout << pwm.get_frequency() << endl;
    pwm.Display();
    pwm.enable();
    pwm.set_duty(100);
    pwm.set_frequency(1000);
    cout << pwm.is_enabled() << endl;
    cout << pwm.get_duty() << endl;
    cout << pwm.get_frequency() << endl;
    return 0;
}