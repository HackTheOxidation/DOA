#include "SkipLists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  SkipList* skiplist = createSkipList(5, 0.5);

  deleteSkipList(skiplist);
  return 0;
}
