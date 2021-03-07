#include <iostream>
#include <string>
#include <iterator>

using namespace std;

string table[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void printPhonenumber(int numbers[], int n, string soFar) {
	if (n == 0) {
		cout << soFar;
		return;
	} else {
		string letters = table[numbers[0]];
		for (char letter : letters) {
			printPhonenumber(numbers + 1, n - 1, soFar + letter);
			cout << endl;
		}
	}
}

int main(void) {

	int phoneNumber[] =  { 3, 4 };

	printPhonenumber(phoneNumber, 2, "");

	return 0;
}
