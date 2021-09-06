#include "./bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int key_cmp(char *left, char *right) {
  // if left is less or equal than right then return 1
  return strcmp(left, right) < 0;
}

void free_node(struct node_t *node) {
  free(node->data);
  free(node->key);
  free(node);
}

void merge_grandparent_to_grandchild(struct node_t *parent,
                                     struct node_t *current) {

  // delete root
  if (parent == NULL)
    return;

  struct node_t *grandchild =
      current->left_node != NULL ? current->left_node : current->right_node;

  if (current->key <= parent->key)
    parent->left_node = grandchild;
  else
    parent->right_node = grandchild;
}

char *find_min(struct node_t *root) {
  struct node_t *current = root;
  while (current->left_node != NULL) {
    current = current->left_node;
  }
  return current->key;
}

int bst_create_new_node(struct node_t **t, char *key, void *data,
                        struct node_t *left_node, struct node_t *right_node) {
  (*t) = (struct node_t *)malloc(sizeof(struct node_t));
  if ((*t) == NULL)
    return 0;
  (*t)->key = (char *)malloc(sizeof(key));
  strcpy((*t)->key, key);
  (*t)->left_node = left_node;
  (*t)->right_node = right_node;

  (*t)->data = malloc(sizeof(data));
  if ((*t)->data == NULL) {
    free_node(*t);
    return 0;
  }
  memcpy((void *)(*t)->data, data, sizeof(data));

  return 1;
}

int bst_insert(struct node_t **root, char *key, void *data) {
  struct node_t *new_node;

  if (!bst_create_new_node(&new_node, key, data, NULL, NULL)) {
    perror("Can't allocate memory for the new node");
    return 0;
  }

  if (*root == NULL) {
    *root = new_node;
    return 1;
  }

  struct node_t *current = *root;
  while (1) {
    if (strcmp(new_node->key, current->key) == 0) {
      memcpy(current->data, data, sizeof(data));
      free_node(new_node);
      return 1;
    }

    if (key_cmp(new_node->key, current->key)) {
      if (current->left_node) {
        current = current->left_node;
      } else {
        current->left_node = new_node;
        return 1;
      }
    } else {
      if (current->right_node) {
        current = current->right_node;
      } else {
        current->right_node = new_node;
        return 1;
      }
    }
  }
  return 0;
};

int bst_get(struct node_t *root, char *key, struct node_t **target) {
  struct node_t *current = root;
  while (current != NULL && strcmp(key, current->key) != 0) {
    current =
        key_cmp(key, current->key) ? current->left_node : current->right_node;
  }

  if (current == NULL)
    return 0;

  (*target) = current;
  return 1;
};

int bst_remove(struct node_t **root, char *key) {
  struct node_t *deleted = *root, *parent = NULL;
  while (deleted != NULL && strcmp(key, deleted->key) != 0) {
    parent = deleted;
    deleted =
        key_cmp(key, deleted->key) ? deleted->left_node : deleted->right_node;
  }

  if (deleted == NULL)
    return 0;

  if (deleted->left_node != NULL && deleted->right_node != NULL) {
    char *min_key = find_min(deleted);
    deleted->key = min_key;
    if (!bst_remove(&deleted, min_key))
      return 0;
  } else {
    merge_grandparent_to_grandchild(parent, deleted);
  }

  free_node(deleted);

  return 1;
};

void bst_free(struct node_t *root) {
  if (root == NULL)
    return;

  bst_free(root->left_node);
  bst_free(root->right_node);
  free_node(root);
}
