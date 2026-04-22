# AleaCli

AleaCLI is a simple modular CLI RNG implemented in C.

Personal moivation: This project was born from a personal desire to understand how various RNGs work and build a cabinet of curiosities of these various implementations.

## Getting started

Compile the tool with the provided Makefile:
```bash
make
```

Example usage:
```bash
# Once compiled, the binary can be used like this:
./bin/alea -e xorshift -n 5 -m 1 -M 10
```
## Usage:

| Flag | Long Flag | Description | Default |
| :--- | :--- | :--- | :--- |
| `-e` | `--engine` | Generator name | `default` |
| `-m` | `--min` | Minimum value | `0` |
| `-M` | `--max` | Maximum value | `100` |
| `-n` | `--count` | Number of outputs | `1` |
| `-s` | `--seed` | Manual seed for reproducibility | `random` |
| `-c` | `--chaos` | Chaos Mode: Randomly picks an engine | `off` |

```
alea [-e engine_name] [-m min] [-M max] [-s seed] [-n count] [-c]
```

## Available engines

| Name | Description |
| ---- | ----------- |
| default | Standard C `stdlib.h` implementation |
| xorshift | 32 bit Xorshift algorithm |

More to come..!

## References and research material

### General

- https://en.wikipedia.org/wiki/List_of_random_number_generators
- D. E. Knuth, “Chapter 3 - Random Numbers,” in The art of computer programming. Volume 2: Seminumerical algorithms, Third edition, Forthy-First printing., Boston: Addison-Wesley, 2021, pp. 1–193.
- W. H. Press, Ed., “Chapter 7 - Random Numbers,” in Numerical recipes: the art of scientific computing, 3. ed., Cambridge: Cambridge University Press, 2007, pp. 340–418.


### Xorshift

- https://en.wikipedia.org/wiki/Xorshift
- G. Marsaglia, “Xorshift RNGs,” Journal of Statistical Software, vol. 8, pp. 1–6, Jul. 2003, doi: 10.18637/jss.v008.i14.
