#include "../bst.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void bst_test_suite() {
  struct bst_node_t **bst;
  *bst = NULL;
  int retval;
  assert(bst_insert(bst, "1", "foo") == 1);
  assert(bst_insert(bst, "2", "bar") == 1);
  assert(bst_insert(bst, "3", "baz") == 1);
  assert(bst_insert(bst, "4", "foz") == 1);

  struct bst_node_t *target;
  assert(bst_get(*bst, "3", &target) == 1);
  assert(strcmp(target->key, "3") == 0);
  assert(strcmp((char *)target->data, "baz") == 0);

  assert(bst_insert(bst, "4", "lmao") == 1);
  assert(bst_get(*bst, "4", &target) == 1);
  assert(strcmp((char *)target->data, "lmao") == 0);

  assert(bst_remove(bst, "3") == 1);
  assert(bst_get(*bst, "3", &target) == 0);
}
