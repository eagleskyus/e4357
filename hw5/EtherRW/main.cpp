//Program Exp 12.8 read from ethernet protocal,
//Ken Ye 
//11_9

#include "mbed.h"
#include "Ethernet.h"

Ethernet eth;
Serial pc(USBTX, USBRX);
char buf[0xFF];


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
  pc.printf("Ethernet data read and display\n\r");
  while (1) 
  {
	int size = eth.receive();
	if(size > 0)
	{
	  eth.read(buf, size);
	  pc.printf("size = %d data = ", size);
	  for(int i=0; i<size; i++)
	  {
	    pc.printf("%02X ", buf[i]);
	  }
	  pc.printf("\n\r");
	}


  }

}

