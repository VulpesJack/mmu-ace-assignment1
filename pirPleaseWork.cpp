#include "mbed.h"
 
InterruptIn motion(p11);
 
int motion_detected = 0;
 
void irq_handler(void)
{
    motion_detected = 1;
}
    
int main(void)
{
    int cnt = 0;
    motion.rise(&irq_handler);
    
    while(1) {
        if(motion_detected) {
            cnt++;
            motion_detected = 0;
            printf("Hello! I've detected %d times since reset\n", cnt);
        }
    }
}
