#include "mbed.h"

Serial pc(USBTX, USBRX);

AnalogIn ldr(p4);

int main() {
	pc.printf("INIT\n");
	
	float Vo;
	pc.printf("LDR GO\n");
	
	while(1){
		Vo = ldr.read();
		
		float pd = 1.7833/Vo;
		
		printf("Sensor Reading (Vo): %f V\r\n", Vo);
		printf("Sensor Reading (PD): %f W/m^2\r\n\r\n", pd);
		
		wait(2);
	}
}
