#include "engines.h"
#include <stdlib.h>

static uint32_t x;

void xor_shift_setup(uint32_t seed) {
    x = seed;
}

uint32_t xor_shift_run(void) {
    
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;

    return x;
}