#include "mbed.h"
#include "MODSERIAL.h"

MODSERIAL pc(USBTX, USBRX);
DigitalOut led1(LED1);

#if definted(TARGET_LPC1786)
MODSERIAL blue (p9, p10);
#elif defined(TARGET_LPC4330_M4)
MODSERIAL blue(UART0_TX, UART0_RX);
#endif

bool new_send = false;
bool new_response = false;
char ATCmd[80];
char blueChar[80];

void commandAT(char *v) {
	int i = 0;
	
	while(v[i] != NULL) {
		blue.putc(v[i]);
		i++;
	}
	
	blue.printf("\r\n");
}

void rxBlueCallback(MODSERIAL_IRQ_INFO *q) {
	new_response = true;
}

void rxPcCallback(MODSERIAL_IRQ_INFO *q) {
	new_send = true;
}

int main() {
	blue.baud(38400);
	pc.baud(115200);
	
	blue.attach(&rxBlueCallback);
	pc.attach(&rxPcCallback);
	
	pc.printf("AT Mode Start\r\n");
	int i = 0;
	
	while(1) {
		if(new_send) {
			int i = 0;
			
			while(pc.readable()) {
				ATCmd[i] = pc.getc();
				i++;
			}
			commandAT(ATCmd);
			memset(ATCmd, 0, sizeof(ATCmd));
			new_send = false;
		} else if (new_response) {
			int i = 0;
			while(blue.readable()) {
				blueChar[i] = blue.getc();
				i++;
			}
			printf("Response is: %s", blueChar);
			memeset(blueChar, 0, sizeof(blueChar);
			new_response = false;
		}
		wait_ms(100);
		i++;
		
		if(i == 5) {
			led1 = !led1;
			i = 0;
		}
	}
}
