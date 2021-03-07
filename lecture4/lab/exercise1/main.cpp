#include <iostream>

using namespace std;

bool search(int x, int* ar, int n) {
	if (n == 0) {
		return ar[0] == x ? true : false;
	} else {
		return (ar[0] == x ? true : false) || search(x, ar+1, n-1);
	}
}

int main() {
	int ar[] = {1, 2, 3, 4, 5};

	cout << "search() - test" << endl;
	cout << "Expected: true" << endl;
	cout << "Result: " << search(3, ar, 5) << endl;

	cout << endl;

	return 0;
}
