#include <iostream>

using namespace std;

#ifndef PAIR_H
#define PAIR_H

enum State {EMPTY, OCCUPIED, PREVIOUSLY_USED};

template<typename Key, typename Value>
class Pair {
	public:
		Pair<Key, Value>() {
			this->state = EMPTY;
		}

		Pair<Key, Value>(Key k, Value V) {
			this->k = k;
			this->v = v;

			this->state = OCCUPIED;
		}

		Pair<Key, Value>(State state) {
			this->state = state;
		}

		Key getKey() const {
			return k;
		}

		Value getValue() const {
			return v;
		}

		void setRecord(Key k, Value v) {
			this->k = k;
			this->v = v;

			if (state != OCCUPIED)
				state = OCCUPIED;
		}

		State getState() const {
			return state;
		}

		void changeState(State state) {
			this->state = state;
		}

		void print() const {
			cout << "Key: " << getKey() << ", Value: " << getValue();
		}

	private:
		Key k;
		Value v;
		State state;
};

#endif
