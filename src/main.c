#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv) {

    char *engine_name = "test_engine";
    int min = 0;
    int max = 100;
    int seed = 0;
    int info_flag = 0;
    int chaos_flag = 0;

    static struct option long_options[] = {
        {"engine", required_argument, 0, 'e'},
        {"min",    required_argument, 0, 'm'},
        {"max",    required_argument, 0, 'M'},
        {"seed",   required_argument, 0, 's'},
        {"info",   no_argument,       0, 'i'},
        {"chaos",  no_argument,       0, 'c'},
        {0, 0, 0, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "e:m:M:s:ic", long_options, NULL)) != -1) {
        switch (opt) {
            case 'e': engine_name = optarg; break;
            case 'm': min = atoi(optarg);   break;
            case 'M': max = atoi(optarg);   break;
            case 's': seed = atoi(optarg);  break;
            case 'i': info_flag = 1;        break;
            case 'c': chaos_flag = 1;       break;
            default:
                fprintf(stderr, "Usage: %s [-e engine] [-m min] [-M max] [-s seed] [-i] [-c]\n", argv[0]);
                return 1;
        }
    }

    printf("--- AleaCLI current parsed config ---\n");
    printf("Chosen engine : %s\n", engine_name);
    printf("Range         : [%d, %d]\n", min, max);
    printf("Seed          : %d\n", seed);
    printf("Info          : %s\n", info_flag ? "Yes" : "No");
    printf("Chaos Mode    : %s\n", chaos_flag ? "On" : "Off");
    printf("-------------------------------------\n");

    return 0;
}