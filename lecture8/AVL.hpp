#ifndef AVL_HPP_
#define AVL_HPP_

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Node {
public:
  Node<T>(const T& data) {
    left = nullptr;
    right = nullptr;
    this->data = data;
  }

  T data;
  Node *left;
  Node *right;
};

template<typename T>
class AVL {
public:
  AVL() {
    root = nullptr; 
  }

  AVL(Node<T> *root) {
    this->root = root;
  }

  void insert(const T& data) {
    insert(this->root, data);
  }

  void remove(const T& data) {
    remove(this->root, nullptr, data);
  }

  bool search(const T& data) {
    return search(this->root, data);
  }

  void print() const {
    print(root, 0);
  }

private:
  Node<T> *root;

  void insert(Node<T>*& root, const T& data) {
    if (!root)
      root = new Node<T>(data);
    else if (root->data < data)
      insert(root->right, data);
    else if (root->data > data)
      insert(root->left, data);
  }

  void remove(Node<T>* root, Node<T>* parent, const T& data) {
    if (!root)
      return;
    else if (data < root->data)
      remove(root->left, root, data);
    else if (data > root->data)
      remove(root->right, root, data);
    else
      removeNode(root, parent);
  }

  void removeNode(Node<T>* node, Node<T>* parent) {
    if (node->left != nullptr && node->right != nullptr) {
      Node<T> *min = node->right;
      Node<T> *minParent = node;
      findMin(min, minParent);

      if (parent->left->data == node->data) {
	parent->left = min;
      } else {
	parent->right = min;
      }
      min->right = node->right;
      min->left = node->left;

      node->left = nullptr;
      node->right = nullptr;
      delete node;
    } else if (node->right != nullptr && node->left == nullptr) {
      if (parent->left->data == node->data) {
	parent->left = node->right;
      } else {
	parent->right = node->right;
      }
      node->right = nullptr;
      delete node;
    } else if (node->left != nullptr && node->right == nullptr) {
      if (parent->left->data == node->data) {
	parent->left = node->left;
      } else {
	parent->right = node->left;
      }
      node->left = nullptr;
      delete node;
    } else {
      if (parent->left->data == node->data) {
	parent->left = nullptr;
      } else {
	parent->right = nullptr;
      }
      delete node;
    }
  }

  void findMin(Node<T>* node, Node<T>* parent) {
    if (node->left == nullptr) {
      parent->left = node->right;
      return;
    } else {
      parent = node;
      node = node->left;
      findMin(node, parent);
    }
  }

  bool search(Node<T>*& root, const T& data) {
    if (!root)
      return false;
    else if (data < root->data)
      return search(root->left, data);
    else if (data > root->data)
      return search(root->right, data);
    else
      return true;
  }

  int height(Node<T>* node) const {
    if (node->left == nullptr && node->right == nullptr) {
      return 1;
    } else if (node->left != nullptr && node->right == nullptr) {
      return 1 + height(node->left);
    } else if (node->left == nullptr && node->right != nullptr) {
      return 1 + height(node->right);
    } else {
      int left = height(node->left);
      int right = height(node->right);

      if (left >= right)
	return 1 + left;
      else
	return 1 + right;
    }
  }

  void print(Node<T>* node, int depth) const {
    string spaces = "";
    for (int i = 0; i < depth; i++)
      spaces = spaces + "   ";

    if (node->right != nullptr) 
      print(node->right, depth + 1);

    cout << spaces << node->data << endl;

    if (node->left != nullptr) 
      print(node->left, depth + 1);
  }

};
#endif
