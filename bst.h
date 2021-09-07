#ifndef BST_H
#define BST_H

typedef struct bst_node_t {
  void *data;
  char *key;
  struct bst_node_t *left_node;
  struct bst_node_t *right_node;
} node_t;

int bst_create_new_node(struct bst_node_t **t, char *key, void *data,
                        struct bst_node_t *left_node,
                        struct bst_node_t *right_node);

int bst_insert(struct bst_node_t **t, char *key, void *data);

int bst_get(struct bst_node_t *t, char *key, struct bst_node_t **target);

int bst_remove(struct bst_node_t **t, char *key);

void bst_free(struct bst_node_t *t);

#endif
