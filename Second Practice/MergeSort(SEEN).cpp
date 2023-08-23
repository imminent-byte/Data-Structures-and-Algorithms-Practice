#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
  
  int leftSize = mid - left + 1;
  int rightSize = right - mid;

  int leftArr[leftSize], rightArr[rightSize];

  for(int i = 0; i < leftSize; i++){
    leftArr[i] = arr[left + i];
  }
  for(int j = 0; j < rightSize; j++){
    rightArr[j] = arr[mid + 1 + j];
  }

  int i, j, k;
  i = 0;
  j = 0;
  k = left;

  while(i < leftSize && j < rightSize){
    if(leftArr[i] <= rightArr[j]){
      arr[k] = leftArr[i];
      i++;
    } else{
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  while(i < leftSize){
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  while(j < rightSize){
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right){
  if(left < right){
    int mid = (left + right)/2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
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
  mergeSort(arr, 0, size - 1);
  printArray(arr, size);
}
