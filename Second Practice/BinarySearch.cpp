#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int elem) {
	if (high >= low){
		int mid = (high + low) / 2;

		if (arr[mid] == elem)
			return mid;

		if (arr[mid] > elem)
			return binarySearch(arr, low, mid - 1, elem);

		return binarySearch(arr, mid + 1, high, elem);
	}

	return -1;
}

void main() {
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, size - 1 , 1);

	(result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;
}
