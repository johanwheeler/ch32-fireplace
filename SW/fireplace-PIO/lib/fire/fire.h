#ifndef FIRE_H
#define FIRE_H

#include "screen.h"

void fire_draw();

uint32_t fire_random();

void fire_reset();

void fire_seed_set(uint32_t seed);

#endif