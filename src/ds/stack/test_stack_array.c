#include "_ds_.h"
#include "node_array.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

node_s*
int_node_new(node_s *node, size_t n) {
  if (0 == node) {
    node = malloc(sizeof(node_s));
    node->data = 0;
  }
  node->data = realloc(node->data, sizeof(int)*n);
  return node;
}

void
int_node_free(node_s *node) {
  free(node);
}

int
int_stack_full(stack_s *const stack) {
  size_t len = ((int*)stack->top - (int*)stack->node->data);
  return sizeof(int) * (stack->n - 1) == len;
}

void*
int_push_val(stack_s *const stack, void *val) {
  int *top = (int*)stack->top + sizeof(int);
  *top = *(int*)val;
  return top;
}

void*
int_pop_val(stack_s *const stack, void *val) {
  int *top = (int*)stack->top - sizeof(int);
  *(int*)val = *(int*)stack->top;
  return top;
}

void
test_stack_new_free_int(void) {
  stack_s *s = stack_new(0, int_node_new, 4);
  stack_free(s, int_node_free);
}

void
test_stack_push_pop_int(void) {
  stack_s *s = stack_new(0, int_node_new, 4);
  int n = 2*s->n + 1, i = 0;

  printf("stack int push/pop [%zu]\n", s->n);
  printf("---------------------\n");

  while (i++ < n) {
    stack_push(s, &i, int_stack_full, int_node_new, int_push_val);
    printf("%8s %16i\n", "push", i);
  }

  printf("---------------------\n");
  i = 0;
  while (i++ < 2*n) {
    int k = 0;
    int empty = stack_pop(s, &k, int_pop_val);
    if (0 == empty) {
      break;
    }
    printf("%8s %16i\n", "pop", k);
  }

  stack_free(s, int_node_free);
}

int
main(void) {
  test_stack_new_free_int();
  test_stack_push_pop_int();
  
  return 0;
}
