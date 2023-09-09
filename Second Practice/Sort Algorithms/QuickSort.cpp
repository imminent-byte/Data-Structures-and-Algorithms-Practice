#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        do{
            i++;
        } while(arr[i] <= pivot);
        do{
            j--;
        } while(arr[j] > pivot);
        if (i < j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int partitionIndex = Partition(arr, low, high);
        quickSort(arr, low, partitionIndex);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void printArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {2,1,4,3,6,5,7,9,8,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArr(arr, size);
    //setting infinity point as high
    quickSort(arr, 0, size);

    cout << "sorted arr: \n";
    printArr(arr, size);
}
