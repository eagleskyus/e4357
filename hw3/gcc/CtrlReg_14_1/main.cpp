//Program Exp 14.1 setup digital output pin using control registers,
//Flash a LPC1768 onboard LED2
//Ken Ye
//10_25

#include "wait_api.h"

//function prototypes

void delay(void);

//Define address according to PinNames.h and NXP MCU user_manual
//LED2 = P1_20, therefore byte 2

#define FIO1DIR2  (*(volatile unsigned char *)(0x2009C022))
#define FIO1PIN2  (*(volatile unsigned char *)(0x2009C036))

int main() {

  FIO1DIR2 = 0xFF;
      while(1) {
      	FIO1PIN2 |= 0x10; //or bit 5 with 1 to set pin high   P1_20 is bit #5
//	delay();
	wait(1);
	FIO1PIN2 &= ~0x10; //and bit 5 with 0 to set pin low
//	delay();
	wait(1);
	
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
