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

// default C RNG
void default_rand_setup(uint32_t seed);
uint32_t default_rand_run(void);

// implemented engines definitions
void xor_shift_setup(uint32_t seed);
uint32_t xor_shift_run(void);

extern Engine engines[];
extern const int ENGINE_COUNT;

#endif