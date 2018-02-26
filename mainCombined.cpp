/*
 * Combined Unit Program
 *  by Jack Noble (15081579)
 * 
 * This program combines the test files found on github 
 * (https://github.com/VulpesJack/mmu-ace-assignment1)
 * into one file that should have complete base functionality
 * for the home automation project.
 *
 * This file does not contain any additional code for BLE comms
 * between the nordic dev kit and an arduino phone.
 *
 * First Created: 26/02/2018
 * Last Revised: 26/02/2018 - Initial Revision
 */
 

#include "mbed.h"
#include "DHT.h"

/*
 * DEFINE INPUTS
 */

DigitalIn pirAlarm(p3, PullNone);    			 // PIR input pin
Analogin ldr(p4);                    			 // LDR input pin
DHT dhtSensor(p11, DHT11);              	     // DHT input pin, defined as per DHT library

/*
 * DEFINE OUTPUTS
 */

DigitalOut pirLED(LED1);             			 // PIR output LED, using nordic pin designation
DigitalOut dhtLED(LED2);             			 // DHT output LED
DigitalOut lightRelay(p10);                      // Relay for switching lights
DigitalOut heatRelay(p11);                       // Relay for switching heating

/*
 * INITIALIZE SERIAL
 */

Serial pc(USBTX, USBRX);             			 // Start a serial monitor with the handle "pc"

/*
 * START MAIN LOOP
 */
 
int main() {
	pc.printf("INIT\n");             			 // Signals that board is active and the serial connection is good
	
	int err;                         			 // Used by the DHT library to signal any errors with the DHT module/connection
	float Vo;                        			 // Defines the voltage output from the LDR
	float R = 10000                  			 // Defines the expected resistance from the LDR (10,000 ohm)
	float Vin = 3.3;                 			 // Defines the expected voltage input to the LDR
	
	float minLux = 1;							 // The minimum lux reading before lights are turned on
	float maxLux = 2;                            // The max lux reading before lights are turned off
	
	float minTemp = 1;                           // The minimum temperature in C before the heating is turned on
	float maxTemp = 2;                           // The maximum temperature in C before the heating is turned off
	
	wait(5);                         			 // Invokes a 5 second break in the code which allows sensors to self-calibrate
	
	pc.printf("PIR GO\n");           			 // Signals to the serial monitor that the PIR sensor is ready.
	pc.printf("LDR GO\n");           			 // Signals that the LDR is ready
	pc.printf("DHT GO\n");           			 // Signals that the DHT module is ready. 
	
	while(1) {
		if (!pirAlarm) {			 			 // Checks to see if the PIR sensor is active or not
			pirLED = 1;              			 // Turns the PIR notification LED on.
			
			dhtLED = 1;              			 // Turns the DHT notification LED on.
			err = dhtSensor.readData();          // Reads data from the DHT sensor.
			
			Vo = ldr.read();         			 // Reads the voltage from the LDR pin.
			float pd = 1.7833/Vo;
			float Rt = (Vo*R)/(Vin - Vo);
			float FTC = (powf(10,5.57644))*(powf(Rt,-1.211743));
			float Lux = FTC*10.76;
			
			if (err == 0) {						 // Checks for an error with the DHT sensor.
				pc.printf("T=%4.2f\n",dhtSensor.ReadTemperature(CELCIUS));
				float tempC = dhtSensor.ReadTemperature(CELCIUS));
				pc.printf("H=%4.2f\n",dhtSensor.ReadHumidity());
				float humid = dhtSensor.ReadHumidity();
				
				pc.printf("LDRVo=%f\n",Vo);
				pc.printf("LDRPD=%f\n",pd);
				pc.printf("LDRFTC=%f\n",FTC);
				pc.printf("Lux=%f\n",Lux);
				
				if (Lux < minLux) {
					pc.printf("MINLUX. LIGHTS ON\n");
					lightRelay = 1;
				} else {
					lightRelay = 0;
				}
				
				if (Lux > maxLux) {
					pc.printf("MAXLUX. LIGHTS OFF\n");
					lightRelay = 0;
				} else {
					lightRelay = 0;
				}
				
				if (tempC < minTemp) {
					pc.printf("MINTMP. HEATING ON\n");
					heatRelay = 1;
				} else {
					heatRelay = 0;
				}
				
				if (tempC > minTemp) {
					pc.printf("MAXTMP. HEATING OFF\n");
					heatRelay = 0;
				} else {
					heatRelay = 0;
				}
				
				wait(2);
			} else {
				pc.printf("DHTERR %i\n",err);
			}
		} else {
			pc.printf("ALARM\n");
		}
	}
}
