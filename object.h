#ifndef OBJECT_H
#define OBJECT_H

#include "./bst.h"

#define C 0.42

typedef struct object_t {
  node_t **slots;
  int capacity;
} object_t;

int object_new(struct object_t **obj, int capacity);

int object_getitem(struct object_t *obj, char *key, void **item);

int object_setitem(struct object_t *obj, char *key, void *item);

int object_removeitem(struct object_t *obj, char *key);

void object_free(struct object_t *obj);

#endif
