#include "mbed.h"
//example using InterruptIn with the input from the PIR motion sensors
InterruptIn alarm(p11);
DigitalOut led(LED1);
DigitalOut flash(LED4);
 
void flip() {
    led = !led;
}
 
int main() {
    alarm.mode(PullUp);
    wait(2);
    alarm.fall(&flip);  // attach the address of the flip function to the falling edge
    while(1) {           // wait around, interrupts will interrupt
        flash = !flash;
        wait(0.25);
    }
}