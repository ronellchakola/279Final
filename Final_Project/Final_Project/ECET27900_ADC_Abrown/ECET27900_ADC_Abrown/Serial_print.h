/*
 * Filename: Serial_print.h
 * Created: 2/14/2018 9:00 PM
 * Author: Professor April Cheung
 *
 *	
 *	Operations: this file is used as to connect the 
				serial terminal from Atmel studio to 
				the serial port in the ATmega2560.  
				this enable students to use printf 
				and scanf for their projects
 *	
 *	IO connections: Tx0, Rx0 through usb port
 */ 
 


#ifndef SERIAL_PRINT_H_
#define SERIAL_PRINT_H_

#include <avr/io.h>
#include <stdio.h>


/* See contents of stdio.h for explanation of data stream 
setup between UART and printf(), scanf() */
void init_UART(void);
 static int uart_putchar(char ch, FILE *stream);
 static int uart_getch(FILE *stream);

/* Assign I/O stream to UART */
 static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, uart_getch, _FDEV_SETUP_RW);



#endif /* SERIAL_PRINT_H_ */