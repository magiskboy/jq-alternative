#ifndef BST_H
#define BST_H

#define ul unsigned long

typedef struct node_t {
  void *data;
  ul key;
  struct node_t *left_node;
  struct node_t *right_node;
} node_t;

int bst_create_new_node(struct node_t **t, ul key, void *data,
                        struct node_t *left_node, struct node_t *right_node);

int bst_insert(struct node_t *t, ul key, void *data);

int bst_get(struct node_t *t, ul key, struct node_t **target);

int bst_remove(struct node_t *t, ul key);

#endif
