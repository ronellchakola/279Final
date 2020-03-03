/*
 * Filemame: ADC.c
 * Created: 2/25/2020 4:09 PM
 * Author: Allana Brown
 
Description: This module contains the functions for
initializing the ADC, reading 8-bit ADC conversion results,
reading 10-bit conversion results, and initializing Timer3
for Fast PWM. 

 
 */ 
#include <avr/io.h>
#include "io_ports.h"
#include "ADC.h"

void init_ADC(void)
{
	// select input channels AD0 thru ADC2
	ADMUX |= ((1 << MUX2) | (1 << MUX1) | (1 << MUX0)); 
	
	// default at ADC0 on PORTF
	ADMUX |= 0x00;
	
	// select ADC clock freq (128)
	ADCSRA = ((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
	
	// enable ADC	
	ADCSRA |= (1 << ADEN); 
}

uint16_t read_ADC(uint8_t channel)
{
	uint8_t adc_readout = 0; // 8bit value holds result
	
	// starting voltage (Avcc) & 8-bit Left justified
	ADMUX = ((1 << REFS0) | (1 << ADLAR));
	
	// select channel
	ADMUX = (ADMUX & 0xE0) | channel;
	
	// start conversion (ADCSRA)
	ADCSRA |= (1 << ADSC);
	
	while((ADCSRA & (1 << ADIF)) == 0)
	{
		// wait for conversion to be completed
	}
	
	adc_readout = ADCH; // get upper 8-bits
	
	// clear conversion flag
	ADCSRA |= (1 << ADIF);
	
	return adc_readout; // send back 8-bit result 
}

uint16_t read_ADC_TENBIT(uint8_t channel)
{
	uint16_t adc_value; 
	
	ADMUX = ((1 << REFS0));  // turn off ADLAR for 10 bit reading
	
	ADMUX = (ADMUX & 0xE0) | channel;
	
	ADCSRA |= (1 << ADSC);
	
	while((ADCSRA & (1 << ADIF)) == 0)
	{
		// wait for conversion to be completed
	}
	
	adc_value = ADCL; // read lower bits
	adc_value = (adc_value | (ADCH << 8)); // combine upper and lower bits
	
	// clear conversion flag
	ADCSRA |= (1 << ADIF);
	
	return adc_value; // send back 8-bit result
	
}


