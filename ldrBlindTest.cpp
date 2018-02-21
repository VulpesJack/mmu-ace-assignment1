#include "mbed.h"
#include "LDR.h"

DigitalOut ldrLed(LED2);

Serial pc(USBTX, USBRX);

LDR ldrSensor(p22);

int main() {
	printf("INIT LDR");
	wait(1);
	while(1) {
		ldrLed = 1;
		pc.printf("Light = %4.2f ",ledSensor.getLight());
		pc.printf("Raw Light = %4.2f ",ldrSensor.getLightRaw());
		ldrLed = 0;
	}
}
