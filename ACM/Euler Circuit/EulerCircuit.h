#include <iostream>
#include <cstring>

using namespace std;

void DFS(bool **graph, int v, bool *visited, int cur = 0) {
	visited[cur] = true;
	for(int i = 0; i < v; i++)
		if(!visited[i] && graph[cur][i]) DFS(graph, v, visited, i);
}

int main() {
	int v, e;
	cin >> v >> e;

	bool **bigraph = new bool*[v], **graph = new bool*[v];
	int *deg = new int[v], *inDeg = new int[v], *outDeg = new int[v];
	memset(deg, 0, sizeof(int) * v);
	memset(inDeg, 0, sizeof(int) * v);
	memset(outDeg, 0, sizeof(int) * v);
	for(int i = 0; i < v; i++) {
		bigraph[i] = new bool[v];
		graph[i] = new bool[v];
		memset(bigraph[i], 0, v);
		memset(graph[i], 0, v);
	}

	int from, to;
	for(int i = 0; i < e; i++) {
		cin >> from >> to;
		if(!bigraph[from][to]) {
			bigraph[from][to] = true, bigraph[to][from] = true;
			deg[from]++, deg[to]++;
		}
		graph[from][to] = true;
		inDeg[to]++, outDeg[from]++;
	}

	// non-directional
	cout << "Non-directional: " << endl;
	// check if all connected
	bool *visited = new bool[v];
	memset(visited, 0, v);
	DFS(bigraph, v, visited);
	bool isConnected = true;
	for(int i = 0; i < v; i++) {
		if(!visited[i]) {
			isConnected = false;
			break;
		}
	}
	// euler circuit and euler trail
	bool isEulerCircuit = isConnected;
	int oddCnt = 0;
	for(int i = 0; i < v; i++) {
		// euler circuit (all degrees are even)
		if(deg[i] & 1) isEulerCircuit = false;
		// euler trail (only 2 degrees are odd)
		else oddCnt++;
	}
	if(isEulerCircuit) {
		cout << "Is Euler Circuit" << endl
			 << "Is Euler Trail" << endl;
	}
	else if(oddCnt == 2 && isConnected) {
		cout << "Is not Euler Circuit" << endl
			 << "Is Euler Trail" << endl;
	}
	else {
		cout << "Is not Euler Circuit" << endl
			 << "Is not Euler Trail" << endl;
	}

	// directional
	cout << "Directional: " << endl;
	// check if all connected
	memset(visited, 0, v);
	DFS(graph, v, visited);
	isConnected = true;
	for(int i = 0; i < v; i++) {
		if(!visited[i]) {
			isConnected = false;
			break;
		}
	}
	// euler circuit and euler trail
	isEulerCircuit = isConnected;
	int inDegMoreCnt = 0, outDegMoreCnt = 0, nonValidCnt = 0;
	for(int i = 0; i < v; i++) {
		// euler trail (only one in degrees == out degrees + 1 and vice versa, others in degrees == out degrees)
		if(inDeg[i] == outDeg[i] + 1) inDegMoreCnt++;
		else if(inDeg[i] + 1 == outDeg[i]) outDegMoreCnt++;
		// euler circuit (in degrees == out degrees)
		else if(inDeg[i] != outDeg[i]) {
			isEulerCircuit = false, nonValidCnt++;
			break;
		}
	}
	if(isEulerCircuit) {
		cout << "Is Euler Circuit" << endl
			 << "Is Euler Trail" << endl;
	}
	else if(inDegMoreCnt == 1 && outDegMoreCnt == 1 && nonValidCnt == 0) {
		cout << "Is not Euler Circuit" << endl
			 << "Is Euler Trail" << endl;
	}
	else {
		cout << "Is not Euler Circuit" << endl
			 << "Is not Euler Trail" << endl;
	}

	// delete
	for(int i = 0; i < v; i++) {
		delete[] bigraph[i];
		delete[] graph[i];
	}
	delete[] bigraph;
	delete[] graph;
	delete[] deg;
	delete[] inDeg;
	delete[] outDeg;
	delete[] visited;
}
