#include <iostream>
using namespace std;

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int size){
  for(int step = 0; step < size - 1; step++){
    int swapped = 0;
    for(int i = 0; i < size - step - 1; i++){
      if (arr[i] > arr[i + 1]){
        swap(arr[i], arr[i + 1]);

        swapped = 1;
      }
    }
    if(swapped == 0)
    break;
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {1, 3, 2, 9, 22, 32};
  
  int size = sizeof(data) / sizeof(data[0]);
  
  bubbleSort(data, size);
  
  cout << "Sorted Array:\n";
  printArray(data, size);
}
