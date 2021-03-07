#include <iostream>

using namespace std;

void triangle(unsigned int m, unsigned int n) {
	if (m > n) {
		return;
	} else {
		for (int i = 0; i < m; i++) 
			cout << '*';
		
		cout << endl;

		triangle(m + 1, n);

		for (int i = 0; i < m; i++) 
			cout << '*';
		
		cout << endl;
	}
}


int main() {
	triangle(4,6);

	return 0;
}
