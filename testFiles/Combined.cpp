#include "mbed.h"
#include "TMP36.h"
#include "LDR.h"
#include "PIR.h"

Serial pc (USBTX, USBRX);

TMP36 myTMP36(p1);
LDR myLDR(p2);
//PIR myPIR(p3);
 
int main()
{
    float TempC;
    float Light;
    //float Motion;
 
    while(1) {
 
        TempC = myTMP36;
        Light = myLDR;
        //Motion = myPIR;
        printf("The Temperature Is : T=%5.2F C \n\r", TempC);
        printf("The Light Intensity Percentage Is : %5.2F \n\r", Light);
        //printf("The Motion Is : T=%5.2F \n\r", Motion);
        printf("\n\r");
        printf("\n\r");
        

        wait(3);
        
        if (!alarm){
            led1=1;
            //printf("***INTRUDER ALERT!***");
            //printf("\n\r");
            //wait(2);
        }
        
        else{
            led1=0;
            printf("***INTRUDER ALERT!***");
            printf("\n\r");
            }
            
    }
}