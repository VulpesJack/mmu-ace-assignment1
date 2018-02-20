#include "mbed.h"

Serial pc(USBTX, USBRX);
//DigitalOut led(LED1);
DigitalIn pirPin(p11, PullUp);

int val = 0;

int main() {
  pc.printf("Init NRF\n");
  
  wait(10);
  pc.printf("Snapshot\n");
  
  while(1) {
    val = pirPin.read();
    
    if (val == 0) {
      pc.printf("Sensor ON\n");
      wait(1.5f);
    }
    else {
      pc.printf("Sensor is OFF\n");
    }
  }
}
