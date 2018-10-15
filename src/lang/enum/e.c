#include <_lang_.h>
#include <stdio.h>


enum { RED, GREEN, BLUE, };

enum order { first, second, third, };
	
#define CORVID_MAP(XX)                                                                         \
	XX(101, BEGIN,    "BEGIN")                                                                   \
	XX(101, MAGPIE,   "Including the black and white Eurasian magpie")                           \
	XX(102, RAVEN,    "A raven is one of several larger-bodied species of the genus Corvus")     \
	XX(103, JAY,      "Jays are several species of medium-sized, usually colorful and noisy")    \
	XX(104, END,      "END")

enum corvid { 
#define XX(num, name, string) CORVID_##name = num,
	CORVID_MAP(XX)
#undef XX
};

int
main(int argc, const char* argv[]) {
	_unused_(argc);
	_unused_(argv);

	printf("RED = %zi, sizeof(RED) = %zu\n", RED, sizeof(RED));
	printf("sizeof(enum order) = %zu\n", sizeof(enum order));
	
	for (int i = CORVID_BEGIN; i < CORVID_END; i++) {
		printf("corvid#: %i\n", i);
	}

}
