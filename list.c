#include "./list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int create_new_node(struct list_node_t *new_node, void *data,
                    struct list_node_t *next) {
  new_node = (struct list_node_t *)malloc(sizeof(struct list_node_t));
  new_node->data = malloc(sizeof(data));

  if (new_node->data == NULL) {
    perror("Can not allocate memory for list node");
    free(new_node);
    return 0;
  }

  memcpy(new_node->data, data, sizeof(data));
  new_node->next = next;
  return 1;
}

void list_node_free(struct list_node_t *node) {
  free(node->data);
  free(node);
}

int list_getitem(struct list_node_t *head, int pos, void *data) {
  struct list_node_t *current = head;
  int i;
  for (i = 0; i < pos && current != NULL; ++i)
    ;

  if (i > pos)
    return 0;

  data = malloc(sizeof(current->data));
  memcpy(data, current->data, sizeof(current->data));

  return 1;
};

int list_insertitem(struct list_node_t *head, int pos, void *data) {
  struct list_node_t *new_node;
  create_new_node(new_node, data, NULL);

  // insert new node at head
  if (pos == 0) {
    new_node->next = head;
    head = new_node;
    return 1;
  }

  struct list_node_t *prev_node = head;

  int i;
  for (i = 0; i < pos - 1 && prev_node != NULL; ++i) {
    prev_node = prev_node->next;
  }

  if (prev_node == NULL)
    return 0;

  new_node->next = prev_node->next;
  prev_node->next = new_node;

  return 1;
};

int list_removeitem(struct list_node_t *head, int pos) {
  struct list_node_t *deleted = NULL;

  // remove head
  if (pos == 0) {
    deleted = head;
    head = head->next;
    list_node_free(deleted);
    return 1;
  }

  struct list_node_t *previous = head;

  int i;
  for (i = 0; i < pos - 1 && previous != NULL; ++i) {
    previous = previous->next;
  }

  if (previous == NULL)
    return 0;

  deleted = previous->next;
  if (deleted == NULL)
    return 0;
  previous->next = deleted->next;
  list_node_free(deleted);

  return 1;
};

int list_pushitem(struct list_node_t *head, void *data) {
  return list_insertitem(head, 0, data);
};

int list_popitem(struct list_node_t *head, void *data) {
  if (head == NULL)
    return 0;

  struct list_node_t *previous = NULL;
  struct list_node_t *last = head;

  while (last->next != NULL) {
    previous = last;
    last = last->next;
  }

  // pop head
  if (previous == NULL) {
    data = malloc(sizeof(last->data));
    memcpy(data, last->data, sizeof(last->data));
    list_node_free(last);
  } else {
    data = malloc(sizeof(previous->data));
    memcpy(data, previous->data, sizeof(previous->data));
    list_node_free(previous);
  }
  return 1;
};
