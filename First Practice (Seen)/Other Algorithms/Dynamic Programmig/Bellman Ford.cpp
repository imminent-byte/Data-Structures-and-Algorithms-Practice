#include <iostream>
using namespace std;

#define MAX 99999

// Struct for the edges of the graph
struct Edge {
	int u; // starting vertex of edge
	int v; // ending vertex of edge
	int w; // weight of the edge (u, v)
};

// Graph that consists of edges
struct Graph {
	int V; // Total number of vertices in the graph
	int E; // Total number of edges in the graph
	struct Edge* edge; // Array of edges
};

typedef struct Graph Graph;
// Create a graph with V vertices and E edges
Graph* createGraph(int V, int E){
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	//Array of edges for graph
	graph->edge = new Edge[E];
	return graph;
}

//Printing the Solution
void printArr(int arr[], int size) {
	cout << "Vertex Distance From Source\n";
	for (int i = 0; i < size; i++) {
		cout << i << " \t\t " << arr[i] << "\n";
	}
}

void BellmanFord(Graph* graph, int u) {
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	// Fill the distance array and predecessor array with infinity;
	for (int i = 0; i < V; i++)
		dist[i] = MAX;

	// Mark the source vertex
	dist[u] = 0;

	// Relax edges V - 1 times
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			// Get the edge data
			int u = graph->edge[j].u;
			int v = graph->edge[j].v;
			int w = graph->edge[j].w;
			if (dist[u] != MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	// Detect negative cycle
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].u;
		int v = graph->edge[i].v;
		int w = graph->edge[i].v;
		if (dist[u] != MAX && dist[u] + w < dist[v]) {
			cout << "Graph contains negative weight cycle";
			cout << '\n';
		}
	}

	// If no negative cycle is found
	printArr(dist, V);
}

int main() {
	// Create a graph
	int V = 5; // Total vertices
	int E = 8; // Total edges

	// Array of edges for graph
	Graph* graph = createGraph(V, E);

	//edge 0 --> 1
	graph->edge[0].u = 0;
	graph->edge[0].v = 1;
	graph->edge[0].w = -1;

	//edge 0 --> 2
	graph->edge[1].u = 0;
	graph->edge[1].v = 2;
	graph->edge[1].w = 4;

	//edge 1 --> 2
	graph->edge[2].u = 1;
	graph->edge[2].v = 2;
	graph->edge[2].w = 3;

	//edge 1 --> 3
	graph->edge[3].u = 1;
	graph->edge[3].v = 3;
	graph->edge[3].w = 2;

	//edge 1 --> 4
	graph->edge[4].u = 1;
	graph->edge[4].v = 4;
	graph->edge[4].w = 2;

	//edge 3 --> 2
	graph->edge[3].u = 3;
	graph->edge[3].v = 2;
	graph->edge[3].w = 5;

	//edge 3 --> 1
	graph->edge[3].u = 3;
	graph->edge[3].v = 1;
	graph->edge[3].w = 1;

	//edge 4 --> 3
	graph->edge[3].u = 4;
	graph->edge[3].v = 3;
	graph->edge[3].w = -3;

	BellmanFord(graph, 0); // here 0 is the source vertex

	return 0;
}
