#include<iostream>
#include<algorithm>
using namespace std;

struct Item {
	int value, weight;

	Item(int value, int weight) {
		this->value = value;
		this->weight = weight;
	}
};

typedef struct Item item;

//Comparison function to sort item according to value/weight ratio
bool cmp(item a, item b) {
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

//N is total weight of KnapSack
double fractionalKnapSack(item arr[], int N, int size) {
	sort(arr, arr + size, cmp);

	int currentWeight = 0;

	double finalValue = 0.0;

	//looping through all Items
	for (int i = 0; i < size; i++) {

		//If adding item wont overflow, add it completely
		if (currentWeight + arr[i].weight <= N) {
			currentWeight += arr[i].weight;
			finalValue += arr[i].value;
		}

		//If we cant add current Item, add fractional part of it
		else {
			int remain = N - currentWeight;
			finalValue += arr[i].value * ((double)remain / arr[i].weight);

			break;
		}
	}

	return finalValue;
}

int main() {
	int N = 60;

	item arr[] = { {100, 10},
				{280, 40},
				{120, 20},
				{120, 24} };

	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Max profit earned = " << fractionalKnapSack(arr, N, size);
	return 0;
}
