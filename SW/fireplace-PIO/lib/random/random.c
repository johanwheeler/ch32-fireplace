#include "random.h"

uint32_t seed = 0xBADC0DE;

uint32_t random() {
    // xorshift32
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;

    return seed;
}

void seed_set(uint32_t seed) {
    seed = seed;
}
