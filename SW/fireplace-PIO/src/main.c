#include "ch32v003fun.h"
#include <stdio.h>

#define WS2812BSIMPLE_IMPLEMENTATION
//#define WS2812BSIMPLE_NO_IRQ_TWEAKING
#include "ws2812b_simple_mod2.h"

#include "frames.h"

#include "buzzer.h"

#include "photores.h"

#include "buttons.h"

// Pinouts
#define NEO_PORT GPIOD
#define NEO_PIN 0

#define BUZZ_PORT GPIOC
#define BUZZ_PIN 0

#define TOUCH_PORT GPIOD
#define TOUCH_1_PIN 2
#define TOUCH_2_PIN 3
#define TOUCH_3_PIN 4

enum ScreenState {
	Fire,
	Animation,
	Santa,
};

uint8_t AnimationNumber;

enum SoundState {
	Mute,
	Sound,
};


int main()
{
	SystemInit();

	// Enable GPIOs
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOC;

	// Neopixel pin push-pull
	NEO_PORT->CFGLR &= ~(0xf<<(4*NEO_PIN));
	NEO_PORT->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*NEO_PIN);

	// init TIM2 peripheral 
	//t2pwm_init();

	// start systick IRQ to run timer
    //systick_init();

	printf("initializing adc...");
	adc_init();
	printf("done.\n\r");

	printf("initializing capacitive buttons");
	init_buttons();
	printf("done.\n\r");

	Delay_Ms(1000);

	int i = 0;

	while(1)
	{

		buttonPress p = readButtons();

		switch (p)
		{
		case buttonNext:
			printf("Next");
			i = 0;
			break;
		case buttonPresent:
			printf("Present");
			i = 1;
			break;
		case buttonSound:
			printf("Sound");
			i = 2;
			break;
		default:
			break;
		}
		Delay_Ms(10);

		
		// WS2812BSimpleSend(GPIOC, 6, santa, 64);
		//for(uint8_t i = 0; i < 3; i++){
		WS2812BSimpleSend(NEO_PORT, NEO_PIN, tree, 64);
		//	printf( "adc: %d\n", adc_get() );
		//	Delay_Ms( 200 );
			
		//}
		
		//printf( "Hello World!\n");
		// Delay_Ms( 1000 );
	}
}
