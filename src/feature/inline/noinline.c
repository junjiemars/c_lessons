#include "_feature_.h"
#include <stdio.h>

__noinline__
int
sum(int n, int acc) {
  if (n < 1) return acc;
  return sum(n-1, n+acc);
}

int
main(int argc, char **argv) {
  if (argc < 2) {
    printf("where the number?\n");
    return 0;
  }

  int n;
  sscanf(argv[1], "%d", &n);
  int x = sum(n, 0);
  printf("sum(%d)=%d\n", n, x);
  
  return 0;
}
