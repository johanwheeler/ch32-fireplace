#define SYSTEM_CORE_CLOCK 48000000
#define APB_CLOCK SYSTEM_CORE_CLOCK

#include "ch32v003fun.h"

#include <stdio.h>

#include "frames.h"
//#include "fire.h"

#define WS2812BSIMPLE_IMPLEMENTATION
#define WS2812BSIMPLE_NO_IRQ_TWEAKING
#include "ws2812b_simple_mod2.h"

    /* static const uint32_t color[1] = {0x000A0A00};
    static const uint32_t off[1] = {0x00000000};

    static const uint16_t col[1] = {0x2aa0};
    static const uint16_t clr[1] = {0x0000}; */

    // fire_t fire;

int main(){

  //fire_start(&fire);

  // Enable GPIOs
  RCC->APB2PCENR |= RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOC;

  // GPIO D0 Push-Pull
  GPIOD->CFGLR &= ~(0xf << (4 * 0));
  GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP) << (4 * 0);

  // GPIO D4 Push-Pull
  GPIOD->CFGLR &= ~(0xf << (4 * 4));
  GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP) << (4 * 4);

  // GPIO D6 Push-Pull
  GPIOD->CFGLR &= ~(0xf << (4 * 6));
  GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP) << (4 * 6);

  // GPIO C0 Push-Pull
  GPIOC->CFGLR &= ~(0xf << (4 * 3));
  GPIOC->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP) << (4 * 3);
  GPIOC->BSHR = (1 << 3);

  // GPIO D5 Push-Pull
  GPIOD->CFGLR &= ~(0xf << (4 * 5));
  GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP) << (4 * 5);

  // WS2812BSimpleSend(GPIOC, 6, digit, 35);
  // Delay_Ms(2000);
  // WS2812BSimpleSend(GPIOC, 6, santa, 64);
  // WS2812BSimpleSend(GPIOC, 6, test_img, 2);
  // Delay_Ms(2000);
  // WS2812BSimpleSend(GPIOC, 6, black, 35);

  // GPIOD->BSHR = (1<<0) | (1<<4) | (1<<6);	 // Turn on GPIOs
  // GPIOC->BSHR = (1<<3);
  // Delay_Ms( 250 );
  // GPIOD->BSHR = (1<<16) | (1<<(16+4)) | (1<<(16+6)); // Turn off GPIOs
  // GPIOC->BSHR = (1<<(16+3));
  // Delay_Ms( 250 );
  while (1)
  {
    // WS2812BSimpleSend(GPIOC, 6, santa, 64);
    for (uint8_t i = 0; i < 3; i++)
    {
      WS2812BSimpleSend(GPIOD, 0, snowman[i], 64);
      // fire_update(&fire);
      Delay_Ms(200);
    }
  }
  
  

  // printf( "Hello World!\n");
  // Delay_Ms( 1000 );

}