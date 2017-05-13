
#ifndef _LIST_H_
#define _LIST_H_

#include <stddef.h>

typedef struct list_node {
	void *data;
	struct list_node *next;
} list_node;

typedef struct list {
	size_t size;
	list_node *head;
	list_node *tail;
} list;


typedef void (*list_node_free)(list_node *node); 
typedef list_node* (*list_node_new)(void *data);

list* list_new(list *lst);
void list_free(list *lst, list_node_free free_node);

list* list_where(list *lst, list_node *node);

list* list_append(list *lst, list_node_new new_node, void *data);
list* list_push(list *lst, list_node_new new_node, void *data);
list* list_insert(list *lst, void *data, list_node *where);


#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_empty(list) (0 == (list)->head)

#define _unused_(x) ((void)(x))

#endif
