#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 99999
#define V 6

//	Using BFS as searching algorithm
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
	//	bool array for visited vertices
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		//	Iterates over all the vertices (v) in the graph and checks if v is not visited and there is a positive residual capacity from u to v in the residual graph
		for (int v = 0; v < V; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	return (visited[t] == true);
} 

//	Ford Fulkerson Algorithm
int fordFulkerson(int graph[V][V], int s, int t) {
	int u, v;

	//	Making copy of original graph
	int rGraph[V][V];
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];
	
	//	Array of size 6
	int parent[V];
	int max_flow = 0;

	//	Updating the residual values of edges
	while (bfs(rGraph, s, t, parent)) {
		int path_flow = MAX;
		//	finding minimum edge path
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		//	Adding the path flows
		max_flow += path_flow;
	}

	return max_flow;
}

int main() {
	int graph[V][V] = { {0, 8, 0, 0, 3, 0},
			   {0, 0, 9, 0, 0, 0},
			   {0, 0, 0, 0, 7, 2},
			   {0, 0, 0, 0, 0, 5},
			   {0, 0, 7, 4, 0, 0},
			   {0, 0, 0, 0, 0, 0} };

	cout << "Max Flow: " << fordFulkerson(graph, 0, 5) << endl;
}
