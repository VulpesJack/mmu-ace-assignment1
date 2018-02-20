#include "mbed.h"

Serial pc(USBTX, USBRX);
//DigitalOut led(LED1);
DigitalIn pirPin(p11, PullUp);

int val = 0;
int cnt = 0;

int main() {
  pc.printf("Init NRF\n");
  
  wait(5);
  pc.printf("Snapshot\n");
  
  while(1) {
    val = pirPin.read();
    
    if (val == 0) {
      cnt++;
      
      pc.printf("Sensor ON, Detected %i \r\n",cnt);
      pc.printf("Stay Away!");
      
      wait(1.5f);
    }
    else {
      pc.printf("Sensor is OFF");
    }
  }
}
