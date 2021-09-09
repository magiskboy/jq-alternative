extern void bst_test_suite();

extern void object_test_suite();

int main(int argv, char **args) {
  bst_test_suite();

  object_test_suite();

  return 0;
}
