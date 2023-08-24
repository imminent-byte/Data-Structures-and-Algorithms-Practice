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
		// As we have created a Max Heap, we will swap root with last element
		// i = size - 1 gives the last index, when swapped largest element goes to the end
		// Then the the tree is heapified
		// i-- will decrease i now the next largest element is swapped with the new largest element
		// When all are swapped and i-- reaches -1 then the array left is sorted
		swap(arr[0], arr[i]);

		//i meaning size - 1 is the new size here and  0 meaning the new current element after prev is removed
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
