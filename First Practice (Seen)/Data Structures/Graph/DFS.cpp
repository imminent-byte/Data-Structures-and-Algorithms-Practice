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
	adjLists[dest].push_back(src);
}

// DFS algorithm, we dont use stack here because recursion takes care of the stack
void Graph::DFS(int vertex) {
	visited[vertex] = true;
	cout << vertex << '\t';

	list<int>::iterator i;
	for (i = adjLists[vertex].begin(); i != adjLists[vertex].end(); i++)
		if (!visited[*i])
			DFS(*i);
}

void test1() {
	cout << "//TEST 1//" << endl;
	Graph g(8);
	g.addEdge(1, 5);
	g.addEdge(1, 4);
	g.addEdge(1, 2);
	g.addEdge(2, 7);
	g.addEdge(2, 6);
	g.addEdge(2, 3);

	g.DFS(1);
	cout << endl;
}

void test2() {
	cout << "//TEST 2//" << endl;
	Graph g(8);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(3, 7);

	g.DFS(1);
	cout << endl;
}

void test3() {
	cout << "//TEST 3//" << endl;
	Graph g(11);
	g.addEdge(1, 4);
	g.addEdge(1, 2);
	g.addEdge(4, 3);
	g.addEdge(2, 3);
	g.addEdge(3, 10);
	g.addEdge(3, 9);
	g.addEdge(2, 7);
	g.addEdge(2, 5);
	g.addEdge(2, 8);
	g.addEdge(8, 5);
	g.addEdge(8, 7);
	g.addEdge(7, 5);
	g.addEdge(5, 6);

	g.DFS(1);
	cout << endl;
}

int main() {
	test1();
	test2();
	test3();
}
