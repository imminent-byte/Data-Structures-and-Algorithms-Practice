#include <iostream>
using namespace std;

int getMax(int arr[], int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void countSort(int arr[], int size, int place) {
	const int max = 10;
	int output[size];
	int count[max];

  //Filling count arr with zeros;
	for (int i = 0; i < max; i++)
		count[i] = 0;

	//Store the count of each elem
	//i.e: arr[i] = 121, place = 1 will be: (121/1) % 10 = 121 % 10 = 1
	for(int i = 0; i < size; i++)
		count[(arr[i] / place) % 10]++;

	//Storing cummulative count
	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];

	//Placing items in sorted order
	for (int i = size - 1; i >= 0; i--) {
		output[count[(arr[i] / place) % 10] - 1] = arr[i]; 
		count[(arr[i] / place) % 10]--; 
	}

  //Copy sorted elements in original arr
	for (int i = 0; i < size; i++)
		arr[i] = output[i];
}

void radixSort(int arr[], int size) {
	int max = getMax(arr, size);

	for (int place = 1; max / place > 0; place *= 10) { 
		countSort(arr, size, place);
	}
}

void printArray(int array[], int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main() {
	int arr[] = { 121, 432, 564, 23, 1, 45, 788 };
	int n = sizeof(arr) / sizeof(arr[0]);

	radixSort(arr, n);
	
	printArray(arr, n);
}
