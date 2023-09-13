#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
	char id;
	int deadline;
	int profit;
	Job(char id, int deadline, int profit) {
		this->id = id;
		this->deadline = deadline;
		this->profit = profit;
	}
};


bool compare(Job a, Job b) {
	return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int size) {
	
	//Sort all jobs according to decreasing order of profit
	sort(arr, arr + size, compare);

	//To store result (Sequence of Jobs);
	int* result = new int[size];

	//to keep track of free time slots
	bool* slot = new bool[size];

	//Initialize all slots to be free
	for (int i = 0; i < size; i++) 
		slot[i] = false;

	//Iterate through all jobs
	for (int i = 0; i < size; i++) {
		// Find a free slot for this job (Note that we start from the last possible slot)
		for (int j = min(size, arr[i].deadline) - 1; j >= 0; j--) { // in j initializing j there is -1 because we have 0 index array and size is 1 index
			if (slot[j] == false) {
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}

	//Printing 
	for (int i = 0; i < size; i++)
		if (slot[i])
			cout << arr[result[i]].id << " ";

	//Deallocate the array
	delete[] result;
	delete[] slot;
}

int main() {
	Job arr[] = { {'a', 2, 100},
				{'b', 1, 19},
				{'c', 2, 27},
				{'d', 1, 25},
				{'e', 3, 15} };

	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs "
		"\n";
	printJobScheduling(arr, size);
	return 0;
}
