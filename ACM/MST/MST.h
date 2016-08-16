#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
	int from, to;
	int dist;
};

bool cmp(const Edge &a, const Edge &b) {
	return a.dist < b.dist;
}

const int NOT_FOUND = -1;

int main() {
	// getting input
	int v;
	cin >> v;
	int **graph = new int*[v];
	for(int i = 0; i < v; i++)
		graph[i] = new int[v];
	int e;
	cin >> e;
	Edge *edges = new Edge[e];
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++) graph[i][j] = INT_MAX;
	for(int i = 0; i < e; i++) {
		int from, to;
		cin >> from >> to;
		cin >> graph[from][to];
		graph[to][from] = graph[from][to];
		edges[i] = { from, to, graph[from][to] };
	}

	// Kruskal's Algorithm
	cout << "Kruskal's Algorithm: " << endl;
	int *set = new int[v];
	int cost = 0;
	for(int i = 0; i < v; i++) set[i] = i;
	sort(edges, edges + e, cmp);
	int numEdges = 0, limit = v - 1;
	for(int i = 0; i < e && numEdges < limit; i++) {
		if(set[edges[i].from] != set[edges[i].to]) {
			numEdges++;
			set[edges[i].from] = set[edges[i].to];
			cout << "(" << edges[i].from << ", " << edges[i].to << ") = " << edges[i].dist << endl;
			cost += edges[i].dist;
		}
	}
	cout << "Minimum cost: " << cost << endl;
	delete[] set;
	delete[] edges;

	// Prim's Algorithm
	cout << "Prim's Algorithm: " << endl;
	bool *inTree = new bool[v];
	int *dist = new int[v];
	int *parent = new int[v];
	cost = 0;
	for(int i = 0; i < v; i++) inTree[i] = false, dist[i] = INT_MAX, parent[i] = NOT_FOUND;
	dist[0] = 0;
	for(int i = 0; i < v; i++) {
		int min = INT_MAX, minIndex = NOT_FOUND;
		for(int j = 0; j < v; j++) {
			if(!inTree[j] && dist[j] < min)
				min = dist[j], minIndex = j;
		}

		if(minIndex == NOT_FOUND) break;
		inTree[minIndex] = true;

		for(int j = 0; j < v; j++) {
			if(!inTree[j] && graph[minIndex][j] < dist[j]) {
				dist[j] = graph[minIndex][j];
				parent[j] = minIndex;
			}
		}
	}
	for(int i = 1; i < v; i++) {
		cout << "(" << parent[i] << ", " << i << ") = " << graph[i][parent[i]] << endl;
		cost += graph[i][parent[i]];
	}
	cout << "Minimum cost: " << cost << endl;
	delete[] dist;
	delete[] parent;
	delete[] inTree;

	// Sollin's Algorithm
	cout << "Sollin's Algorithm: " << endl;
	set = new int[v];
	cost = 0;
	for(int i = 0; i < v; i++) set[i] = i, parent[i] = NOT_FOUND;
	bool done = false;
	while(!done) {
		for(int i = 0; i < v; i++) {
			int min = INT_MAX, minIndex = NOT_FOUND;
			for(int j = 0; j < v; j++) {
				if(set[i] != set[j] && graph[i][j] < min)
					min = graph[i][j], minIndex = j;
			}
			if(minIndex == NOT_FOUND) {
				done = true;
				break;
			}

			for(int j = 0; j < v; j++) {
				if(j != minIndex && set[minIndex] == set[j])
					set[j] = set[i];
			}
			set[minIndex] = set[i];
			cout << "(" << i<< ", " << minIndex << ") = " << graph[i][minIndex] << endl;
			cost += graph[i][minIndex];
		}
	}
	cout << "Minimum cost: " << cost << endl;

	for(int i = 0; i < v; i++)
		delete[] graph[i];
	delete[] graph;
}
