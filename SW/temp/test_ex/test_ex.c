#include "ch32v003fun.h"
#include <stdio.h>


#define WS2812BSIMPLE_IMPLEMENTATION
#define WS2812BSIMPLE_NO_IRQ_TWEAKING
#include "ws2812b_simple_mod2.h"

/* static const uint32_t color[1] = {0x000A0A00};
static const uint32_t off[1] = {0x00000000};

static const uint16_t col[1] = {0x2aa0};
static const uint16_t clr[1] = {0x0000}; */


static const uint16_t digit[35] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0xffe0, 0x0000, 0xffe0, 0xffe0, 0xffe0, 0x0000, 
0x0000, 0xffe0, 0x0000, 0xffe0, 0x0000, 0xffe0, 0x0000, 
0x0000, 0xffe0, 0xffe0, 0xffe0, 0x0000, 0xffe0, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

/* static const uint16_t digit[35] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0xffff, 0x0000, 0xffff, 0xffff, 0xffff, 0x0000, 
0x0000, 0xffff, 0x0000, 0xffff, 0x0000, 0xffff, 0x0000, 
0x0000, 0xffff, 0xffff, 0xffff, 0x0000, 0xffff, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
}; */

static const uint16_t black[35] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

/* static const uint8_t data[2 * 24] = {
    0x00, 0x00, 0x00,   // LED 1: Full intensity green, full intensity red, no blue
    0x00, 0x00, 0x00,   // LED 2: Full intensity green, full intensity red, no blue
}; */

/* static const uint8_t data[6] = {
    10, 10, 0,   // LED 1: 10% intensity green, 10% intensity red, no blue
    10, 10, 0,   // LED 2: 10% intensity green, 10% intensity red, no blue
};

static const uint8_t clear[6] = {
	0, 0, 0,
	0, 0, 0
}; */


int main()
{
	SystemInit();


	// Enable GPIOs
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOC;

	// GPIO D0 Push-Pull
	GPIOD->CFGLR &= ~(0xf<<(4*0));
	GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*0);

	// GPIO D4 Push-Pull
	GPIOD->CFGLR &= ~(0xf<<(4*4));
	GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*4);

	// GPIO D6 Push-Pull
	GPIOD->CFGLR &= ~(0xf<<(4*6));
	GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*6);

	// GPIO C0 Push-Pull
	GPIOC->CFGLR &= ~(0xf<<(4*3));
	GPIOC->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*3);
	GPIOC->BSHR = (1<<3);
	 
	WS2812BSimpleSend(GPIOC, 6, digit, 35);
	Delay_Ms(2000);
	WS2812BSimpleSend(GPIOC, 6, black, 35);


	

	while(1)
	{
/* 		GPIOD->BSHR = (1<<0) | (1<<4) | (1<<6);	 // Turn on GPIOs
		GPIOC->BSHR = (1<<3);
		Delay_Ms( 250 );
		GPIOD->BSHR = (1<<16) | (1<<(16+4)) | (1<<(16+6)); // Turn off GPIOs
		GPIOC->BSHR = (1<<(16+3));
		Delay_Ms( 250 ); */
	}
}
