#include <lang.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int
sqr(int x) {
	assert((0 < x) && (x < 100));
	return (x * x);
}

int
main(int argc, const char* argv[]) {
	if (argc <= 1) {
		printf("%s usage:\n\t <int>", argv[0]);
		return 0;
	}
	
	#if (NM_HAVE_STATIC_ASSERT)
		static_assert(4 == sizeof(int), "sizeof(int) != 4 bytes");
		printf("sizeof(int)=%lu\n", sizeof(int));
	#endif

	int n = atoi(argv[1]);
	printf("sqr(%u)=%u\n", 2u, sqr(n));
	printf("after call sqr()\n");

	return 0;
}
