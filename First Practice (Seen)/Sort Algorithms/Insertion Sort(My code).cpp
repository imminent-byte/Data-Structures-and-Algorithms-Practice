#include <iostream>
using namespace std;

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int size) {
    for (int step = 1; step < size; step++) {
        int key = arr[step];
        int lastSortedIndex = step - 1;

        while (key < arr[lastSortedIndex] && lastSortedIndex >= 0) {
            arr[lastSortedIndex + 1] = arr[lastSortedIndex];
            lastSortedIndex--;
        }
        arr[lastSortedIndex + 1] = key;
    }
}


int main() {
    int data[] = { 9, 5, 1, 4, 3 };
    int size = sizeof(data) / sizeof(data[0]);
    insertionSort(data, size);
    cout << "Sorted array in ascending order:\n";
    printArray(data, size);
}
