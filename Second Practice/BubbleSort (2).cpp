#include <iostream>
using namespace std;

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int size){
  for(int step = 0; step < size; step++){
    for(int i = step + 1; i < size; i++){
      if(arr[i] < arr[step]){
        swap(arr[i], arr[step]);
      }
    }
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {1,2,3,5,4};
  
  int size = sizeof(data) / sizeof(data[0]);
  
  bubbleSort(data, size);
  
  cout << "Sorted Array:\n";
  printArray(data, size);
}
