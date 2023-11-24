#include "fire.h"

// macro for linear index
#define idx(x,y) (y*8+x)  

// start with a small value for the center bottom pixels
void fire_start(fire_t * f) {

    f->temps[idx(3, 7)] = 127;
    f->temps[idx(4, 7)] = 127;

    return;
}

// 
void fire_update(fire_t * f) {
    return;
}

//cleanup macros
#undef idx