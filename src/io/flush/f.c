#include <_io_.h>
#include <stdio.h>

#if !defined(NM_HAVE_FPURGE_FN)
#  if defined(NM_HAVE___FPURGE_FN)
#    include <stdio_ext.h>
#    define fpurge(x) __fpurge((x))
#  else
#    define fpurge(x) ((void)(x))
#  endif
#endif

int
main(int argc, char **argv) {
	_unused_(argc);
	_unused_(argv);

	int n = 0;
	int ch = fgetc(stdin);
	fprintf(stdout, "[%i] %c\n", n++, ch);
	ch = fgetc(stdin);
	fprintf(stdout, "[%i] %c\n", n++, ch);
	fflush(stdout);
	
	ch = fgetc(stdin);
	fprintf(stdout, "[%i] %c\n", n++, ch);

	fpurge(stdin);
	
	ch = fgetc(stdin);
	fprintf(stdout, "[%i] %s\n", n++, EOF == ch ? "EOF" : "!EOF");
	fflush(0);
}
