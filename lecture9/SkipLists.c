#include "SkipLists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Recursive helper method for search
Node* find(Node* x, int key, unsigned int level) {
  if (x && x->forward[level] && x->forward[level]->key == key) {
    return x = x->forward[1];
  } else if (x->forward[level] && x->forward[level]->key < key) {
    return find(x->forward[level], key, level);
  } else {
    if (level == 1)
      return NULL;

    return find(x, key, level - 1);
  }
}

Node* searchSkipList(SkipList* list, int key) {
  // Original Iterative Search Method
  /*
  Node* x = list->header;
  for (int i = list->level; i >= 1; i--) {
    while (x->forward[i]->key < key)
      x = x->forward[i];
  }
  if (x->forward[1]->key == key) {
    return x->forward[1];
  } else {
    return NULL;
  }
  return NULL;
  */
  return find(list->header, key, list->level);
}

int insertSkipListNode(SkipList* list, int key, int value) {
  Node* update[MAXLEVEL + 1];
  Node* x = list->header;
  int level;
  for (int i = list->level; i >= 1; i--) {
    while (x->forward[i]->key < key)
      x = x->forward[i];
    update[i] = x;
  }
  x = x->forward[1];

  if (key == x->key) {
    x->value = value;
    return 0;
  } else {
    level = randomLevel();
    if (level > list->level) {
      for (int i = list->level+1; i <= level; i++) {
        update[i] = list->header;
      }
      list->level = level;
    }

    x = (Node*) malloc(sizeof(Node));
    x->key = key;
    x->value = value;
    x->forward = (Node**) malloc(sizeof(Node*) * (level + 1));
    for (int i = 1; i <= level; i++) {
      x->forward[i] = update[i]->forward[i];
      update[i]->forward[i] = x;
    }
  }
  return 0;
}

int deleteSkipListNode(SkipList* list, int key) {
  Node* update[MAXLEVEL + 1];
  Node* x = list->header;
  for (int i = list->level; i >= 1; i--) {
    while (x->forward[i]->key < key) 
      x = x->forward[i];
    update[i] = x;
  }

  x = x->forward[1];
  if (x->key == key) {
    for (int i = 1; i <= list->level; i++) {
      if (update[i]->forward[i] != x)
        break;
      update[i]->forward[i] = x->forward[i];
    }
    if (x) {
      free(x->forward);
      free(x);
    }
    while (list->level > 1 && list->header->forward[list->level] == list->header)
      list->level--;
    return 0;
  }
  return 1;
}

static int randomLevel() {
  int level = 1;
  while (rand() < RAND_MAX/2 && level < MAXLEVEL) {
    level++;
  }

  return level;
}

SkipList* initSkipList(SkipList* list) {
  Node* header = (Node*) malloc(sizeof(struct Node));
  list->header = header;
  header->key = INT_MAX;
  header->forward = (Node**) malloc(sizeof(Node*) * (MAXLEVEL + 1));
  for (int i = 0; i <= MAXLEVEL; i++) {
    header->forward[i] = list->header;
  }

  list->level = 1;
  list->size = 0;
  
  return list;
}

