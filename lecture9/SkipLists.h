#ifndef SKIPLISTS_H_
#define SKIPLISTS_H_

#define MAXLEVEL 6

typedef struct Node {
  int key;
  int value;
  struct Node** forward; 
} Node;

typedef struct SkipLists {
  int level;
  int size;
  struct Node* header; 
} SkipList;

Node* searchSkipList(SkipList* list, int searchKey);
int insertSkipListNode(SkipList* list, int key, int value);
int deleteSkipListNode(SkipList* list, int key);
static int randomLevel();
SkipList* initSkipList(SkipList* list);

#endif
