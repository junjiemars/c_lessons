#include <_lang_.h>
#include <string.h>
#include <stdio.h>

typedef size_t (*strspn_fn)(const char *s, const char *d);

static void test_strspn(strspn_fn fn, const char *s, const char *d);

void
test_strspn(strspn_fn fn, const char *s, const char *d) {
  size_t s1 = fn(s, d);
  fprintf(stdout, "%zu\n", s1);
}

int
main(int argc, char **argv) {
  if (argc < 3) {
    printf("where the source string and spn?\n");
    return 0;
  }

  const char *ss = argv[1];
  const char *d = argv[2];
  test_strspn(strspn, ss, d);
  test_strspn(strcspn, ss, d);
  
  return 0;
}
