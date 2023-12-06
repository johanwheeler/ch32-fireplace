#include "ch32v003fun.h"
#include <stdio.h>

#define WS2812BSIMPLE_IMPLEMENTATION
//#define WS2812BSIMPLE_NO_IRQ_TWEAKING
#include "screen.h"

#include "frames.h"

#include "buzzer.h"

#include "photores.h"

#include "buttons.h"

#include "fire.h"

typedef enum
{
	screenFire,
	screenAnimation,
	screenPresent,
} ScreenState_t;

typedef enum
{
	Mute,
	Sound,
} SoundState_t;

// xorshift random

unsigned int rand = 1212;

unsigned int newRandom(){
	rand ^= rand << 13;
	rand ^= rand >> 17;
	rand ^= rand << 5;
	return rand;
}

int main()
{
	SystemInit();

	// Enable GPIOs
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOC;

	screen_init();

	// init TIM2 peripheral 
	//t2pwm_init();

	// start systick IRQ to run timer
    //systick_init();

	printf("initializing adc...");
	adc_init();
	printf("done.\n\r");

	printf("initializing capacitive buttons");
	buttons_init();
	printf("done.\n\r");

	Delay_Ms(1000);

	buttonPress_t last_button = buttonNone;
	uint8_t animationNumber = 0;
	uint8_t animationFrameNumber = 0;
	ScreenState_t screen = screenFire;
	SoundState_t sound = Mute;
	uint32_t t = 0;
	uint32_t oldFire = 0;

	while(1)
	{
		Delay_Ms(1);
		t++;

		// read buttons every x ms
		if(t%100 == 0){
			buttonPress_t p = buttons_read();

			if (p != last_button)
			{
			    int switchScreen = 0;
				ScreenState_t newScreen = screenFire;
				switch (p)
				{
				case buttonNext:
					printf("Next");
					switch (screen)
					{
					case screenAnimation:
						animationNumber++;
						animationFrameNumber = 0;
						if(animationNumber >= (sizeof(animations)/sizeof(animation_t))){
							screen = screenFire;
						}
						printf("animation number: %d", animationNumber);
						break;
					case screenFire:
						screen = screenAnimation;
						animationNumber = 0;
						animationFrameNumber = 0;
						break;
					case screenPresent:
						screen = screenFire;
						break;
					}
				break;
				case buttonPresent:
					printf("Present");
					switch (screen)
					{
					case screenFire:
					case screenAnimation:
						screen = screenPresent;
						animationFrameNumber = 0;
						break;
					default:
						screen = screenFire;
						animationFrameNumber = 0;
						break;
					}
					break;
				case buttonSound:
					printf("Sound");
					break;
				default:
					break;
				}

				last_button = p;
			}
		}

		// Change fire frame
		if((t%20 == 0) && (screen == screenFire)){
			fire_draw();
		}

		// Change animation frame
		if((t%250 == 0) && (screen == screenAnimation)){
			screen_write(animations[animationNumber].data + animationFrameNumber*64);
			animationFrameNumber = (animationFrameNumber+1) % animations[animationNumber].numframes;
		}

		if((t%250 == 0) && (screen == screenPresent)){
			screen_write(santa+animationFrameNumber*64);
			animationFrameNumber++;
			animationFrameNumber = animationFrameNumber%15;
		}

	}
}
