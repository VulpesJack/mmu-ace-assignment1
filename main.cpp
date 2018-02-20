#include "mbed.h"
//#include "dht.h"

//#define DHT11_PIN 3               // Define the DHT11 Pin

Serial pc (USBTX, USBRX); //RX TX 

DigitalOut relayPin(p12);       // Set the relay output pin to Arduino equivalent
DigitalOut ledPin(LED1);        // Set the LED output pin to LED1

DigitalIn pirPin(p29);          // Set the PIR read pin to arduino equivalent

AnalogIn ldrPin(A0);            // Set the analog LDR pin to arduino equivalent
//AnalogIn ldrPin(p01);

//dht DHT;                      // Enable the dht library.

int pirState = 0;             // Initialize the PIR state to low
int pirVal = 0;                 // Initialize the PIR value to 0
int ldrVal = 0;                 // Initialize the LDR value to 0

int setup(void) {
    relayPin = 0;               // Disable relay pin upon boot
}

int loop(void) {
    relayPin = 0;
    pc.printf("RELAY OFF\n");
    wait(1);
    relayPin = 1;
    pc.printf("RELAY ON\n");
    wait(1);
    
    //int chk = DHT.read11(DHT11_PIN);
    //TODO: add serial
    
    //if(pirPin) {
        //ledPin = 1;
        
        //if(pirState == 0) {
            //pc.printf("MOTION\n");
           // pirState = 1;
       // } else {
            //ledPin = 0;
            
            //if(pirState == 1) {
               // pc.printf("NO MOTION\n");
               // pirState = 0;
     //float dect          
    // dect = pirPin.read();
               
    wait(2); //Wait for sensor to take snap shot of still room
    float dect;
        while(1) {
            dect=pirPin.read();
            wait (1);
            pc.printf("pirPin value: %f \n", dect);
            if (dect == 1){
            ledPin=1;
            pc.printf("MOTION\n");
            pc.printf("pirPin value: %f \n", dect);
            wait(2);
            }
            else if (dect == 0)
            ledPin=0;
            pc.printf("NO MOTION\n");
            pc.printf("pirPin value: %f \n", dect);
              
            }
        }
    
    
    //TODO: add LDR serial code.


int main(void) {
    
    // This loop emulates an Arduino Uno, it simply invokes setup then moves onto
    // the "main" loop once setup has completed.
    
    setup();
    while(1) {
        loop();
    }
}
