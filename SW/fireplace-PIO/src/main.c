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

typedef enum
{
	screenFire,
	screenAnimation,
	screenSanta,
} ScreenState_t;

typedef enum
{
	Mute,
	Sound,
} SoundState_t;

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

	buttonPress_t last_button = buttonNone;
	uint8_t animationNumber = 0;
	uint8_t animationFrameNumber = 0;
	ScreenState_t screen = screenFire;
	SoundState_t sound = Mute;
	uint32_t t = 0;

	while(1)
	{
		Delay_Ms(1);
		t++;

		// read buttons every x ms
		if(t%200 == 0){
			buttonPress_t p = readButtons();

			if (p != last_button)
			{
				switch (p)
				{
				case buttonNext:
					printf("Next");
					screen = screenFire;
					break;
				case buttonPresent:
					printf("Present");
					screen = screenSanta;
					break;
				case buttonSound:
					printf("Sound");
					screen = screenAnimation;
					break;
				default:
					break;
				}

				last_button = p;
			}
		}

		// Change fire frame
		if((t%300 == 0) && (screen == screenFire)){
			WS2812BSimpleSend(NEO_PORT, NEO_PIN, snowman[2], 64);
		}

		// Change animation frame
		if((t%500 == 0) && (screen == screenAnimation)){
			WS2812BSimpleSend(NEO_PORT, NEO_PIN, tree, 64);
		}

		if((t%500 == 0) && (screen == screenSanta)){
			WS2812BSimpleSend(NEO_PORT, NEO_PIN, santa, 64);
		}


		
	}
}
