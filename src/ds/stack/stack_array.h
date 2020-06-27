#ifndef _STACK_ARRAY_H_
#define _STACK_ARRAY_H_

#include <stddef.h>


typedef struct stack_s {
	size_t n;
  size_t size;
  void *top;
  void *data;
} stack_s;


stack_s* stack_new(stack_s *stack, size_t n, size_t size);
void stack_free(stack_s *const stack);

int stack_empty(stack_s *const stack);
int stack_full(stack_s *const stack);

typedef void (*push_val)(stack_s *const stack, void *val);
typedef void (*pop_val)(stack_s *const stack, void *val);

void stack_push(stack_s *const stack, void *val, push_val push_val);

int stack_pop(stack_s *const stack, void *val, pop_val pop_val);


#endif /* end of _STACK_ARRAY_H_ */
