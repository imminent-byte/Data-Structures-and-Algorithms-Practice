#include <iostream>
using namespace std;

void countSort(int arr[], int size) {
	int output[20];
	int count[10];
	int max = arr[0];


	//Finding largest elements
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	//Filling count arr with zeros;
	for (int i = 0; i <= max; i++) {
		count[i] = 0;
	}

	//Store the count of each elem
	//We are using arr[i] value as the index of count;
	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
	}

	//Storing cummulative count
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	//Find the index of each element of the original arr in count arr, and place the elements in output arr
	for (int i = size - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	//Copy sorted elements in original arr
	for (int i = 0; i < size; i++) {
		arr[i] = output[i];
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
	int arr[] = { 3,3,2,2,1,1,5,6,8,8,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	countSort(arr, size);
	cout << "Sorted array: \n";
	printArray(arr, size);
}
