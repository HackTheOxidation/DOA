#include "SkipListGeeksforGeeks.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(void) {
	SkipListGeeksforGeeks list(5, 0.5);
	cout << "Empty? " << list.isEmpty() << endl;
	cout << "Is 1 in the list? " << list.search(1) << endl;

	list.insert(1);
	cout << "Empty? " << list.isEmpty() << endl;
	cout << "Is 1 in the list? " << list.search(1) << endl;

	list.remove(1);
	cout << "Empty? " << list.isEmpty() << endl;
	cout << "Is 1 in the list? " << list.search(1) << endl;

	return 0;
}
