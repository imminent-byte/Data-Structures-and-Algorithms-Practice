#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void heapify(vector<int>& heapTree, int currentElement) {
	int size = heapTree.size();
	int largest = currentElement;
	int left = 2 * currentElement + 1;
	int right = 2 * currentElement + 2;
	if (left < size && heapTree[left] > heapTree[largest])
		largest = left;
	if (right < size && heapTree[right] > heapTree[largest])
		largest = right;

	if (largest != currentElement) {
		swap(&heapTree[currentElement], &heapTree[largest]);
		heapify(heapTree, largest);
	}
}

void insert(vector<int>& heapTree, int newNum) {
	int size = heapTree.size();
	if (size == 0) {
		heapTree.push_back(newNum);
	}
	else {
		heapTree.push_back(newNum);
		//Start from the first index of non-leaf node whose index is given by size / 2 - 1
		for (int i = size / 2 - 1; i >= 0; i--) {
			heapify(heapTree, i);
		}
	}
}

void deleteNode(vector<int>& heapTree, int num) {
	int size = heapTree.size();
	int i;
	for (i = 0; i < size; i++) {
		if (num == heapTree[i])
			break;
	}
	swap(&heapTree[i], &heapTree[size - 1]);

	heapTree.pop_back();
	//Start from the first index of non-leaf node whose index is given by size / 2 - 1
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(heapTree, i);
	}
}

void printArray(vector<int>& hT)
{
	for (int i = 0; i < hT.size(); ++i)
		cout << hT[i] << " ";
	cout << "\n";
}

int main()
{
	vector<int> heapTree;

	insert(heapTree, 3);
	insert(heapTree, 4);
	insert(heapTree, 9);
	insert(heapTree, 5);
	insert(heapTree, 2);

	cout << "Max-Heap array: ";
	printArray(heapTree);

	deleteNode(heapTree, 4);

	cout << "After deleting an element: ";

	printArray(heapTree);
}
