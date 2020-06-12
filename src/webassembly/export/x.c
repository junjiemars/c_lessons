#include "_wasm_.h"

#ifdef __cplusplus
extern "C" {
#endif

EMSCRIPTEN_KEEPALIVE
unsigned long
ver(void) {
  return 0x11223344;
}

EMSCRIPTEN_KEEPALIVE
unsigned long
sum(unsigned long n, unsigned long acc) {
  if (n < 1) {
    return acc;
  }
  return sum(n-1, n+acc);
}

EMSCRIPTEN_KEEPALIVE
long long
sqr(long long x) {
  long long *y = 0;
  *y = 0;
  return (*y)*x;
}


#ifdef __cplusplus
} /* end of extern "C" */
#endif

