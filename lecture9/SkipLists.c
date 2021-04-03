#include "SkipLists.h"
#include <stdio.h>
#include <stdlib.h>

int searchSkipList(Node* node, void* key) {

  return 0;
}

void insertSkipListNode(Node* node, void* key, void* newValue) {

}

void deleteSkipListNode(Node* node, void* key) {

}

SkipList* createSkipList(unsigned int maxLevel, float P) {
  SkipList* skiplist = (SkipList*) malloc(sizeof(SkipList));
  skiplist->maxLevel = maxLevel;
  skiplist->P = P;
  skiplist->search = &searchSkipList;
  skiplist->insertNode = &insertSkipListNode;
  skiplist->deleteNode = &deleteSkipListNode;

  return skiplist;
}

void deleteSkipList(SkipList* skiplist) {
  free(skiplist);
}
