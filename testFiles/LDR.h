#include "mbed.h"
 
//Print temperature from TMP36 analog temperature sensor

//Serial pc (USBTX, USBRX);
 
//Setup a new class for TMP36 sensor
class LDR
{
public:
    LDR(PinName pin);
    LDR();
    operator float ();
    float read();
private:
//class sets up the AnalogIn pin
    AnalogIn _pin;
};
 
LDR::LDR(PinName pin) : _pin(pin)
{
// _pin(pin) means pass pin to the AnalogIn constructor
}
 
float LDR::read()
{
//convert sensor reading to temperature in degrees C
    return ((_pin.read()));
}
//overload of float conversion (avoids needing to type .read() in equations)
LDR::operator float ()
{
//convert sensor reading to temperature in degrees C
    return ((_pin.read())*100);
}