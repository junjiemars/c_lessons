#include <_lang_.h>
#include <stdio.h>

int
main(int argc, char **argv, char **envp) {
  _unused_(argc);
  _unused_(argv);

  char **p = envp;
  while (0 != *p) {
    printf("%s\n", *p++);
  }

  printf("Hello,\n");
}
