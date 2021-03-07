#include <iostream>

using namespace std;

int sum(int* ar, int n) {
	if (n == 1) {
		return ar[0];
	} else {
		return ar[n-1] + sum(ar, n-1);
	}
}

int main() {
	int ar[] = {1, 2, 3, 4, 5};

	int result = sum(ar, 5);

	cout << "Result of sum(): " << result << endl;

	return 0;
}
