#pragma once

#include "funconfig.h"
#include "stdint.h"

#define AD_PIN 4u 
#define AD_CHL 2u

void adc_init( void )
{
	// ADCCLK = 24 MHz => RCC_ADCPRE = 0: divide by 2
	RCC->CFGR0 &= ~(0x1F<<11);
	
	// Enable GPIOC and ADC
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOC | RCC_APB2Periph_ADC1;
	
	// C4 is analog input chl 2
	GPIOC->CFGLR &= ~(0xf<<(4*AD_PIN));	// CNF = 00: Analog, MODE = 00: Input
	
	// Reset the ADC to init all regs
	RCC->APB2PRSTR |= RCC_APB2Periph_ADC1;
	RCC->APB2PRSTR &= ~RCC_APB2Periph_ADC1;
	
	// Use 0th conversion channel for analog channel 2
	// Set up single conversion on chl 2
	ADC1->RSQR1 = 0;
	ADC1->RSQR2 = 0;
	ADC1->RSQR3 = AD_CHL;	// 0-9 for 8 ext inputs and two internals
	
	// set sampling time for chl 2
	// 0:7 => 3/9/15/30/43/57/73/241 cycles
	ADC1->SAMPTR2 &= ~(ADC_SMP0<<(3*AD_CHL));	// clear SMP2[2:0]
	ADC1->SAMPTR2 |= 0b111<<(3*AD_CHL);				// set SMP2[2:0] to 0b111 -> 241 cycles
		
	// turn on ADC and set rule group to sw trig
	ADC1->CTLR2 |= ADC_ADON | ADC_EXTSEL;
	
	// Reset calibration
	ADC1->CTLR2 |= ADC_RSTCAL;
	while(ADC1->CTLR2 & ADC_RSTCAL);
	
	// Calibrate
	ADC1->CTLR2 |= ADC_CAL;
	while(ADC1->CTLR2 & ADC_CAL);
	
	// should be ready for SW conversion now
}

uint16_t adc_get( void )
{
	// start sw conversion (auto clears)
	ADC1->CTLR2 |= ADC_SWSTART;
	
	// wait for conversion complete
	while(!(ADC1->STATR & ADC_EOC));
	
	// get result
	return ADC1->RDATAR;
}