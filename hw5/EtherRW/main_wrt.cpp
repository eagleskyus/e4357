//Program Exp 12.7 write to ethernet protocal,
//Ken Ye 
//11_9

#include "mbed.h"
#include "Ethernet.h"

Ethernet eth;
char data[] = {0xB9, 0x46};

//function prototypes

//Define address according to PinNames.h and NXP MCU user_manual
//LED1 = P1_18, therefore port 1 byte 2 bit 2, start from 0
//LED2 = P1_20, therefore port 1 byte 2 bit 4
//LED3 = P1_21, therefore byte 2 byte 2 bit 5
//LED4 = P1_23, therefore byte 2 byte 2 bit 7

//LED will flash based on switch
//Switch at vdd: LED1-LED2-LED2-LED2-LED1
//Switch at gnd: LED2-LED1-LED1-LED1-LED2

int main() {
  while (1) 
  {
	eth.write(data, 0x02);
	eth.send();
	wait(0.2);
  }

}

