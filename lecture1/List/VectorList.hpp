#include "List.hpp"
#include <iostream>
#include <exception>
#include <vector>

using namespace std;

template<typename T>
class VectorList : public List<T> {
	public:
		VectorList<T>() : v() {
			
		}

		void headInsert(const T& x) {
			v.emplace(v.begin(), x);
		}

		void headRemove() {
			v.erase(v.begin());
		}

		unsigned int length() {
			return v.size();
		}

		void clear() {
			if (length() == 0) {
				return;
			}

			v.clear();
		}

		T& at(unsigned int i) {
			if (i >= length()) {
				throw out_of_range("VectorList::at() : Index out of bounds");
			}

			return v[i];
		}

		void remove(unsigned int index) {
			if (index >= length()) {
				throw out_of_range("VectorList::remove() : Index out of bounds");
			}
			
			v.erase(v.begin() + index);
		}

		void insert(const T& x, unsigned int index) {
			if (index >= length()) {
				throw out_of_range("VectorList::insert() : Index out of bounds");	
			}
			
			v.emplace(v.begin() + index);
		}

	private:
		vector<T> v;
};
