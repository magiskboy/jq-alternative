#ifndef BST_H
#define BST_H

typedef struct node_t {
  void *data;
  char *key;
  struct node_t *left_node;
  struct node_t *right_node;
} node_t;

int bst_create_new_node(struct node_t **t, char *key, void *data,
                        struct node_t *left_node, struct node_t *right_node);

int bst_insert(struct node_t **t, char *key, void *data);

int bst_get(struct node_t *t, char *key, struct node_t **target);

int bst_remove(struct node_t **t, char *key);

void bst_free(struct node_t *t);

#endif
