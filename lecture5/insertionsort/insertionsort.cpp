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
void insertionsort(T *arr, size_t len) {
	int i = 1;
	while (i < len) {
		int j = i;
		while (j > 0 && arr[j-1] > arr[j]) {
			swap(arr, j, j-1);
			j--;
		}
		i++;
	}
}

int main(void) {
	int testData[7] = {6, 2, 8, 7, 12, 1, 5};

	cout << "Test data: ";
	for (int i = 0; i < 7; i++) {
		cout << testData[i] << " ";
	}
	cout << endl;

	insertionsort(testData, 7);

	cout << "After insertionsort: ";
	for (int i = 0; i < 7; i++) {
		cout << testData[i] << " ";
	}
	cout << endl;

	return 0;
}
