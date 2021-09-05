#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAP_ELEMENT 200000
#define C 0.42

typedef struct node_t {
  struct node_t *next;
  void *key;
  void *data;
} node_t;

int __hash_function(void *key) {
  int sum = 0, i;
  for (int i = 0; i < strlen((char *)key); ++i) {
    sum += (int)((char *)key)[i];
  }
  double ipart, fpart;
  fpart = modf(sum * C, &ipart);
  return (int)floor(MAX_MAP_ELEMENT * fpart);
}

void create_new_node(struct node_t **head, void *key, void *data) {
  (*head) = (struct node_t *)malloc(sizeof(node_t));
  (*head)->key = (void *)malloc(sizeof(key));
  memcpy((*head)->key, key, sizeof(key));
  (*head)->data = (void *)malloc(sizeof(data));
  memcpy((*head)->data, data, sizeof(data));
}

void list_push(struct node_t **head, void *key, void *data) {
  if (head == NULL) {
    create_new_node(head, key, data);
    return;
  }

  struct node_t *new_node;
  create_new_node(&new_node, key, data);
  new_node->next = (*head);
  (*head) = new_node;
}

void list_find(struct node_t *head, void *key, void **data) {
  if (head == NULL)
    return;

  struct node_t *current = head;
  while (current != NULL) {
    if (strcmp(key, current->key) == 0) {
      *data = (void *)malloc(sizeof(current->data));
      memcpy(*data, current->data, sizeof(current->data));
      break;
    }
    current = current->next;
  }
};

void map_set(struct node_t **map, void *key, void *data) {
  int index = __hash_function(key);
  list_push(&map[index], key, data);
};

void map_get(struct node_t **map, void *key, void **data) {
  int index = __hash_function(key);
  list_find(map[index], key, data);
};

int main(int argv, char **args) {
  struct node_t *map[MAX_MAP_ELEMENT];
  map_set(map, "name", "Nguyen Khac Thanh");
  map_set(map, "age", "23");
  map_set(map, "job", "Programmer");
  return 0;
}
