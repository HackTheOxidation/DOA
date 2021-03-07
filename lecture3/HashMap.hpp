#include "Pair.h"
#include <iostream>

#ifndef HASHMAP_H
#define HASHMAP_H

template<typename Key, typename Value>
class HashMap {
	public:
		HashMap<Key, Value>() {
			this->capacity = 10;
			this->size = 0;

			records = new Pair<Key, Value>*[capacity];

			for (int i = 0; i < capacity; i++) {
				records[i] = new Pair<Key, Value>(EMPTY);
			}
		}

		HashMap<Key, Value>(int capacity) {
			if (capacity < 1) 
				capacity = 10;
			else
				this->capacity = capacity;

			this->size = 0;

			records = new Pair<Key, Value>*[capacity];

			for (int i = 0; i < capacity; i++) {
				records[i] = new Pair<Key, Value>(EMPTY);
			}
		}

		int getSize() const {
			return size;
		}

		int getCapacity() const {
			return capacity;
		}

		double getLoadFactor() const {
			return ((double) size) / capacity;
		}

		void insert(Key k, Value v) {
			if (getLoadFactor() > 0.65)
				rehash();

			int i = hash(k);

			if (records[i]->getState() == OCCUPIED) {
				for (int j = i + 1; j != i; j++) {
					if (j == capacity) {
						j = 0;
						continue;
					} else {
						if (records[j]->getState() != OCCUPIED) {
							records[j]->setRecord(k, v);
						} else
							continue;
					}
				}
			} else {
				records[i]->setRecord(k, v);
			}

			size = size + 1;
		}

		bool search(Key k) {
			int i = hash(k);

			if (records[i]->getKey() == k) {
				return true;
			} else {
				for (int j = i + 1; j != i; j++) {
					if (j == capacity) {
						j = 0;
						continue;
					}

					if (records[j]->getKey() == k) {
						return true;
					}
				}
			}

			return false;
		}

		Value remove(Key k) {
			int i = hash(k);

			if (records[i]->getKey() == k) {
				size = size - 1;
				Value target = records[i]->getValue();
				records[i] = new Pair<Key, Value>(PREVIOUSLY_USED);
				return target;
			} else {
				for (int j = i + 1; j != i; j++) {
					if (j == capacity) {
						j = 0;
						continue;
					}

					if (records[j]->getKey() == k) {
						size = size - 1;
						Value target = records[j]->getValue();
						records[j] = new Pair<Key, Value>(PREVIOUSLY_USED);
						return target;
					}
				}
			}

			return NULL;
		}


	private:
		int size;
		int capacity;
		Pair<Key, Value> **records;

		int hash(Key k) {
			return (37*k + 41) % capacity;
		}

		void rehash() {
			int tcapacity = 2 * capacity;

			Pair<Key, Value> **trecords = records;

			records = new Pair<Key, Value>*[tcapacity];

			for (int i = 0; i < capacity; i++) {
				insert(trecords[i]->getKey(), trecords[i]->getValue());
			}

			capacity = tcapacity;

			delete[] trecords;
		}
};

#endif
