/*
 Filename: init_timer0.h
 Author : Allana Brown
 Created: 2/12/2020 2:41 AM
 
 Description: this header file contains the function
 prototype for initializing Timer0.
 */ 

#ifndef INIT_TIMER0_H_
#define INIT_TIMER0_H_


void init_timer0(void); // initialize timer0 function prototype

void ms_Delay(uint16_t); // multiple 1ms delay function prototype

void PWM_init(void); // BONUS PWM function prototype


#endif /* INIT_TIMER0_H_ */