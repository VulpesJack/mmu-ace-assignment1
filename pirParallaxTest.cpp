#include "mbed.h"

Serial pc(USBTX, USBRX);
//DigitalOut led(LED1);
DigitalIn pirPin(p11, PullUp);

int main() {
  pc.printf("Init NRF\n");
  
  wait(10);
  pc.printf("Snapshot\n");
  
  int val = pirPin.read();
  while(1) {
    pc.printf("val = %f\n",val);
  }
}
