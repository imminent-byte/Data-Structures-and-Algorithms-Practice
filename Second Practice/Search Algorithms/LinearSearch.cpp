#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int elem) {
	for (int i = 0; i < size; i++)
		if (arr[i] == elem)
			return i;
	return -1;
}

void main() {
	int arr[] = { 2,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = linearSearch(arr, size, 10);

	(result == -1) ? cout << "Element not found" : cout << "Element found at: " << result;
}
