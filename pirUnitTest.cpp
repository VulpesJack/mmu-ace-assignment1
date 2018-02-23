#include "mbed.h"

DigitalIn pirAlarm(p3, PullNone);
DigitalOut pirLed(LED1);

Serial pc(USBTX, USBRX);

int main() {
    pc.printf("INIT\n");
	
    wait(5);
    pc.printf("PIR GO\n");
	
    while(1) {
        if (!pirAlarm) {
	    pirLed = 1;
        } else {
	    pirLed = 0;
	    pc.printf("ALARM!\n");
        }
    }
}
