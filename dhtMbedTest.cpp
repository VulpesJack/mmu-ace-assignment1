#include "mbed.h"
#include "DHT.h"

DigitalOut dhtLed(LED);

DHT sensor(p23, DHT11);

int main() {
	int err;
	printf("INIT DHT");
	wait(1);
	while(1) {
		dhtLED = 1;
		err = sensor.readData();
		if (err == 0) {
			printf("Temp = %4.2f C\r\n",sensor.ReadTemperature(CELCIUS));
			printf("Humidity = %4.2f \r\n",sensor.ReadHumidity());
		}
	} else
		printf("\r\nErr %i \n",err);
	dhtLed = 0;
	wait(5);
}
