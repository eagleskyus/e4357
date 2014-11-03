//Program Exp 7.9 setup digital output pin using control registers,
//Flash a LPC1768 onboard LED2
//Ken Ye 
//11_3

#include "mbed.h"

Serial async_port(p9, p10);
DigitalOut red_led(p25);
DigitalOut green_led(p26);
DigitalOut strobe(p7);
DigitalIn switch_ip1(p5);
DigitalIn switch_ip2(p6);
char switch_word;
char recd_val;


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
  async_port.baud(115200);
  //default 8 bits, no parity

  while(1) {
	//setup word to be sent
	switch_word = 0xa0;
	if(switch_ip1 == 1)
	  switch_word = switch_word | 0x01;
	if(switch_ip2 == 1)
	  switch_word = switch_word | 0x02;

	strobe = 1;
	wait_us(10);
	strobe = 0;
	async_port.putc(switch_word); //transmit switch_word
	if(async_port.readable() == 1) //any character to be read
	  recd_val = async_port.getc(); //then read it

	strobe = 1;
	wait_ms(10);
	strobe = 0;

	//set led according to incoming word
	red_led = 0;
	green_led = 0;
	recd_val = recd_val & 0x03;
	if(recd_val == 1)
	  red_led = 1;
	if(recd_val == 2)
	  red_led = 1;
	if(recd_val == 3) {
	  red_led = 1;
	  green_led = 1;
	}
  }
}

