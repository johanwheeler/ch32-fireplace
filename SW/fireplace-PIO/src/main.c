#include "ch32v003fun.h"
#include <stdio.h>

#define WS2812BSIMPLE_IMPLEMENTATION
//#define WS2812BSIMPLE_NO_IRQ_TWEAKING
#include "screen.h"

#include "frames.h"

#include "buzzer.h"

#include "photores.h"

#include "buttons.h"


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

	while(1)
	{
		Delay_Ms(1);
		t++;

		// read buttons every x ms
		if(t%200 == 0){
			buttonPress_t p = buttons_read();

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
			screen_write(snowman[2]);
		}

		// Change animation frame
		if((t%500 == 0) && (screen == screenAnimation)){
			screen_write(tree);
		}

		if((t%300 == 0) && (screen == screenSanta)){
			screen_write(santa+animationFrameNumber*64);
			animationFrameNumber++;
			animationFrameNumber = animationFrameNumber%15;

		}


		
	}
}
