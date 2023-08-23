#include <iostream>
using namespace std;

void insertionSort(int arr[], int size){
  for(int step = 1; step < size; step++){
    int key = arr[step];
    int j = step - 1;

    while(key < arr[j] && j >=0){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main(){
  int arr[] = {2,1,4,0,10,9,12,44,22};
  int size = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, size);
  insertionSort(arr, size);
  printArray(arr, size);
}
