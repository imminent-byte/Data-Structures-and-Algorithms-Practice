#include <iostream>
#include <list>
using namespace std;

class Graph {
	int numVertices;
	list<int>* adjLists;
	bool* visited;

public:
	Graph(int V);
	void addEdge(int src, int dest);
	void DFS(int vertex);
};

// Initialize graph
Graph::Graph(int vertices) {
	numVertices = vertices;
	adjLists = new list<int>[vertices];
	visited = new bool[vertices];

	// Initialize visited array to false
	for (int i = 0; i < vertices; ++i) {
		visited[i] = false;
	}
}

// Add edges
void Graph::addEdge(int src, int dest) {
	adjLists[src].push_back(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
	visited[vertex] = true;
	cout << vertex << '\t';

	list<int>::iterator i;
	for (i = adjLists[vertex].begin(); i != adjLists[vertex].end(); i++)
		if (!visited[*i])
			DFS(*i);
}

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);

	g.DFS(0);

	return 0;
}
