#ifndef SKIPLISTS_H_
#define SKIPLISTS_H_

typedef struct Node {
  int key;
  struct Node* forward[]; 
} Node;

typedef struct SkipLists {
  unsigned int maxLevel;
  float P;
  unsigned int level;
  struct Node* header; 
} SkipList;

int searchSkipList(SkipList* list, int searchKey);
void insertSkipListNode(SkipList* list, int newValue);
void deleteSkipListNode(SkipList* list, int searchKey);
unsigned int randomLevel(SkipList* list);
SkipList* createSkipList(unsigned int maxLevel, float P);
void deleteSkipList(SkipList* list);
struct Node* makeNode(int key, unsigned int level);

#endif
