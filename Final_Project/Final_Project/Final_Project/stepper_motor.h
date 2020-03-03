/*
 * stepper_motor.h
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


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#define F_CPU 16000000UL

// Include Files:
#include <avr/io.h>
#include <util/delay.h>
#include "io_ports.h"	//for troubleshooting purposes only

// Function Prototypes:
void stepper_drive(char mode, uint8_t revolutions);
void stepper_init(void);
void stepper_position(uint16_t degrees);

// Define:
#define wave_step	0x01
#define full_step	0x02
#define half_step	0x04
#define angle		0x08


#define stepper_output

// Declaration of Variables:
extern uint8_t wave[4];
extern uint8_t full[4];
extern uint8_t half[8];

#endif /* STEPPER_MOTOR_H_ */