#include <_io_.h>
#include <stdio.h>
#include <wchar.h>

int
main(int argc, char **argv) {
	_unused_(argc);
	_unused_(argv);

	if (argc < 2) {
		printf("!panic, need a unicode filename to pass in.\n");
		return 0;
	}
	
	char *path = argv[1];
	FILE *f = fopen(path, "r");
	if (!f) {
		perror(path);
		return 1;
	}

	wint_t c;
	while (WEOF != (c = fgetwc(f))) {
		fputwc(c, stdout);
	}
	if (ferror(f)) {
		perror(path);
	}
	fclose(f);
	
	return 0;
}
