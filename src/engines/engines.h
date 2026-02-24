#ifndef ALEACLI_ENGINES_H
#define ALEACLI_ENGINES_H

#include <stdint.h>

typedef uint32_t (*rng_func_t)(void);
typedef void (*seed_func_t)(uint32_t);

typedef struct {
    const char *name;
    const char *info;
    rng_func_t generate;
    seed_func_t setup;
} Engine;

// implemented engines definitions
void mock_engine_1_setup(uint32_t seed);
uint32_t mock_engine_1(void);

void mock_engine_2_setup(uint32_t seed);
uint32_t mock_engine_2(void);

extern Engine engines[];
extern const int ENGINE_COUNT;

#endif