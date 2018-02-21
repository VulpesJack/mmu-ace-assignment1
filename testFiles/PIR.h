#include "mbed.h"

DigitalOut led1(LED1);
DigitalIn alarm(p3, PullNone); //internal pull up
/*
//Print temperature from TMP36 analog temperature sensor

//Serial pc (USBTX, USBRX);
 
//Setup a new class for TMP36 sensor
class PIR
{
public:
    PIR(PinName pin);
    PIR();
    operator float ();
    float read();
private:
//class sets up the AnalogIn pin
    AnalogIn _pin;
};
 
PIR::PIR(PinName pin) : _pin(pin)
{
// _pin(pin) means pass pin to the AnalogIn constructor
}
 
float PIR::read()
{
//convert sensor reading to temperature in degrees C
    return ((_pin.read()));
}
//overload of float conversion (avoids needing to type .read() in equations)
PIR::operator float ()
{
//convert sensor reading to temperature in degrees C
    return ((_pin.read()*1.0));
}*/