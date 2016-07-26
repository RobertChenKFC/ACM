#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

	vector<bool> inQueue(numNodes, false), marked(numNodes, false);
	queue<int> nodeQueue;
	inQueue[0] = true, marked[0] = true;
	nodeQueue.push(0);
	while(nodeQueue.size() != 0) {
		int cur = nodeQueue.front();
		cout << cur << endl;

		inQueue[cur] = false;
		nodeQueue.pop();

		for(int i = 0; i < numNodes; i++) {
			if(connected[cur][i] && !inQueue[i] && !marked[i]) {
				inQueue[i] = true, marked[i] = true;
				nodeQueue.push(i);
			}
		}
	}
}
