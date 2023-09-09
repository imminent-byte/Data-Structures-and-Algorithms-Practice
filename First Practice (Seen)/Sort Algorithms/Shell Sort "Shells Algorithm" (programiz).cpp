#include <iostream>
using namespace std;

void shellSort(int arr[], int size) {
	for (int interval = size / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < size; i++) {
			int temp = arr[i];
			int j;
			for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
				arr[j] = arr[j - interval];
			}
			arr[j] = temp;
		}
	}
}

void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int data[] = { 9, 8, 3, 7, 5, 6, 4, 1 };
	int size = sizeof(data) / sizeof(data[0]);
	shellSort(data, size);
	cout << "Sorted array: \n";
	printArray(data, size);
}
