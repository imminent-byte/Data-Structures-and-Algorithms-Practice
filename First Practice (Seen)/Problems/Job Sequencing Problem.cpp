#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
	char id;
	int deadLine;
	int profit;
};

bool compare(Job a, Job b) {
	return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int size) {

	//Sorting all jobs according to decreasing order of profit
	sort(arr, arr + size, compare);

	//To store result (Sequence of Jobs); Kind of creating index for printing it in sequence later
	int* result = new int [size];

	//To keep track of free time slots
	bool* slot = new bool [size];

	//Initialize all slots to be free
	for (int i = 0; i < size; i++)
		slot[i] = false;

	//Iterate through all jobs
	for (int i = 0; i < size; i++) {
		// Find a free slot for this job (Note that we start from the last possible slot)
		for (int j = min(size, arr[i].deadLine) - 1; j >= 0; j--) {
			//Free slot found
			if (slot[j] == false) {
				result[j] = i; // Add this job to result
				slot[j] = true; // Make this slot occupied
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
