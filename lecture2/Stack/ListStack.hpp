#include "LinkedList.hpp"
#include "Stack.hpp"
#include <iostream>

using namespace std;

template <typename T>
class ListStack : public Stack<T> {
	public:

		ListStack<T>() {

		}

		T top() {
			return list.at(0);
		}

		T pop() {
			T res = this->top();
			list.headRemove();
			return res;
		}

		void push(const T& item) {
			list.headInsert(item);
		}

		bool isEmpty() {
			return list.length() == 0 ? true : false;
		}

	private:
		LinkedList<T> list;
};
