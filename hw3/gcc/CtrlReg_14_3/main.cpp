//Program Exp 14.3 setup digital output pin using control registers,
//Flash a LPC1768 onboard LED2
//Ken Ye 
//10_26

#include "wait_api.h"

//function prototypes

void delay(void);

//Define address according to PinNames.h and NXP MCU user_manual
//LED1 = P1_18, therefore port 1 byte 2 bit 2, start from 0
//LED2 = P1_20, therefore port 1 byte 2 bit 4
//LED3 = P1_21, therefore byte 2 byte 2 bit 5
//LED4 = P1_23, therefore byte 2 byte 2 bit 7

//LED will flash based on switch
//Switch at vdd: LED1-LED2-LED2-LED2-LED1
//Switch at gnd: LED2-LED1-LED1-LED1-LED2

#define FIO0DIR0  (*(volatile unsigned char *)(0x2009C000))
#define FIO0PIN0  (*(volatile unsigned char *)(0x2009C014))

#define FIO1DIR2  (*(volatile unsigned char *)(0x2009C022))
#define FIO1PIN2  (*(volatile unsigned char *)(0x2009C036))

char a, b;

int main() {
  FIO0DIR0 = 0x00;	//input at pin 9
  FIO1DIR2 = 0xFF;	//output at onboard LED
      while(1) {

	if((FIO0PIN0 & 0x01) == 1){
	  a=0x04;
	  b=0x10;
	}
	else {
	  a=0x10;
	  b=0x04;
	}

      	FIO1PIN2 |= a; 
//	delay();
	wait(1);
	FIO1PIN2 &= a; 
//	delay();
	wait(1);

	for (int i=1; i<=3; i++) {
	  FIO1PIN2 |= b;
	  wait(1);
	  FIO1PIN2 &= b;
	  wait(1);
	} 
	
      }

      
}

//delay function

void delay(void) {
  int j;
  for(j=0; j<100000000; j++) {
  	j++;
	j--;
  }
  
}
