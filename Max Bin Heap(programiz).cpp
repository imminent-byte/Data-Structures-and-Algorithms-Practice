#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(vector<int>& heapT, int currentElem) {
	int size = heapT.size();
	int largest = currentElem;
	int left = 2 * currentElem + 1;
	int right = 2 * currentElem + 2;
	if (left < size && heapT[left] > heapT[largest])
		largest = left;
	if (right < size && heapT[right] > heapT[largest])
		largest = right;

	if (largest != currentElem) {
		swap(&heapT[currentElem], &heapT[largest]);
		heapify(heapT, largest);
	}
}

void insertNode(vector<int>& heapT, int newNum) {
	int size = heapT.size();
	if (size == 0)
	{
		heapT.push_back(newNum);
	}
	else
	{
		heapT.push_back(newNum);
		for (int i = size / 2 - 1; i >= 0; i--) {
			heapify(heapT, i);
		}
	}

}

void deleteNode(vector<int>& heapT, int num) {
	int size = heapT.size();
	cout << size << endl;
	int i;
	for (i = 0; i < size; i++) {
		if (num == heapT[i])
			break;
	}
	swap(&heapT[i], &heapT[size - 1]);

	heapT.pop_back();
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(heapT, i);
	}
}

void printArray(vector<int>& hT)
{
	for (int i = 0; i < hT.size(); ++i)
		cout << hT[i] << " ";
	cout << "\n";
}

int main() {
	vector<int> heapTree;

	insertNode(heapTree, 3);
	insertNode(heapTree, 4);
	insertNode(heapTree, 9);
	insertNode(heapTree, 5);
	insertNode(heapTree, 2);

	cout << "Max-Heap array: ";
	printArray(heapTree);

	deleteNode(heapTree, 4);

	cout << "After deleting an element: ";

	printArray(heapTree);
}
