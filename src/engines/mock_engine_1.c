#include <stdio.h>
#include "engines.h"

static uint32_t mock_engine_1_state = 1;

void mock_engine_1_setup(uint32_t seed) {
    mock_engine_1_state = seed;
    printf("mock_engine_1_state=%d\n", mock_engine_1_state);
}

uint32_t mock_engine_1(void) {
    return 1111;
}