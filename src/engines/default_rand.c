#include "engines.h"
#include <stdlib.h>

void default_rand_setup(uint32_t seed) {
    srand(seed);
}

uint32_t default_rand_run(void) {
    return (uint32_t)rand();
}