/*
 * Filename: init_ports.h
 * Created: 2/25/2020 3:30 PM
 *  Author: Allana Brown
 
 Description: This header file contains the
 function prototype for initalizing the ports
 and the declaration of switches used in the 
 project.
  
 */ 
#define PushButtons		(~PINA & 0x0F)

#define SW0			~PINA & (1 << PINA0) // activate ADC conversion
#define SW1			~PINA & (1 << PINA1)
#define SW2			~PINA & (1 << PINA2)
#define SW3			~PINA & (1 << PINA3) // BONUS #2

#ifndef INIT_PORTS_H_
#define INIT_PORTS_H_

void init_ports(void);

#endif /* INIT_PORTS_H_ */