// Prim's Algorithm in C++

#include <iostream>
using namespace std;

#define INF 9999999

// number of vertices in graph
#define V 5

// Total for printing the total cost in the end
int total;

// create a 2d array of size 5x5 for adjacency matrix to represent graph
//(These are all the weights)
int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0} };

int main() {
	int num_edges; // number of edges

	//create an array to track selected vertex selected will become true otherwise false
	int selected[V];

	//set selected to false initially
	memset(selected, false, sizeof(selected));

	//set number of edges to 0
	num_edges = 0;

	//the number of edge in minimum spanning tree will be always less than (V_1), where V is number os vertices in a graph

	//choose 0th vertex and make it true (we choose one vertex randomly)
	selected[0] = true; //(Step 1)

	int x, y; //row and column number

	//Print header of result i.e edge and weight
	cout << "Edge"
		<< " : "
		<< "Weight";
	cout << endl;
	while (num_edges < V - 1) {
		//For every vertex in the set S, find all the adjacent vertices,
		//calculate the distance from the vertex selected at step 1.
		//If the vertex is already in the set S, discard it otherwise
		//choose another vertex nearest to selected vertex at step 1.

		//reseting minimum, x and y in each iteration to check new minimum again with every vertex for every edge
		int min = INF;
		x = 0;
		y = 0;

		for (int i = 0; i < V; i++) {
			if (selected[i]) {
				for (int j = 0; j < V; j++) {
					//finding smallest weight from the one selected vertex
					if (!selected[j] && G[i][j]) { // not in selected and there is an edge
						if (min > G[i][j]) {
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		total += G[x][y];
		cout << x << " - " << y << " : " << G[x][y];
		cout << endl;
		selected[y] = true;
		num_edges++;
	}
	cout << "Total Cost: " << total;
	return 0;
}
