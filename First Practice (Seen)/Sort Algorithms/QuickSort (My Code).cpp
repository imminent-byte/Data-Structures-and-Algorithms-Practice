#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int arr[], int low, int high) {
	int pivot = arr[low];
	int i = low, j = high;
	while (i < j) {
		do {
			i++;
		} while (arr[i] <= pivot);
		do{
			j--;
		} while (arr[j] > pivot);
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[low], &arr[j]);
	return j;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = Partition(arr, low, high);
		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 15, 14, 13, 12, 11, 10, 9, 8, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Unsorted Array: \n";
	printArray(arr, size);

	quickSort(arr, 0, size);

	cout << "Sorted array: \n";
	printArray(arr, size);
	return 0;
}
