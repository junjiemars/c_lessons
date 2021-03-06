#include <_algo_.h>


void
insertion_sort(void *base, size_t nel, size_t width,
							 int (*cmp)(const void *lhs, const void *rhs))
{
	void *saved = malloc(width);
	for (size_t j = 1; j < nel; j++)
    {
      long long i = j-1;
      while (i >= 0 && cmp((char*)base+i*width, (char*)base+j*width) > 0)
        {
          i--;
        }
      if ((long long)j == ++i/* important */)
        {
          continue;
        }
      memmove(saved, (char*)base+j*width, width);
      memmove((char*)base+(i+1)*width, (char*)base+i*width, (j-i)*width);
      memmove((char*)base+i*width, saved, width);
    }
	free(saved);
}

int
main(int argc, char **argv)
{
	_unused_(argc);
	_unused_(argv);

	int a1[] =
    {
      0x3, 0x5, 0x1, 0x4, 0x1, 0x2, 0x2
    };
	printf("insertion sort+:\n----------\n");
	list_array(a1, sizeof(a1)/sizeof(*a1), sizeof(*a1), print_int);
	printf("insertion sort-:\n----------\n");
	insertion_sort(a1, sizeof(a1)/sizeof(*a1), sizeof(*a1), cmp_int);
	list_array(a1, sizeof(a1)/sizeof(*a1), sizeof(*a1), print_int);

	char *s1[] =
    {
      "block", "array", "floor", "digit", "floor", "cell", "cell"
    };
	printf("insertion sort+:\n----------\n");
	list_array(s1, sizeof(s1)/sizeof(*s1), sizeof(*s1), print_str);
	printf("insertion sort-:\n----------\n");
	insertion_sort(s1, sizeof(s1)/sizeof(*s1), sizeof(*s1), cmp_str);
	list_array(s1, sizeof(s1)/sizeof(*s1), sizeof(*s1), print_str);

	return 0;
}
