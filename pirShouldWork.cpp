#include "mbed.h"

DigitalIn pirAlarm(p3, PullNone);
DigitalOut pirLed(LED1);

Serial pc(USBTX, USBRX);

int main() {
	pc.printf("INIT");
	
	while(1) {
		pc.printf("PIR GO");
		
		wait(5);
		
		if (!alarm) {
			pirLed = 1;
		} else {
			pirLed = 0;
			pc.printf("ALARM!\n");
		}
	}
}
