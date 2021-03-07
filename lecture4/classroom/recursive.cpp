#include <iostream>

using namespace std;

// Exercise 1
int factorial(int n) {
	if (n == 0) { 
		return 1;
	} else {
		return n * factorial(n-1);
	}
}

// Exercise 2
void printDownTo1(int n) {
	if (n == 1) {
		cout << "num is " << n << endl;
		return;
	} else {
		cout << "num is " << n << endl;
		printDownTo1(n-1);
	}
}

// Exercise 3
int power(int x, unsigned int exp) {
	if (exp == 0) {
		return 1;
	} else {
		return x * power(x, exp-1);
	}
}

// Exercise 4
int fib(int n) {
	if (n < 2) {
		return n;
	} else {
		return fib(n-1) + fib(n-2);
	}
}

// Exercise 5
void hanoi(int nDisks, int ns, int ne, int nv) {
	if (nDisks > 0) {
		hanoi(nDisks - 1, ns, nv, ne);

		cout << "Move disk " << nDisks << " from pin " << ns << " to pin " << ne << endl;

		hanoi(nDisks - 1, nv, ne, ns);
	}
}

int main() {
	cout << "factorial() - test" << endl;
	cout << "Expected: 120" << endl;
	cout << "Result: " << factorial(5) << endl;

	cout << endl;

	cout << "printDownTo1() - test" << endl;
	cout << "Expected: prints numbers 6 through 1" << endl;
	printDownTo1(6);

	cout << endl;

	cout << "power() - test" << endl;
	cout << "Expected: 1024" << endl;
	cout << "Result: " << power(2, 10) << endl;

	cout << endl;

	cout << "fib() - test" << endl;
	cout << "Expected: 8" << endl;
	cout << "Result: " << fib(6) << endl;

	cout << endl;

	cout << "hanoi() - test" << endl;
	cout << "Expected: see sample in exercise description" << endl;
	hanoi(2, 1, 3, 2);

	return 0;
}
