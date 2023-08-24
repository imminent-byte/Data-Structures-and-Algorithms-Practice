#include<iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int size, int currentIndex) {
	int largest = currentIndex;
	int left = 2 * currentIndex + 1;
	int right = 2 * currentIndex + 2;

	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < size && arr[right] > arr[largest]) 
		largest = right;

	if (largest != currentIndex) {
		swap(arr[currentIndex], arr[largest]);
		heapify(arr, size, largest);
	}
}

void heapSort(int arr[], int size) {
	//Building Max Heap
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	//Heap Sort
	for (int i = size - 1; i >= 0; i--) {
		//Swapping root with the last elem
		//i = size - 1 leaves the last index that is swapped everytime and then after i >= 0 is false, the array that is left is the sorted array.
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 1, 12, 9, 5, 6, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, size);

	cout << "Sorted array is \n";
	printArray(arr, size);
}
