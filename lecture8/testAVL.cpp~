#include <iostream>
#include <string>
#include "BST.hpp"

using namespace std;

int main(void) {

  BST<int> tree;

  tree.insert(3);
  tree.insert(6);
  tree.insert(2);
  tree.insert(7);
  tree.insert(1);
  tree.insert(5);
  tree.insert(4);

  tree.print();
  
  cout << "Is 7 in the tree?: " << tree.search(7) << endl;

  cout << "Removing 7..." << endl;
  tree.remove(7);

  cout << "Is 7 in the tree?: " << tree.search(7) << endl;

  tree.print();

  return 0;
}
