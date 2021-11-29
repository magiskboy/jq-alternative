#include <stdio.h>

extern void bst_test_suite();

extern void object_test_suite();

int main(int argv, char **args) {
  bst_test_suite();

  object_test_suite();

  printf("PASS\n");

  return 0;
}
