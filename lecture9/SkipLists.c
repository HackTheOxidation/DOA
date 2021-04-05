#include "SkipLists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive helper method for search
int find(Node* x, int searchKey, unsigned int level) {
  if (x && x->forward[level] && x->forward[level]->key == searchKey) {
    x = x->forward[0];
    return 1;
  } else if (x->forward[level] && x->forward[level]->key < searchKey) {
    return find(x->forward[level], searchKey, level);
  } else {
    if (level == 0)
      return 0;

    return find(x, searchKey, level - 1);
  }
}

int searchSkipList(SkipList* list, int searchKey) {
  // Original iterative method
  Node* x = list->header;
  for (int i = list->level; i >= 0; i--) {
    while (x->forward[i] &&
        x->forward[i]->key < searchKey)
      x = x->forward[i];
  }
  x = x->forward[0];
  
  return (x && x->key == searchKey);
  //return find(list->header, searchKey, list->level);
}

void insertSkipListNode(SkipList* list, int newValue) {
  Node** update = malloc(sizeof(Node*) * (list->maxLevel + 1));
  memset(update, 0, sizeof(Node*) * (list->maxLevel + 1));
  Node* x = list->header;
  for (int i = list->level; i >= 0; i--) {
    while (x->forward[i] != NULL &&
        x->forward[i]->key < newValue)
      x = x->forward[i];
    update[i] = x;
  }
  x = x->forward[0];
  if (x == NULL || x->key != newValue) {
    int lvl = randomLevel(list);
    if (lvl > list->level) {
      for (int i = list->level + 1; i < lvl+1; i++)
        update[i] = list->header;
      list->level = lvl;
    }
    x = makeNode(newValue, lvl);
    for (int i = 0; i <= lvl; i++) {
      x->forward[i] = update[i]->forward[i];
      update[i]->forward[i] = x;
    }
    printf("Successfully Inserted key %d\n", newValue);
  }
  free(update);
}

void deleteSkipListNode(SkipList* list, int searchKey) {
  Node** update = malloc(sizeof(Node*) * (list->maxLevel + 1));
  memset(update, 0, sizeof(Node*) * (list->maxLevel + 1));
  Node* x = list->header;
  for (int i = list->level; i >= 0; i--) {
    while (x->forward[i] != NULL && x->forward[i]->key < searchKey)
      x = x->forward[i];
    update[i] = x;
  }
  x = x->forward[0];
  if (x != NULL && x->key == searchKey) {
    for (int i = 0; i < list->level; i++) {
      if (update[i]->forward[i] != x)
        break;
      update[i]->forward[i] = x->forward[i];
    }
    free(x);
    while (list->level > 0 &&
        list->header->forward[list->level] == NULL)
      list->level--;
    printf("Successfully deleted key %d\n", searchKey);
  }
  free(update);
}

unsigned int randomLevel(SkipList* skiplist) {
  unsigned int level = 0;
  int r = rand(); 
  while (r < skiplist->P && level < skiplist->maxLevel) {
    level++;
    r = rand();
  }

  return level;
}

SkipList* createSkipList(unsigned int maxLevel, float P) {
  SkipList* list = (SkipList*) malloc(sizeof(SkipList));
  list->maxLevel = maxLevel;
  list->P = P;
  list->header = makeNode(-1, maxLevel);

  return list;
}

void deleteSkipList(SkipList* list) {
  free(list);
}

Node* makeNode(int key, unsigned int level) {
  Node* node = (Node*) malloc(sizeof(Node) * (level + 1));
  node->key = key;
  memset(node->forward, 0, sizeof(Node*) * (level + 1));
  return node;
}
