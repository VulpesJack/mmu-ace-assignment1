#include "mbed.h"
 
DigitalOut led1(LED1);
DigitalIn alarm(p29, PullUp); //internal pull up 
 
int main() {  
    wait(2); //Wait for sensor to take snap shot of still room
    
    while(1) {
        if (!alarm){
            led1=1;
            wait(2);
        }
        else
            led1=0;
    }
}
