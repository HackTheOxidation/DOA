#include <iostream>
#include <string>
#include "AVL.hpp"

using namespace std;

int main(void) {

  AVL<int> tree;

  tree.insert(10);
  tree.print();
  cout << endl;

  tree.insert(20);
  tree.print();
  cout << endl;

  tree.insert(30);
  tree.print();
  cout << endl;

  tree.insert(25);
  tree.print();
  cout << endl;

  tree.insert(28);
  tree.print();
  cout << endl;

  tree.insert(31);
  tree.print();
  cout << endl;

  return 0;
}
