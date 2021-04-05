#include "SkipLists.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand((unsigned) time(NULL));

  SkipList* skiplist = createSkipList(5, 0.5);

  int is1 = searchSkipList(skiplist, 1);
  printf("Is 1 in the list: %d\n", is1);

  insertSkipListNode(skiplist, 1);

  is1 = searchSkipList(skiplist, 1);
  printf("Is 1 in the list: %d\n", is1);

  deleteSkipListNode(skiplist, 1);

  is1 = searchSkipList(skiplist, 1);
  printf("Is 1 in the list: %d\n", is1);

  deleteSkipList(skiplist);
  return 0;
}
