#include "mbed.h"
#include "LDR.h"

DigitalOut ldrLed(LED2);

LDR ldrSensor(p22);

int main() {
	printf("INIT LDR");
	wait(1);
	while(1) {
		ldrLed = 1;
		printf("Light = %4.2f ",ledSensor.getLight());
		printf("Raw Light = %4.2f ",ldrSensor.getLightRaw());
		ldrLed = 0;
	}
}
