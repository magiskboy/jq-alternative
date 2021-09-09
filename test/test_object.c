#include "../object.h"
#include <assert.h>
#include <string.h>

void object_test_suite() {
  struct object_t *obj;

  object_new(&obj, 2000);
  assert(object_setitem(obj, "name", "Thanh") == 1);
  assert(object_setitem(obj, "age", "23"));

  char *value;
  assert(object_getitem(obj, "name", (void **)&value) == 1);
  assert(strcmp(value, "Thanh") == 0);
  assert(object_getitem(obj, "age", (void **)&value) == 1);
  assert(strcmp(value, "23") == 0);

  assert(object_removeitem(obj, "name") == 1);
  assert(object_getitem(obj, "name", (void **)&value) == 0);

  /* object_free(obj); */
  /* assert(obj == NULL); */
}
