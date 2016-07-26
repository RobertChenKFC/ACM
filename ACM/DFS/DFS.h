#include <iostream>
#include <vector>

using namespace std;

void DFS(vector< vector<bool> >& connected, vector<bool>& marked, int size, int curNode = 0) {
	cout << curNode << endl;
	marked[curNode] = true;
	for(int i = 0; i < size; i++) {
		if(connected[curNode][i] && !marked[i])
			DFS(connected, marked, size, i);
	}
}

int main() {
	int numNodes;
	cin >> numNodes;

	vector< vector<bool> > connected(numNodes, vector<bool>(numNodes, false));
	int numSegs;
	cin >> numSegs;
	for(int i = 0; i < numSegs; i++) {
		int from, to;
		cin >> from >> to;
		connected[from][to] = true, connected[to][from] = true;
	}

	vector<bool> marked(numSegs, false);
	DFS(connected, marked, numNodes);
}
