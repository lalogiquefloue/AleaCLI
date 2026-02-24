#include <stdio.h>
#include "engines.h"

static uint32_t mock_engine_2_state = 1;

void mock_engine_2_setup(uint32_t seed) {
    mock_engine_2_state = seed;
    printf("mock_engine_2_state=%d\n", mock_engine_2_state);
}

uint32_t mock_engine_2(void) {
    return 2222;
}