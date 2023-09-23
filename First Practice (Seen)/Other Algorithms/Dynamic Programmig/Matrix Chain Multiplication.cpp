#include <iostream>
using namespace std;

int main() {
	// 5 because we use 1 indexing on C and K
	int n = 5;
	int P[] = { 5,4,6,2,7 };
	// Filling all values as zeros so we overwrite the ones we use
	int C[5][5] = { 0 }; //COST
	int K[5][5] = { 0 }; //K value (checking every possibility)
	// Columns that are dependent on value of i (rows)
	int j;
	// For comparing and finding minimum 
	int min, q;

	//EMPTY MATRIX FOR TABLE C
	cout << "Empty table for Matrix C\n\n";
	for (int d = 1; d < n; d++) {
		for (int i = 1; i < n; i++) {
			cout << "\t" << C[d][i];
		}
		cout << "\n";
	}
	cout << "\n";

	// Matrix Chain Multiplication
	for (int d = 1; d < n - 1; d++) {// Here d is difference, we will first find values with smallest difference and then largest, n - 1 gives last index i.e, if we find index 1,4 then difference is 3 which is 1 less than 4
		for (int i = 1; i < n - d; i++) {// n - d because the number of rows also decreases with difference
			j = i + d;
			min = 32767;
			for (int k = i; k <= j - 1; k++) {// k <= j - 1 because we use k + 1 later when making comparisons
					q = C[i][k] + C[k + 1][j] + P[i - 1] * P[k] * P[j];
					if (q < min) {
						min = q;
						K[i][j] = k;
					}
			}
			C[i][j] = min;
		}
	}

	//	MATRIX FOR TABLE C
	cout << "Table for Matrix C\n\n";
	for (int d = 1; d < n; d++) {
		for (int i = 1; i < n; i++) {
			cout << "\t" << C[d][i];
		}
		cout << "\n";
	}
	cout << "\n";

	//	MATRIX FOR TABLE K
	cout << "Table for Matrix K\n\n";
	for (int d = 1; d < n; d++) {
		for (int i = 1; i < n; i++) {
			cout << "\t" << K[d][i];
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "MINIMUM NUMBER OF CALCULATION = \t" << C[1][n - 1] << "\n";
	cout << "PARENTHESIS POSITION " << K[1][n - 2] << " and " << K[1][n - 1];
}
