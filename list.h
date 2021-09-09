#ifndef LIST_H
#define LIST_H

typedef struct list_node_t {
  void *data;
  struct list_node_t *next;
} list_node_t;

int list_insertitem(struct list_node_t *head, int pos, void *data);

int list_getitem(struct list_node_t *head, int pos, void *data);

int list_removeitem(struct list_node_t *head, int pos);

int list_popitem(struct list_node_t *head, void *data);

int list_pushitem(struct list_node_t *head, void *data);

#endif
