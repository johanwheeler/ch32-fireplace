/* Single-File-Header for using asynchronous LEDs with the CH32V003 using DMA to the SPI port.
   I may write another version of this to use DMA to timer ports, but, the SPI port can be used
   to generate outputs very efficiently. So, for now, SPI Port.  Additionally, it uses FAR less
   internal bus resources than to do the same thing with timers.
   
   For the CH32V003 this means output will be on PORTC Pin 6

   Copyright 2023 <>< Charles Lohr, under the MIT-x11 or NewBSD License, you choose!
   Copyright 2023 Daniel Quach, modified from Charles Lohr, MIT-x11.

   If you are including this in main, simply 
	#define WS2812BSIMPLE_IMPLEMENTATION

   You may also want to define 
	#define WS2812BSIMPLE_NO_IRQ_TWEAKING

*/

#ifndef _WS2812B_SIMPLE
#define _WS2812B_SIMPLE

#include <stdint.h>

void WS2812BSimpleSend( GPIO_TypeDef * port, int pin, const uint16_t * data, int len_in_bytes );

#ifdef WS2812BSIMPLE_IMPLEMENTATION

#include "funconfig.h"

#if FUNCONF_SYSTICK_USE_HCLK != 1
#error WS2812B Driver Requires FUNCONF_SYSTICK_USE_HCLK
#endif

void WS2812BSimpleSend( GPIO_TypeDef * port, int pin, const uint16_t * data, int len_in_bytes )
{
	int port_id = (((intptr_t)port-(intptr_t)GPIOA)>>10);
	RCC->APB2PCENR |= (RCC_APB2Periph_GPIOA<<port_id);  // Make sure port is enabled.

	int poffset = (pin*4);
	port->CFGLR = ( port->CFGLR & (~(0xf<<poffset))) | ((GPIO_Speed_2MHz | GPIO_CNF_OUT_PP)<<(poffset));

	int maskon = 1<<pin;
	int maskoff = 1<<(16+pin);

	port->BSHR = maskoff;

	const uint16_t * end = data + len_in_bytes;
	while( data != end )
	{
		uint16_t byte = *data;

		uint32_t bits = (uint32_t)byte;
		uint32_t blue = (bits & 0x001F) << 3;     	// 5 bits blue  ............bbbbb -> bbbbb000
		uint32_t green = (bits & 0x07E0) >> 3;    	// 6 bits green .....ggg ggg..... -> gggggg00
		uint32_t red = (bits & 0xF800) >> 8;      	// 5 bits red   rrrrr... ........ -> rrrrr000
		
		uint32_t expanded = (green/16 << (16)) | (red/16 << (8)) | (blue/16) | 0x00000000; // divide by 30 to reduce brightness

		int i;
		for( i = 0; i < 24; i++ )
		{
			if( expanded & 0x800000)
			{
				// WS2812B's need AT LEAST 625ns for a logical "1"
				port->BSHR = maskon;
				DelaySysTick(25);
				port->BSHR = maskoff;
				DelaySysTick(1);
			}
			else
			{
				// WS2812B's need BETWEEN 62.5 to about 500 ns for a logical "0"
#ifndef WS2812BSIMPLE_NO_IRQ_TWEAKING
				__disable_irq();
#endif
				port->BSHR = maskon;
				asm volatile( "nop\nnop\nnop\nnop" );
				port->BSHR = maskoff;
#ifndef WS2812BSIMPLE_NO_IRQ_TWEAKING
				__enable_irq();
#endif
				DelaySysTick(15);
			}
			expanded <<= 1;
		}

		data++;
	}

	port->BSHR = maskoff;
}

#endif

#endif

