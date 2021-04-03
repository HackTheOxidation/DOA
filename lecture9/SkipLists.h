#ifndef SKIPLISTS_H_
#define SKIPLISTS_H_

typedef struct SkipListNode {
  void** nodes; 
  void* value;
} Node;

int searchSkipList(Node* node, void* key);
void insertSkipListNode(Node* node, void* key, void* newValue);
void deleteSkipListNode(Node* node, void* key);
unsigned int randomLevel();

typedef struct SkipLists {
  unsigned int maxLevel;
  float P;
  Node* sentinel; 
  int (*search)(Node*, void*);
  void (*insertNode)(Node*, void*, void*);
  void (*deleteNode)(Node*, void*);
} SkipList;

SkipList* createSkipList(unsigned int maxLevel, float P);
void deleteSkipList(SkipList* skiplist);

#endif
