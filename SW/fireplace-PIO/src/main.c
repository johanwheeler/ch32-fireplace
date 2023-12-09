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

int main()
{
	SystemInit();

	// Enable GPIOs
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOC;

	screen_init();

	// init TIM2 peripheral 
	t2pwm_init();

	// start systick IRQ to run timer
    systick_init();

	printf("initializing adc...");
	adc_init();
	printf("done.\n\r");

	printf("initializing capacitive buttons");
	buttons_init();
	printf("done.\n\r");

	// set seed for fire
	fire_seed_set(adc_get());

	Delay_Ms(1000);

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
		if(t%100 == 0){
			buttonPress_t p = buttons_read_rising();

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
						fire_reset();
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
					fire_reset();			
					break;
				}
			break;
			case buttonPresent:
				printf("Present");
				switch (screen)
				{
				case screenFire:
				case screenAnimation:

					if(adc_get() > 400){
						for (int i = 0; i < 6; i++)
						{
							screen_write(no_present+i*64);
							Delay_Ms(100);
						}
						Delay_Ms(1000);
						for (int i = 0; i < 6; i++)
						{
							screen_write(no_present+(5-i)*64);
							Delay_Ms(100);
						}

						screen = screenFire;
						fire_reset();
					}else{
						screen = screenPresent;
						animationFrameNumber = 0;
					}
					break;
				default:
					screen = screenFire;
					fire_reset();
					break;
				}
				break;
			case buttonSound:
				printf("Sound");
				if (sound == Mute) {
					music_on();
					sound = Sound;
				}
				else {
					music_off();
					sound = Mute;	
				}
				break;
			default:
				break;
			}

		}

		// Change fire frame
		if((t%32 == 0) && (screen == screenFire)){
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
