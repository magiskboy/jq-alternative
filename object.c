#include "./object.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int __hash_function(char *key, int capacity) {
  int sum = 0, i;
  for (int i = 0; i < strlen((char *)key); ++i) {
    sum += (int)key[i];
  }

  double ipart, fpart;

  fpart = modf(sum * C, &ipart);

  return (int)floor(capacity * fpart);
}

int object_new(struct object_t **obj, int capacity) {
  (*obj) = (struct object_t *)malloc(sizeof(struct object_t));
  (*obj)->capacity = capacity;
  (*obj)->slots = (struct node_t **)malloc(sizeof(struct node_t *) * capacity);
  memset((*obj)->slots, 0, capacity * sizeof(struct node_t *));

  return 0;
}

int object_setitem(object_t *obj, char *key, void *item) {
  int index = __hash_function(key, obj->capacity);

  return bst_insert(&obj->slots[index], key, item);
};

int object_getitem(object_t *obj, char *key, void **item) {
  int index = __hash_function(key, obj->capacity);

  struct node_t *target;
  if (!bst_get(obj->slots[index], key, &target))
    return 0;

  *item = malloc(sizeof(target->data));
  memcpy(*item, target->data, sizeof(target->data));

  return 1;
};

int object_removeitem(struct object_t *obj, char *key) {
  int index = __hash_function(key, obj->capacity);

  return bst_remove(&obj->slots[index], key);
}

void object_free(struct object_t *obj) {
  int i;
  for (i = 0; i < obj->capacity; ++i) {
    if (obj->slots[i] != NULL)
      bst_free(obj->slots[i]);
  }
  free(obj);
}
