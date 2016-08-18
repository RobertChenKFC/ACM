#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int NOT_VISITED = -1;

void DFS(bool **graph, int v, int *orders, int *lowest, int me = 0, int father = NOT_VISITED, int cur = 0) {
	orders[me] = lowest[me] = cur;
	int child = 0;
	bool isAP = false;
	for(int i = 0; i < v; i++) {
		if(graph[me][i]) {
			if(orders[i] == NOT_VISITED) {
				child++;
				DFS(graph, v, orders, lowest, i, me, cur + 1);
				if(lowest[i] < lowest[me]) lowest[me] = lowest[i];
				if(lowest[i] >= orders[me]) isAP = true;
			}
			else if(i != father && orders[i] < lowest[me])
				lowest[me] = orders[i];
		}
	}

	if((father == NOT_VISITED && child >= 2) || (father != NOT_VISITED && isAP))
		cout << me << endl;
}

void FoundAP(bool **graph, int v) {
	int *orders = new int[v], *lowest = new int[v];
	for(int i = 0; i < v; i++) orders[i] = NOT_VISITED;
	DFS(graph, v, orders, lowest);
	delete[] orders;
	delete[] lowest;
}

int main() {
	int v, e;
	cin >> v >> e;

	bool **graph = new bool*[v];
	for(int i = 0; i < v; i++) {
		graph[i] = new bool[v];
		memset(graph[i], 0, v);
	}
	int a, b;
	for(int i = 0; i < e; i++) {
		cin >> a >> b;
		graph[a][b] = true, graph[b][a] = true;
	}

	FoundAP(graph, v);

	for(int i = 0; i < v; i++) delete graph[i];
	delete[] graph;

	/* test
	10 11
	0 1
	1 2
	2 3
	3 4
	4 5
	5 6
	6 7
	7 8
	7 9
	5 7
	1 4
	 */
}
