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
			if (i == 0 || ksW == 0)
				k[i][ksW] = 0;

			else if (oW[i] <= ksW)
				k[i][ksW] = max(P[i] + k[i - 1][ksW - oW[i]], k[i - 1][ksW]);

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
			j = j - oW[i];
			i--;
		}
	}
}
