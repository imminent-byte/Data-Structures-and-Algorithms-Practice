#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
	adj[s].push_back(d);
	adj[d].push_back(s);
}

void printGraph(vector<int> adj[], int V) {
	for (int i = 0; i < V; i++) {
		cout << "\n Vertex"
			<< i << " : ";
		for (auto x : adj[i])
			cout << " -> " << x;
		cout << "\n";
	}
}

int main() {
	int V = 5;
	vector<int> adj[5];

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 0, 3);
	addEdge(adj, 1, 2);

	addEdge(adj, 3, 2);
	addEdge(adj, 4, 2);
	printGraph(adj, V);
}
