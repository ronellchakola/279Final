/*
 * Filename: ADC.h
 * Created: 2/25/2020 4:08 PM
 * Author: Allana Brown
 
 Description: This header file contains the function
 prototypes for initializing and reading the ADC on PORTF.
 */ 


#ifndef ADC_H_
#define ADC_H_

void init_ADC(void);

uint16_t read_ADC(uint8_t); 

uint16_t read_ADC_TENBIT(uint8_t);

#endif /* ADC_H_ */