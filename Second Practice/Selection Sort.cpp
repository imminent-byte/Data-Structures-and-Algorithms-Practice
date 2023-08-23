#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int arr[], int size){
  for(int step = 0; step < size - 1; step++){
    int min_idx = step;
    for(int i = step + 1; i < size; i++){
      if(arr[i] < arr[min_idx]){
        min_idx = i;
      }
    }
    swap(arr[min_idx], arr[step]);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main(){
  int arr[] = {2,1,4,0,10,9};
  int size = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, size);
  selectionSort(arr, size);
  printArray(arr, size);
}
