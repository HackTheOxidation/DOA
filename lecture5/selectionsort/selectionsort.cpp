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
void selectionsort(T *arr, size_t len) {
	for (int i = 0; i < len; i++) {
		int min = i;
		for (int j = i; j < len; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(arr, i, min);
	}
}

int main(void) {
	int testData[7] = {6,2,8,7,12,1,5};

	cout << "Test data: ";
	for (int i = 0; i < 7; i++) {
		cout << testData[i] << " ";
	}
	cout << endl;

	selectionsort(testData, 7);

	cout << "After selectionsort(): ";
	for (int i = 0; i < 7; i++) {
		cout << testData[i] << " ";
	}
	cout << endl;

	return 0;
}
