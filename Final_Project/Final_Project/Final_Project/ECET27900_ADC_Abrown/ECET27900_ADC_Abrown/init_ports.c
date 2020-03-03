/*
 * Filename: init_ports.c
 * Created: 2/25/2020 3:33:10 PM
 * Author: Allana Brown
 
 Description: 
 
 I/O Connections:
	PORTA   -> Switches
	PORTG -> timer0
	PORTC   -> LEDs
	PORTF   -> ADC
 
 */ 

#include <avr/io.h>
#include "init_ports.h"

void init_ports(void)
{
	DDRA = 0x00; // set PORTA as inputs
	PORTA = 0xFF; // turn on PU
	
	DDRC = 0xFF; // set PORTC as outputs
	PORTC = 0x00; 
	
	// BONUS !!!
	DDRE = 0xFF; // timer3 OC3A output
	PORTE = 0x00;

	
	DDRF = 0x00; // set PORTF as inputs
	PORTF = 0x00; // turn off PU
	
	DDRG = 0x00; // set PORTG as inputs
	PORTG = 0xFF; // turn on PU
}