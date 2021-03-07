#include "Queue.hpp"
#include <iostream>
#include <exception>
#include <list>

using namespace std;

template<typename T>
class ListQueue : public Queue<T> {
	public:
		ListQueue<T>() : l() {
			
		}
		
		bool isEmpty() const {
			return (bool) l.empty();
		}

		T& front() {
			if (isEmpty()) {
				throw out_of_range("ListQueue::front() : Index out of bounds");
			}
			return l.front();
		}

		void pop() {
			if (isEmpty()) {
				throw out_of_range("ListQueue::front() : Index out of bounds");
			}
			l.pop_front();	
		}

		void push(const T& x) {
			l.push_back(x);	
		}
		
	private:
		list<T> l;
};
