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
void insertionsort(T *arr, size_t start, size_t end) {
	int i = start + 1;
	while (i < end) {
		int j = i;
		while (j > start && arr[j-1] > arr[j]) {
			swap(arr, j, j-1);
			j--;
		}
		i++;
	}
}

template<typename T>
int partition(T *arr, int start, int end) {
	T pivot = arr[end];
	int i = start;
	for (int j = start; j < end; j++) {
		if (arr[j] < pivot) {
			T temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			++i;
		}
	}
	T temp = arr[i];
	arr[i] = arr[end];
	arr[end] = temp;
	return i;
}

template<typename T>
void quicksort(T *arr, int start, int end, int bc) {
	if ((start - end) <= bc) {
		insertionsort(arr, start, end);			
		return;
	}

	int p = partition(arr, start, end);
	quicksort(arr, start, p - 1, bc);
	quicksort(arr, p + 1, end, bc);
}


int main(void) {
	int testData[7] = {6,2,8,7,12,1,5};
	cout << "Test data: ";
	for (int i = 0; i < 7; i++) {
		cout << testData[i] << " ";
	}
	cout << endl;

	quicksort(testData, 0, 7, 4);
	
	cout << "After quicksort(): ";
	for (int i = 0; i < 7; i++) {
		cout << testData[i] << " ";
	}
	cout << endl;

	return 0;
}
