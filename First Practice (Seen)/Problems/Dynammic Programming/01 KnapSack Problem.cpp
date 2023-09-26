#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int P[5] = { 0,1,2,5,6 };
	int oW[5] = { 0,2,3,4,5 }; // Object weight
	int m = 8, n = 4;
	int k[5][9] = { 0 };

	for (int i = 0; i <= n; i++) {
		for (int ksW = 0; ksW <= m; ksW++) { // knapsack weight
			if (i == 0 || ksW == 0) // if any of them is 0 meaning the value should be zero
				k[i][ksW] = 0;

			else if (oW[i] <= ksW) // if the object weight is less than equal to the current knapsack weight
				k[i][ksW] = max(P[i] + k[i - 1][ksW - oW[i]], k[i - 1][ksW]);

			// whatever was in the previous row, IE whatever the weight was with the previous value
			else k[i][ksW] = k[i - 1][ksW];
		}
	}
	cout << "Max Profit is: " << k[n][m] << endl;

	int i = n, j = m;
	while (i > 0) {
		if (k[i][j] == k[i - 1][j]) {
			cout << i << " = 0" << endl;
			i--;
		}
		else {
			cout << i << " = 1" << endl; 
			j = j - oW[i]; // j is subtracted with the weight of the added object so next we can choose the object that is less than or equal to the remaining weight in knapsack
			i--;
		}
	}
}
