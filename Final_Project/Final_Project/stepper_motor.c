/*
 * stepper_motor.c
 *
 * Created: 2/10/2020 11:48:04 AM
 * Author : Jonathan Lane
 * 
 * Hardware ConNections:
 *	 INPUTS:
 *		SW0 -> PINC.0		// 1 revolution w/ wave step mode.
 *		SW1 -> PINC.1		// 1 revolution w/ full step mode.
 *		SW2 -> PINC.2		// 1 revolution w/ half step mode.
 *		SW3 -> PINC.3		// Angle
 *	 OUTPUTS:
 *		IN1 -> PORTL.0		red
 *		IN2 -> PORTL.1		orange
 *		IN3 -> PORTL.2		yellow
 *		IN4 -> PORTL.3		green
 *
 */ 

#include "stepper_motor.h"

//Declaration of Variables:
uint8_t wave[4] = {1,2,4,8};
uint8_t full[4] = {9,3,6,12};
uint8_t half[8] = {9,1,3,2,6,4,12,8};
	
void stepper_position(uint16_t position)
{
	uint16_t steps;

	steps =	((uint32_t)position * 2048 / 360 / 4);		// calculates steps needed
	for(uint16_t i=0; i<steps; i++)						// loops the correct number of times per step
	{
		for(uint16_t j=0; j<4; j++)						// loops 4 times
		{
			PORTL = wave[j];							// sets PORTL to wave[j]
			_delay_ms(3);								// delays for 50 ms.
		}
	}
}

	
void stepper_drive(char mode, uint8_t revolutions)
{
	uint16_t steps;
	
	switch(mode)
	{
		case 'W':
			steps = ((uint16_t)revolutions * 2048 / 4);			// calculates steps needed
			for(uint16_t i=0; i<steps; i++)						// loops the correct number of times per step
			{
				for(uint16_t j=0; j<4; j++)						// loops 4 times
				{
					PORTL = wave[j];							// sets PORTL to wave[j]
					_delay_ms(3);								// delays for 50 ms.
				}
			}
		break;
		
		case 'F':
			steps = ((uint16_t)revolutions * 2048 / 4);			// calculates steps needed
			for(uint16_t i=0; i<steps; i++)						// loops the correct number of times per step
			{
				for(uint16_t j=0; j<4; j++)						// loops 4 times
				{
					PORTL = full[j];							// sets PORTL to full[j]
					_delay_ms(3);								// delays for 50 ms.
				}
			}
		break;
		
		case 'H':
		steps = ((uint16_t)revolutions * 4096 /8);				// calculates steps
			for(uint16_t i=0; i<steps; i++)						// loops the correct number of times per step
			{				
				for(uint16_t j=0; j<8; j++)						// loops 8 times
				{
					PORTL = half[j];							// sets PORTL to half[j]
					_delay_ms(3);								// delays for 50 ms.
				}
			}
		break;
	}
}