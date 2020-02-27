/*
 * Filename: Serial_print.c
 * Created: 2/14/2018 9:00 PM
 * Author: Professor April Cheung
 *	
 *	Operations: this file is used as to connect the serial 
				terminal from Atmel studio to the serial port 
				in the ATmega2560. this enable students to 
				use printf and scanf for their projects
 *	
 *	IO connections: Tx0, Rx0 through usb port
 */ 
#include "Serial_print.h"

void init_UART(void)
{
	UCSR0A = 0x00;		// No clock doubling

	//UCSR0A = 0x02;		// Set clock doubler and increase UBRR to 12 to improve baud rate error to 0.2%
	// With no clock doubling and UBRR = 6, the error is -7%, too large and get "stop bit
	// received too soon" error in Cool Term hyper-terminal. Displays odd characters on screen

	UCSR0B = 0x18;		// enable UART RX and TX
	UCSR0C = 0x06;		// set the UART for N, 8, 1

	UBRR0L = 103;		// set BAUD Rate for 9600 with 1MHz clock (no clock doubler)

	//UBRR0L = 12;		// set BAUD Rate for 9600 with 2MHz clock (clock doubler bit is set)
	UBRR0H = 0;

	stdout = &mystdout;	// define the output stream
	stdin = &mystdout;	// define the input stream

}


// the following function sends a single character out of the serial port
 static int uart_putchar(char ch, FILE *stream)
{

	while ( (UCSR0A & (1 << UDRE0)) == 0 ) // wait until there is room in the transmit buffer
	{
	}

	UDR0 = ch; // load the character into the UART data register

	return 0;
}

// the following function waits for a serial character to be received
 static int uart_getch(FILE *stream)
{
	unsigned char ch;   	// create a variable to hold the received value

	while ( (UCSR0A & (1<<RXC0)) == 0 )	// wait until the received character flag is set
	{
	}

	ch=UDR0; // load the received character into the local variable

	return ch; // return the received value (ASCII)
}