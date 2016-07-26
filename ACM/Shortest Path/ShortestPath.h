#include <iostream>
#include <climits>

using namespace std;

const int NOT_FOUND = -1;
int main() {
	// getting input
	int numOfNodes;
	cin >> numOfNodes;

	// initializing input
	int** graph = new int*[numOfNodes]; // for both algorithms
	bool* marked = new bool[numOfNodes]; // for Dijkstra's algorithm
	int* distance = new int[numOfNodes]; // for Dijikstra's algorithm
	for(int i = 0; i < numOfNodes; i++) {
		graph[i] = new int[numOfNodes];
		marked[i] = false;
		distance[i] = INT_MAX;
		for(int j = 0; j < numOfNodes; j++) {
			if(i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INT_MAX;
		}
	}

	int numOfInput;
	cin >> numOfInput;
	for(int i = 0; i < numOfInput; i++) {
		int fromNode, toNode, distance;
		cin >> fromNode >> toNode >> distance;

		graph[fromNode][toNode] = distance;
	}

	int startNode;
	cin >> startNode;

	// Dijkstra's Algorithm starts here
	int curStartNode = startNode;
	distance[curStartNode] = 0;
	while(true) {
		// closes the node that's starting
		marked[curStartNode] = true;

		// updates distances from starting node to node i
		for(int i = 0; i < numOfNodes; i++) {
			int curDistance = distance[curStartNode] + graph[curStartNode][i];
			if(distance[curStartNode] > 0 && graph[curStartNode][i] > 0 && curDistance < 0)
				curDistance = INT_MAX;

			if(i != curStartNode && curDistance < distance[i])
				distance[i] = curDistance;
		}

		// finds the shortest distance node that is not closed
		int curMinDistance = INT_MAX, curMinIndex = NOT_FOUND;
		for(int i = 0; i < numOfNodes; i++) {
			if(!marked[i] && distance[i] < curMinDistance)
				curMinDistance = distance[i], curMinIndex = i;
		}

		// breaks whenever every reachable node is closed
		if(curMinIndex == NOT_FOUND)
			break;
		else
			curStartNode = curMinIndex;
	}
	cout << "Dijkstra's Algorithm: " << endl;
	for(int i = 0; i < numOfNodes; i++) {
		cout << startNode << " -> " << i << ": ";
		if(distance[i] == INT_MAX)
			cout << "unreachable" << endl;
		else
			cout << distance[i] << endl;
	}
	cout << endl;


	// Floyd - Warshall's Algorithm
	for(int i = 0; i < numOfNodes; i++) { // node to stop by
		for(int j = 0; j < numOfNodes; j++) { // from
			for(int k = 0; k < numOfNodes; k++) { // to
				int curDistance = graph[j][i] + graph[i][k];
				if(graph[j][i] > 0 && graph[i][k] > 0 && curDistance < 0)
					curDistance = INT_MAX;

				if(curDistance < graph[j][k])
					graph[j][k] = curDistance;
			}
		}
	}
	cout << "Floyd - Warshall's Algorithm" << endl;
	for(int i = 0; i < numOfNodes; i++) {
		for(int j = 0; j < numOfNodes; j++) {
			cout << i << " -> " << j << ": ";
			if(graph[i][j] == INT_MAX)
				cout << "unreachable" << endl;
			else
				cout << graph[i][j] << endl;
		}
	}
}
