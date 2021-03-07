#include "List.hpp"
#include <iostream>

using namespace std;


template<typename T>
struct Node {
    T data;
    Node<T> *next;
};


template<typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() {
            this->head = nullptr;
        }

        LinkedList(Node<T> *head) {
            this->head = head;
        }

        void headInsert(const T& x) override {
            if (length() == 0) {
                this->head = new Node<T>{x, nullptr};
            } else {
                Node<T> * tmp = new Node<T>{x, this->head};
                this->head = tmp;
            }
        }

        void headRemove() override {
            if (length() == 0)
                return;
            else {
                Node<T> * tmp = this->head;
                this->head = this->head->next;
                delete tmp;
            }
        }

        void insert(const T& x, unsigned int index) override {
                if (index < length()) {
                    Node<T> * nodePtr = this->head;

                    for (int i = 0; i < index-1; i++) {
                        nodePtr = nodePtr->next;
                    }

                    Node<T> * tail = nodePtr->next;
                    nodePtr->next = new Node<T>{x, tail};
                } else {
                    throw exception();
                }
        }

        void remove(unsigned int index) override {
                if (index < length()) {
                    Node<T> * nodePtr = this->head;

                    for (int i = 0; i < index-1; i++) {
                        nodePtr = nodePtr->next;
                    }

                    Node<T> * tail = nodePtr->next->next;
                    nodePtr->next = tail;
                } else {
                    throw out_of_range("LinkedList::remove() : Index out of bounds");
                }
        }

        unsigned int length() override {
            unsigned int len = 0;
            Node<T> * nodePtr = this->head;

            while (nodePtr != nullptr) {
                len++;
                nodePtr = nodePtr->next;
            }

            return len;
        }

        void clear() override {
            Node<T> * tmp = this->head;
            this->head = nullptr;
            delete tmp;
        }

        T& at(unsigned int i) override {
		if (i >= length()) {
			throw out_of_range("LinkedList::at() : Index out of bounds");
		}

		Node<T> * tmp = this->head;
		for (int j = 0; j < i; j++) {
			tmp = tmp->next;
		}

		return tmp->data;
	}
        

    private:
        Node<T> *head;
};
