#ifndef MINHEAP_HPP_
#define MINHEAP_HPP_

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class MinHeap {
public:
  MinHeap(const unsigned int capacity) {
    arr = new T[capacity];
    currentSize = 0;
    currentCapacity = capacity;
  }

  MinHeap(T *array, const unsigned int capacity) {
    arr = new T[capacity];
    currentSize = capacity;
    currentCapacity = capacity;
    buildHeap(array);
  }

  ~MinHeap() {
    delete[] arr;
  }

  void insert(T elem) {
    // Resize if capacity has been reached
    if (currentSize == currentCapacity) {
      T *tempArr = new T[2*currentCapacity];

      for (int i = 0; i < currentCapacity; i++) {
	tempArr[i] = arr[i];
      }

      currentCapacity = 2*currentCapacity;
      arr = tempArr;
    }

    int i = currentSize;
    arr[i] = elem;
    currentSize++;

    heapUp(i);
  }

  T getMin() {
    if (currentSize == 0)
      return NULL;
    else
      return arr[0];
  }

  T removeMin() {
    if (currentSize == 0)
      return NULL;

    T rootElem = arr[0];
    arr[0] = arr[currentSize - 1];
    heapDown(0);

    return rootElem;
  }

  unsigned int size() const {
    return currentSize;
  }

  unsigned int capacity() const {
    return currentCapacity;
  }
    
  void print() const {
    for (int i = 0; i < currentSize; i++) {
      cout << arr[i] << " ";
    }
  }

private:
  void buildHeap(T *array) {
    for (int i = 0; i < currentSize; i++) {
      arr[i] = array[i];

      heapUp(i);
    }
  }

  void heapUp(unsigned int i) {
    if (i == 0)
      return;

    if (arr[i] < arr[getParent(i)]) {
      swap(i, getParent(i));
      heapUp(getParent(i));
    }
  }

  void heapDown(unsigned int i) {
    unsigned int leftChild = getLeftChild(i);
    unsigned int rightChild = getRightChild(i);
    unsigned int smallest = i;

    if (leftChild >= currentSize
	|| rightChild >= currentSize)
      return;

    if (arr[i] > arr[leftChild]) {
      smallest = leftChild;
    }

    if (arr[i] > arr[rightChild]) {
      smallest = rightChild;
    }

    if (smallest != i) {
      swap(i, smallest);
      heapDown(smallest);
    }
  }

  unsigned int getParent(unsigned int i) {
      return (i - 1) / 2;
  }

  unsigned int getLeftChild(unsigned int i) {
    return (i * 2) + 1;
  }

  unsigned int getRightChild(unsigned int i) {
    return (i * 2) + 2;
  }

  void swap(unsigned int i, unsigned int j) {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  
  T *arr;
  unsigned int currentSize;
  unsigned int currentCapacity;
  
};

template<typename T>
T kth_min(unsigned int k, T *arr, unsigned int size) {
  MinHeap<T> heap(arr, size);

  T min;

  for (int i = 0; i < k; i++) {
    min = heap.removeMin();
  }

  return min;
}

#endif
