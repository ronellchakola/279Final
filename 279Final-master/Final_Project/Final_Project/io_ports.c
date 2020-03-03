/*
 * io_ports.c
 *
 * Created: 2/19/2020 1:50:52 PM
 * Author: lane97
 */ 

#include "io_ports.h"

void init_ports(void)
{
	DDRA = 0x00;		// sets port A to input.	//	buttons
	PORTA = 0xFF;		// turns on pullup resistors.
	
	DDRE = 0xFF;		// sets port E to output for PWM.	// PWM motor
	PORTE = 0x00;		// sets starting values to 0.
	
	DDRB = 0x0F;		// sets port B (0-3) to output	//	step motor
	PORTB = 0x00;		// sets starting values to 0.
	
	DDRF = 0x00;		// sets port F to input.	//	ADC input
	PORTF = 0xFF;		// turn on pu
}