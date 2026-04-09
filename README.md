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

## REFERENCES

### Xorshift
- https://en.wikipedia.org/wiki/Xorshift
- https://www.jstatsoft.org/article/view/v008i14