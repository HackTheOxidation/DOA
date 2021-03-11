#include "MinHeap.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int testData[6] = {6, 5, 4, 3, 2, 1};

  cout << "---MinHeap Test---\nTest data: ";
  for (int i = 0; i < 6; i++) {
    cout << testData[i] << " ";
  }
  cout << endl;

  MinHeap<int> heap(testData, 6);

  cout << "After heapification: ";
  heap.print();
  cout << endl;

  heap.insert(7);
  cout << "After insertion: ";
  heap.print();
  cout << endl << "Size: " << heap.size() << ", Capacity: " << heap.capacity();
  cout << endl << endl;

  cout << "---K'th-select (min) Test---" << endl;

  int k3 = kth_min(3, testData, 6);

  cout << "Result - Third smallest: " << k3 << endl;

  return 0;
}
    
