/* Based on ws2812b_simple_mod2 by Charles Lohr
 Copyright 2023 <>< Charles Lohr, under the MIT-x11 or NewBSD License, you choose!
 Copyright 2023 Daniel Quach, modified from Charles Lohr, MIT-x11.

 Defines in funconfig:
    - SCREEN_GPIO_PORT: GPIO port for display
    - SCREEN_GPIO_PIN: GPIO pin for display
*/

#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>
#include <ch32v003fun.h>
#include <funconfig.h>

void screen_init(void);

void screen_write(const uint16_t *data);

#endif
