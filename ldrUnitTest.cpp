#include "mbed.h"

Serial pc(USBTX, USBRX);

AnalogIn ldr(p4);

int main() {
	pc.printf("INIT\n");
	
	float Vo;
	float R = 10000;
	float Vin = 3.3;
	
	pc.printf("LDR GO\n");
	
	while(1){
		Vo = ldr.read();
		
		float pd = 1.7833/Vo;
		float Rt = (Vo*R)/(Vin - Vo);
		float FTC = (powf(10,5.57644))*(powf(Rt,-1.211743));
		float Lux = FTC*10.76;
		
		printf("Sensor Reading (Vo): %f V\r\n", Vo);
		printf("Sensor Reading (PD): %f W/m^2\r\n\r\n", pd);
		printf("FTC: %f\r\n",FTC);
		printf("Lux: %f\r\n",Lux);
		
		wait(2);
	}
}
