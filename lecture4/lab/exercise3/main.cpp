#include <iostream>

using namespace std;

void bookletPrint(int startPage, int endPage) {
	if (startPage > endPage) {
		return;
	} else {
		cout << "Sheet " << " contains pages " 
			<< startPage << ", " << (startPage + 1) << ", "
			<< (endPage - 1) << ", " << endPage << "." << endl;

		bookletPrint(startPage+2, endPage-2);
	}
}

int main() {
	bookletPrint(1, 8);

	return 0;
}
