/*
 * Filename: ECET27900_ADC_Abrown.c
 * Created: 2/25/2020 3:28 PM
 * Author : Allana Brown
 
 Description: This multi-module program uses 8-bit
 and 10-bit ADC conversion through the serial terminal. 
 The ADC are connected as single-end inputs ranged from 0-5V. 

 
 Hardware: 
	ATmega 2560 Microcontroller
	10k single-turn Potentiometers
	LED bar
	Jumper cables
 
 
 */ 

#include <avr/io.h>
#include "init_ports.h"
#include "init_timer0.h"
#include "Serial_print.h"
#include "ADC.h"

void IO_Test(void); // test function for circuit

int main(void)
{
    init_ports(); // initialize ports
	init_timer0(); // initialize Timer0
	init_UART(); // initialize UART
	init_ADC(); // initialize ADC
	PWM_init(); // BONUS!!
	
	// Testing the Serial Terminal
	/* uncomment this when testing the Serial Terminal
	uint16_t ADC_value = 1000;
	printf("\nThe voltage is %x V", ADC_value);
	printf("\nThe voltage is %d V", ADC_value);
	*/
	
    while (1) 
    {
		// Test the HardWare of Circuit before proceeding
		/* uncomment this for the Testing Hardware Procedure
		PORTC = ~PINA;
		if(~PINA & 0x01)
		{
		IO_Test();
		}
		
		PORTC = 0x00; // turn LEDs OFF
		ms_Delay(500); // wait 500 ms
		PORTC = 0xFF; // turn on LEDs
		ms_Delay(500); // wait 500 ms
		*/
		
		// PROCEDURE 2: TESTING 8-bit & 10-bit ADC
		// uncomment this section to use SW0 to read ADC
		/*
		while(~SW0) // wait till SW0 is pressed
		{
		}
		while(SW0) // wait till SW0 is released
		{
		}
		*/
		
		uint16_t ADC0_value = read_ADC(0); // read ADC0
		//PORTC = ADC_value; // will display value between 0 - 255
			
		uint16_t ADC1_value = read_ADC_TENBIT(1); // read ADC1
		
		uint16_t ADC2_value = read_ADC_TENBIT(2); // read ADC2	
		
		// print ADC values to Serial Terminal	
		printf("\n ADC0: %d \t ADC1: %d \t ADC2: %d ", ADC0_value, ADC1_value, ADC2_value); 
		
		// uncomment the SW0 commands above before uncommenting this
		//ms_Delay(500); // delay 500 ms
		

//>>>>>>>>>>>>>>>>>>>>>> BONUS 1 (10pt) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		switch (PushButtons)
		{
			case 1: // display ADC0
			PORTC = ADC0_value; // will display value between 0 - 255
			break;
			
			case 2: // display ADC1
			PORTC = ADC1_value >> 2; // will display ONLY 8 MSB
			break;
			
			case 4: // display ADC2
			PORTC = ADC2_value >> 2; // will display ONLY 8 MSB
			break; 
		}


    }
}

void IO_Test()
{
	/*
	This function starts at PA.7 and shifts left until
	it reaches PA.0 and then shifts in the opposite
	direction till it reaches PA.7, etc.
	*/
	uint8_t count;
	uint8_t sh_right = 0x01; // start at LED0
	uint8_t sh_left = 0x80; // start at LED7
	
	// shift from right to left
	for(count = 0; count < 8; count++) // is count less than 8?
	{
		PORTC = sh_right; // start at PA.0
		ms_Delay(60); // delay for 60 ms
		sh_right = sh_right << 1; // shift once left
	}
	
	// shift left to right
	for(count = 0; count < 8; count++) // is count less than 8?
	{
		PORTC = sh_left; // start at PA.7
		ms_Delay(60); // delay for 60 ms
		sh_left = sh_left >> 1; //shift once right
	}

}
