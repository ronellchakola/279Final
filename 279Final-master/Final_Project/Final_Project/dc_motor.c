/*
 * dc_motor.c
 *
 * Created: 2/19/2020 1:27:00 PM
 * Author: lane97
 *
 * Using TOV0 interrupt flag.
 * TCCR0A = 0
 * TCNT0 = 6
 *
 */ 

#include "dc_motor.h"

void timer_delay_init(void)
{
	TCNT0 = 0x06;		// prescaler = 64.
	TCCR0A = 0x00;		// sets timer function to normal.
	TCCR0B = 0X00;		// should set to intended delay when timer starts.
}

void my_delay_ms(uint16_t Tint)
{
	for(int i = 0; i < Tint; i++)				// loops for Tint times.
	{
		TCCR0B = ((1 << CS01) | (1 << CS00));	// sets prescaler (0b011).
		while((TIFR0 & (1 << TOV0)) == 0)		// wait until overflow.
		{
		}
		TCCR0B = 0;								// stops timer.
		TIFR0 |= (1 << TOV0);					// clears overflow.
		TCNT0 = 0x06;							
	}
}

void PWM_init(void)
{
	TCCR3A = (1 << WGM31) | (1 << WGM30) | (1 << COM3A1);		// sets bits 0, 3, and 7 of Timer / Counter 3 Control Register A.
	TCCR3B = (1 << WGM32) | (1 << CS32);						// sets bits 2 and 3 of Timer / Counter 3 Control Register B.
}

void PWM_output(uint8_t duty_cycle)
{
	OCR3A = ((1024 * (uint32_t)duty_cycle) / 100);				// sets Output Compare Register 3 A.
}

void ramp_up_delay_n_steps (uint8_t start, uint8_t end, uint16_t mS_time, uint8_t num_steps)
{	
	if(start < end)
	{
		uint8_t duty_per_step = ((end - start) / num_steps);						// duty cycle per step calculation.
		uint16_t incrament_per_step = ((uint32_t)(duty_per_step) * 1024) / 100;		// incrament per step value;
		
		for(uint8_t i = 1; i <= num_steps; i++)
		{
			PWM_output(start);							// sets start value.
			
			OCR3A = (i * incrament_per_step);			// determines the needed duty cycle per step.
			my_delay_ms((mS_time / num_steps));			// delays for specified time per step.
		}
	}
	else if(start > end)
	{
		uint8_t duty_per_step = ((start - end) / num_steps);						// duty cycle per step calculation.
		uint16_t incrament_per_step = ((uint32_t)(duty_per_step) * 1024) / 100;		// increment per step value;
		
		for(uint8_t i = num_steps; i >= 1; i--)
		{
			PWM_output(start);							// sets start value.
			
			OCR3A = (i * incrament_per_step);			// determines the needed duty cycle per step.
			my_delay_ms((mS_time / num_steps));			// delays for specified time per step.
		}
		OCR3A = 0x00;
	}
	
}