#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <time.h>
#include "engines/engines.h"

int main(int argc, char **argv) {

    char *engine_name = "default";
    int min = 0;
    int max = 100;
    int seed = 0;
    int count = 1;
    int info_flag = 0;
    int chaos_flag = 0;

    static struct option long_options[] = {
        {"engine", required_argument, 0, 'e'},
        {"min",    required_argument, 0, 'm'},
        {"max",    required_argument, 0, 'M'},
        {"seed",   required_argument, 0, 's'},
        {"count",  required_argument, 0, 'n'},
        {"chaos",  no_argument,       0, 'c'},
        {"info",   no_argument,       0, 'i'},
        {0, 0, 0, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "e:m:M:s:n:ci", long_options, NULL)) != -1) {
        switch (opt) {
            case 'e': engine_name = optarg; break;
            case 'm': min = atoi(optarg);   break;
            case 'M': max = atoi(optarg);   break;
            case 's': seed = atoi(optarg);  break;
            case 'n': count = atoi(optarg); break;
            case 'c': chaos_flag = 1;       break;
            case 'i': info_flag = 1;        break;
            default:
                fprintf(stderr, "Usage: %s [-e engine] [-m min] [-M max] [-s seed] [-n count] [-i] [-c]\n", argv[0]);
                return 1;
        }
    }

    if (!seed){
        seed = time(NULL); // sets seed to current time
    }

    // find engine./
    Engine *selected = NULL;

    for (int i = 0; i < ENGINE_COUNT; i++) {
        if (strcmp(engine_name, engines[i].name) == 0) {
            selected = &engines[i];
            break;
        }
    }

    if (selected == NULL) {
        fprintf(stderr, "Error: Engine '%s' not found.\n", engine_name);
        fprintf(stderr, "Available engines:\n");
        for (int i = 0; i < ENGINE_COUNT; i++) {
            fprintf(stderr, " - %s: %s\n", engines[i].name, engines[i].info);
        }
        return 1;
    }

    selected->setup(seed);
    for (int i = 0; i < count; i++) {
        int val = selected->generate();
        printf("%d\t", val);
    }

    // parsed commands debugging
    // printf("--- AleaCLI current parsed config ---\n");
    // printf("Chosen engine : %s\n", engine_name);
    // printf("Range         : [%d, %d]\n", min, max);
    // printf("Seed          : %d\n", seed);
    // printf("Info          : %s\n", info_flag ? "Yes" : "No");
    // printf("Chaos Mode    : %s\n", chaos_flag ? "On" : "Off");
    // printf("-------------------------------------\n");

    return 0;
}