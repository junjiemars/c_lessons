#include <_memory_.h>
#include <stdio.h>

typedef struct fraction_s {
	int numerator;
	int denominator;
} fraction_s;


#define _VAL_ 0x11223344
#define _GAP_ 4


void
basic_layout() {
	int head[_GAP_] = {0};
	fraction_s f = { .numerator = 22, .denominator = 7 };
	int tail[_GAP_] = {0};

	_unused_(head);
	_unused_(tail);

	printf("\nBASIC LAYOUT\n");
	printf("----------\n");

  printf("&(struct) == &(struct->1st) \t\t=> %s (%p)\n", 
		_bool_(&f == (fraction_s*)&f.numerator), &f);

	// dangerous:

	((fraction_s*)&f.denominator)->numerator = f.numerator;
	assert(f.numerator == f.denominator);

	((fraction_s*)&f.denominator)->denominator = _VAL_;
	assert(_VAL_ == *((int*)&f.denominator+1));

	assert(f.denominator == ((fraction_s*)&f.denominator)[0].numerator);
}

int 
main(int argc, char *argv[]) {
	_unused_(argc);
	_unused_(argv);

	basic_layout();

}