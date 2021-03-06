#include <_lang_.h>
#include <stdlib.h>
#include <stdio.h>


#if (NM_HAVE_ARC4RANDOM_UNIFORM)

uint32_t
randomize(const uint32_t n) {
    return arc4random_uniform(n);
}

#endif  /* NM_HAVE_ARC4RANDOM_UNIFORM */


int
main(int argc, char **argv) {
    _unused_(argc);
    _unused_(argv);

#if (NM_HAVE_ARC4RANDOM_UNIFORM)

    size_t  n  =  10;
    if (argc > 1) {
        n = atoi(argv[1]);
    }

    printf("arc4random_uniform: [0, %zu)\n", n);
    printf("--------------------\n");
    for (size_t i = 0; i < n; i++) {
        printf("%u ", randomize(n));
    }
    putchar('\n');

#endif  /* NM_HAVE_ARC4RANDOM_UNIFORM */

    return 0;
}
