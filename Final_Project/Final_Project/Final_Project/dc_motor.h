/*
 * dc_motor.h
 *
 * Created: 2/19/2020 1:27:26 PM
 * Author: lane97
 *
 * Using TOV0 interrupt flag.
 * TCCR0A = 0
 * TCNT0 = 193.5
 * 
 */ 

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#define F_CPU 16000000UL

// Include Files:
#include <avr/io.h>
//#include <util/delay.h>		// using my_delay_ms instead.

// Function Prototypes:
void timer_delay_init(void);
void my_delay_ms(uint16_t Tint);
void PWM_init(void);
void delay_millisecond(void);
void PWM_output(uint8_t duty_cycle);
void ramp_up_delay_n_steps (uint8_t start, uint8_t end, uint16_t mS_time, uint8_t num_steps);


#endif /* DC_MOTOR_H_ */