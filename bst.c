#include "./bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bst_create_new_node(struct node_t **t, ul key, void *data,
                        struct node_t *left_node, struct node_t *right_node) {
  (*t) = (struct node_t *)malloc(sizeof(struct node_t));
  if ((*t) == NULL)
    return 0;

  (*t)->key = key;
  (*t)->left_node = left_node;
  (*t)->right_node = right_node;

  (*t)->data = (void *)malloc(sizeof(data));
  if ((*t)->data == NULL) {
    free((void *)(*t));
    return 0;
  }
  memcpy((void *)(*t)->data, data, sizeof(data));

  return 0;
}

int bst_insert(struct node_t *root, ul key, void *data) {
  struct node_t *new_node;

  if (!bst_create_new_node(&new_node, key, data, NULL, NULL))
    return 0;

  if (root == NULL) {
    root = new_node;
    return 1;
  }

  struct node_t *current = root;
  while (1) {
    if (new_node->key <= current->key) {
      if (current->left_node) {
        current = current->left_node;
      } else {
        current->left_node = new_node;
        break;
      }
    } else {
      if (current->right_node) {
        current = current->right_node;
      } else {
        current->right_node = new_node;
        break;
      }
    }
  }

  return 1;
};

int bst_get(struct node_t *root, ul key, struct node_t **target) {
  struct node_t *current = root;
  while (current->key != key && current != NULL) {
    current = key <= current->key ? current->left_node : current->right_node;
  }

  if (current == NULL)
    return 0;

  (*target) = current;
  return 1;
};

void merge_grandparent_to_grandchild(struct node_t *parent,
                                     struct node_t *current) {
  struct node_t *grandchild =
      current->left_node != NULL ? current->left_node : current->right_node;

  if (current->key <= parent->key)
    parent->left_node = grandchild;
  else
    parent->right_node = grandchild;
}

ul find_min(struct node_t *root) {
  struct node_t *current = root;
  while (current->left_node != NULL) {
    current = current->left_node;
  }
  return current->key;
}

int bst_remove(struct node_t *root, ul key) {
  struct node_t *deleted = root, *parent = NULL;
  while (deleted->key != key && deleted != NULL) {
    parent = deleted;
    deleted = key < deleted->key ? deleted->left_node : deleted->right_node;
  }

  if (deleted == NULL)
    return 0;

  if (deleted->left_node != NULL && deleted->right_node != NULL) {
    ul min_key = find_min(deleted);
    deleted->key = min_key;
    if (!bst_remove(deleted, min_key))
      return 0;
  } else {
    merge_grandparent_to_grandchild(parent, deleted);
  }

  free(deleted->data);
  free((void *)deleted);

  return 1;
};
