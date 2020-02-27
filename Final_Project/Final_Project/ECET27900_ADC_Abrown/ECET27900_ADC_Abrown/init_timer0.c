/*
 Filename: init_timer0.c
 Created: 2/12/2020 2:43 PM
 Author: Allana Brown
 
 Description: This file contains the functions
 that utilize Timer0's OCR0A & OCR0B. These 
 functions will be used in the main.c file and 
 will replace the "#include <util/delay.h>"
 
 */ 

#include <avr/io.h>
#include "init_ports.h"
#include "init_timer0.h"

void init_timer0(void)
{
	TCNT0 = 0; // initialize timer count
	TCCR0A = 0; // normal operation mode
	TCCR0B = 0; // initalize prescaler
	OCR0A = 17; // initial 1 ms timer count
}

// Multiple 100ms delays
void ms_Delay(uint16_t time)
{
	//start timer, with pre-scaler 1024
	for(uint16_t i = 0; i < time; i++)
	{
		TCCR0B = 0x05; //pre-scaler 1024
		while((TIFR0 & (1<<OCF0A))==0)
		{
			//Wait until compare match occurs
			// OCF0A flag is set when TNCT0 = OCR0A
		}
		TCCR0B = 0; //clear timer
		
		// clear compare flag by writing a 1 to it
		TIFR0 = TIFR0 | (1<<OCF0A);
		
		TCNT0 = 0; // write this next time
		//TIMER0 is now disabled until next call
		
	}

}

// BONUS
void PWM_init(void)
{
	// Instructor said look at MODE 14 from previous IA
	TCCR3A |= ((1 << COM3A0) | (1 << WGM31)); // MODE 14: Fast PWM
	
	TCCR3B |= ((1 << WGM33) | (1 << WGM32) | (1 << CS32)); // prescaler 256
	
	OCR3A = 1250; // 50 Hz??
}

// PWM output frequency = fclk / (N * (1 + TOP))
// N = prescaler (1, 8, 64, 256, 1024)
// TOP = ______ matches the TOP