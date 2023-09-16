#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
private:
	//int is weight here
	vector<pair<int, edge>> G; //Graph
	vector<pair<int, edge>> T; //MST
	int* parent;
	int V; // number of vertices/nodes in graph
public:
	Graph(int V);
	//u is vertex one and v is vertex two and weight is w
	void AddWeightedEdge(int w, int u, int v);
	int find_set(int i);
	void union_set(int u, int v);
	void kruskal();
	void print();
};

Graph::Graph(int V) {
	parent = new int[V];

	//i 0 1 2 3 4 5 ....
	//parent[i] 0 1 2 3 4 5 ....
	for (int i = 0; i < V; i++)
		parent[i] = i;

	G.clear();
	T.clear();
}

void Graph::AddWeightedEdge(int w, int u, int v) {
	G.push_back(make_pair(w, edge(u, v)));
}

//find parent
int Graph::find_set(int i) {
	// If i is the parent of itself
	if (i == parent[i])
		return i;
	else
		//Else if i is not the parent of itself
		//Then i is not the representative of his set,
		//so we recursively call Find on its parent
		return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
	parent[u] = parent[v];
}

void Graph::kruskal() {
	int i, uParent, vParent;
	sort(G.begin(), G.end()); //increasing weight
	for (i = 0; i < G.size(); i++) {
		uParent = find_set(G[i].second.first);
		vParent = find_set(G[i].second.second);
		if (uParent != vParent) {
			T.push_back(G[i]); //add to tree
			union_set(uParent, vParent);
		}
	}
}

void Graph::print() {
	cout << "Edge :"
		<< " Weight" << endl;
	for (int i = 0; i < T.size(); i++) {
		cout << T[i].second.first << " - " << T[i].second.second << " : "
			<< T[i].first;
		cout << endl;
	}
}

int main() {
	Graph g(9);
	g.AddWeightedEdge(8, 0, 1);
	g.AddWeightedEdge(12, 0, 2);
	g.AddWeightedEdge(13, 1, 2);
	g.AddWeightedEdge(25, 1, 3);
	g.AddWeightedEdge(21, 2, 6);
	g.AddWeightedEdge(9, 1, 4);
	g.AddWeightedEdge(20, 4, 3);
	g.AddWeightedEdge(19, 4, 5);
	g.AddWeightedEdge(8, 5, 3);
	g.AddWeightedEdge(11, 5, 7);
	g.AddWeightedEdge(12, 3, 7);
	g.AddWeightedEdge(12, 3, 6);
	g.AddWeightedEdge(16, 3, 8);
	g.AddWeightedEdge(11, 6, 8);
	g.AddWeightedEdge(9, 8, 7);
	g.AddWeightedEdge(14, 2, 3);
	g.kruskal();
	g.print();
	return 0;
}
