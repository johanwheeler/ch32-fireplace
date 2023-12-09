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

#include "wavetable.h"

#include "random.h"

typedef enum
{
	screenFire,
	screenAnimation,
	screenPresent,
	screenTreeFade
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

	// set seed for RNG
	random_seed(adc_get());

	Delay_Ms(1000);

	uint8_t animationNumber = 0;
	uint8_t animationFrameNumber = 0;
	ScreenState_t screen = screenFire;
	SoundState_t sound = Mute;
	uint32_t t = 0;
	uint8_t sine_idx = 0;

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
						//fire_reset();
						//screen = screenFire;
						screen = screenTreeFade;
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
				case screenTreeFade:
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

		if((t%40 == 0) && (screen == screenTreeFade)) {

			for(int i = 0; i < 5; i++) {
				uint8_t brightness = sine_table[(sine_idx+i*10)%64]+100;
				uint32_t color = tree_colors[i];
				
				uint32_t blue = (color & 0x001F);  // 5 bits blue  ............bbbbb -> 000bbbbb
				uint32_t green = (color & 0x07E0) >> 5; // 6 bits green .....ggg ggg..... -> 00gggggg
				uint32_t red = (color & 0xF800) >> 11;   // 5 bits red   rrrrr... ........ -> 000rrrrr

				red = red*brightness >> 8;
				green = green*brightness >> 8;
				blue = blue*brightness >> 8;

				uint16_t faded = red << 11 | green << 5 | blue;

				tree[tree_idx[i]] = faded;
			}

			for (int i = 0; i < 10; i++) {
				uint8_t brightness = sine_table[(sine_idx+i*5)%64]+100;
				
				uint32_t color = (uint16_t)tree_colors[5];
				
				uint32_t blue = (color & 0x001F);  // 5 bits blue  ............bbbbb -> 000bbbbb
				uint32_t green = (color & 0x07E0) >> 5; // 6 bits green .....ggg ggg..... -> 00gggggg
				uint32_t red = (color & 0xF800) >> 11;   // 5 bits red   rrrrr... ........ -> 000rrrrr

				red = red*brightness >> 8;
				green = green*brightness >> 8;
				blue = blue*brightness >> 8;

				uint16_t faded = red << 11 | green << 5 | blue;
				tree[tree_idx[5+i]] = faded;
			}

			sine_idx++;
			sine_idx = sine_idx % 64; 
			screen_write(tree);
		}

	}
}
