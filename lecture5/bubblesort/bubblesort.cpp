#include <iostream>
#include <string>

using namespace std;

template<typename T>
void swap(T *arr, size_t i, size_t j) {
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template<typename T>
void bubblesort(T *arr, size_t len) {
	bool swapped = false;
	for (int i = 0; i < len; i++) {

		for (int j = 0; j < len-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr, j, j+1);
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}

}

int main(void) {
	int testData[7] = {6,2,8,7,12,1,5};

	cout << "Test data: ";
	for (int i = 0; i < 7; i++) {
		cout << testData[i] << " ";
	}
	cout << endl;

	bubblesort(testData, 8);

	cout << "After bubblesort(): ";
	for (int i = 0; i < 7; i++) {
		cout << testData[i] << " ";
	}
	cout << endl;

	return 0;
}
