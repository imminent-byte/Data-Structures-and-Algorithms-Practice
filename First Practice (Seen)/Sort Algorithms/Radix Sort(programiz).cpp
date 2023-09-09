#include <iostream>
using namespace std;

//Function that returns the largest element 
int getMax(int arr[], int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

//Optimizing coutSort to sort the elements in the basis of significant places
void countSort(int arr[], int size, int place) {
	const int max = 10;
	int output[size];
	int count[max];

	for (int i = 0; i < max; i++)
		count[i] = 0;

	//Calculate count of elements
	for(int i = 0; i < size; i++)
		count[(arr[i] / place) % 10]++;//need to understand 

	//Calculate cumulative count
	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];

	//Placing items in sorted order
	for (int i = size - 1; i >= 0; i--) {
		output[count[(arr[i] / place) % 10] - 1] = arr[i]; //need to understand
		count[(arr[i] / place) % 10]--; //need to understand
	}

	for (int i = 0; i < size; i++)
		arr[i] = output[i];
}

void radixSort(int arr[], int size) {
	//Get max elem
	int max = getMax(arr, size);

	//Apply countSort to sort elements based on place value
	for (int place = 1; max / place > 0; place *= 10) { //need to understand
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
