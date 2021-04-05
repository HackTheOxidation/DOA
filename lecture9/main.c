#include "SkipLists.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand((unsigned) time(NULL));

  SkipList* skiplist;  
  initSkipList(skiplist);

  Node* x = searchSkipList(skiplist, 1);
  if (x) {
    printf("1 is in the list!\n");
  } else {
    printf("1 is NOT in the list\n");
  }

  insertSkipListNode(skiplist, 1, 1);

  x = searchSkipList(skiplist, 1);
  if (x) {
    printf("1 is in the list!\n");
  } else {
    printf("1 is NOT in the list\n");
  }

  deleteSkipListNode(skiplist, 1);

  x = searchSkipList(skiplist, 1);
  if (x) {
    printf("1 is in the list!\n");
  } else {
    printf("1 is NOT in the list\n");
  }

  return 0;
}
