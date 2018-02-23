#include "mbed.h"
#include "DHT.h"

DigitalOut dhtLed(LED1);

Serial pc(USBTX, USBRX);

DHT sensor(p23, DHT11);

int main() {
	int err;
	pc.printf("INIT DHT");
	wait(1);
	while(1) {
		dhtLED = 1;
		err = sensor.readData();
		if (err == 0) {
			pc.printf("Temp = %4.2f C\r\n",sensor.ReadTemperature(CELCIUS));
			pc.printf("Humidity = %4.2f \r\n",sensor.ReadHumidity());
		} else {
		pc.printf("\r\nErr %i \n",err);
	}
	dhtLed = 0;
	wait(5);
}
