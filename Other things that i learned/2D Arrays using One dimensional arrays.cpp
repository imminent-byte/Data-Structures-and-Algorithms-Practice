#include <iostream>
using namespace std;

int main() {
	const int a = 5;
	const int b = 5;
	int arr[a * b] = { 0 };

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << arr[(i * a) + j];
		}
		cout << endl;
	}
}
