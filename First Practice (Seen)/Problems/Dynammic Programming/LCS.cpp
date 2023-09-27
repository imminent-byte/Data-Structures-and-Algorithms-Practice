#include <iostream>
#include <algorithm>
using namespace std;

void lcsAlo(char* S1, char* S2, int m, int n) {
	int** LCS_Table = new int* [m + 1];
	for (int i = 0; i <= m; i++)
		LCS_Table[i] = new int[n + 1];


	// Building the matrix using bottom-up approach
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				LCS_Table[i][j] = 0;
			else if (S1[i - 1] == S2[j - 1])
				LCS_Table[i][j] = LCS_Table[i - 1][j - 1] + 1;
			else
				LCS_Table[i][j] = max(LCS_Table[i - 1][j], LCS_Table[i][j - 1]);
		}
	}

	int index = LCS_Table[m][n];
	//LCS arr that will be printed
	char* lcsAlgo = new char[index + 1];
	lcsAlgo[index] = '\0';

	int i = m, j = n;
	while (i > 0 && j > 0) {
		if (S1[i - 1] == S2[j - 1]) {
			lcsAlgo[index - 1] = S1[i - 1];
			i--;
			j--;
			index--;
		}

		else if (LCS_Table[i - 1][j] > LCS_Table[i][j - 1])
			i--;
		else
			j--;
	}

	// Printing matrix
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			cout << LCS_Table[i][j];
		}
		cout << endl;
	}
	cout << endl;
	// Printing LCS
	cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS : " << lcsAlgo << "\n";

	// Cleaning the dynamically allocated memory
	delete lcsAlgo;

	for (int i = 0; i < m; i++)
		delete[] LCS_Table[i];
	delete[] LCS_Table;
}

int main() {
	char S1[] = "ACADB";
	char S2[] = "CBDA";
	int m = strlen(S1);
	int n = strlen(S2);

	lcsAlo(S1, S2, m, n);
}
