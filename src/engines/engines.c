#include "engines.h"
#include <stdio.h>

Engine engines[] = {
    {"default", "Standard C rand() implementation", default_rand_run, default_rand_setup},
    {"xorshift", "Xor shift.", xor_shift_run, xor_shift_setup},
};

const int ENGINE_COUNT = sizeof(engines) / sizeof(Engine);