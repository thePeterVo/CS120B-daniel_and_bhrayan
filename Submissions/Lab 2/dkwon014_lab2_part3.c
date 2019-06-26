/*	Author: dkwon014
 *  Partner(s) Name: Bhrayan Escobar
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
 #include <avr/io.h>
 #ifdef _SIMULATE_
 #include "simAVRHeader.h"
 #endif
 int main(void)
 {
 	DDRA = 0x00;
  PORTA = 0xFF;
 	DDRB = 0xFF;
  PORTB = 0x00;

 	unsigned char tempA0, tempA1, tempA2, tempA3 = 0x00;
 	unsigned char cntavail = 4;

 	while(1) {
 		tempA0 = PINA & 0x01;
 		tempA1 = PINA & 0x02;
 		tempA2 = PINA & 0x04;
 		tempA3 = PINA & 0x08;
 		if(tempA0 == 0x01) {
 			--cntavail;
 		}
 		if(tempA1 == 0x02) {
 			--cntavail;
 		}
 		if(tempA2 == 0x04) {
 			--cntavail;
 		}
 		if(tempA3 == 0x08) {
 			--cntavail;
 		}
    if (cntavail == 0) {
      cntavail = 0x80;
    }
 		PORTC = cntavail;
    cntavail = 4;
 	}

 }