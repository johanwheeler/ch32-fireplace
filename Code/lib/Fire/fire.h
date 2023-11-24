#ifndef __FIRE_H__
#define __FIRE_H__

#include "stdint.h"
#include "malloc.h"

typedef struct {
    uint32_t randn;
    uint8_t temps[64];
} fire_t;

// Initialize fire
void fire_start(fire_t * f);

// Step 1 frame
void fire_update(fire_t * f);

#endif