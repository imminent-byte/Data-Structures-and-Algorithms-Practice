#include<iostream>
using namespace std;

int main() {
	const int stages = 4;
	int min;
	int n = 8;
	int cost[9], d[9], path[stages + 1];
	int C[9][9] = { {0,0,0,0,0,0,0,0,0},
		{0,0,2,1,3,0,0,0,0,},
		{0,0,0,0,0,2,3,0,0,},
		{0,0,0,0,0,6,7,0,0,},
		{0,0,0,0,0,6,8,9,0,},
		{0,0,0,0,0,0,0,0,6,},
		{0,0,0,0,0,0,0,0,4,},
		{0,0,0,0,0,0,0,0,5,},
		{0,0,0,0,0,0,0,0,0,} };
	cost[n] = 0;

	for (int i = n - 1; i >= 1; i--) {
		min = 32767;
		for (int k = i + 1; k <= n; k++) {
			if (C[i][k] != 0 && C[i][k] + cost[k] < min) {
				min = C[i][k] + cost[k];
				d[i] = k;
			}
		}
		cost[i] = min;
	}
	
	cout << "Shortest distance from source to sink is: " << cost[1] << endl;

	path[1] = 1; path[stages] = n;
	for (int i = 2; i < stages; i++)
		path[i] = d[path[i - 1]];

	for (int i = 1; i <= stages; i++)
		cout << path[i] << "\t";
}
