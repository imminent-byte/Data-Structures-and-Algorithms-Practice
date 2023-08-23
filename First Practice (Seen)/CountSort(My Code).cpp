#include <iostream>
using namespace std;

void countSort(int arr[], int size) {
    int output[10];
    int count[10];
    int max = arr[0];

    //Finding largest elem in original arr
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    //Initialize count arr with all zeros
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    //Store the count of each elem
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    //Store the cummulative count of each arr
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    //Find the index of each element of the original arr in count arr, and place the elements in output arr
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    //Copy the sorted elements into original arr
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
	int data[] = { 4, 2, 2, 8, 3, 3, 1 };
	int size = sizeof(data) / sizeof(data[0]);
	countSort(data, size);
	cout << "Sorted array: \n";
	printArray(data, size);
}
