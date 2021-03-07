#include <iostream>
#include <string>

using namespace std;

int binary_search(int *list, int target, int start, int end) {
	if (start > end) {
		return -1;
	} else {
		int middle = (end + start) / 2;

		if (list[middle] > target) {
			return binary_search(list, target, start, (middle - 1));
		} else if (list[middle] < target) {
			return binary_search(list, target, (middle + 1), end);
		} else {
			return list[middle];
		}
	}
}

int main(void) {

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

	int result = binary_search(arr, 3, 0, 7);

	cout << "Result: " << result << endl;

	return 0;
}
