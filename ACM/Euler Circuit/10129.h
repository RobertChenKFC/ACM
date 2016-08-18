// Play On Words *AC*

#include <iostream>
#include <string>

using namespace std;

void DFS(bool graph[30][30], bool visited[30], int cur) {
	visited[cur] = true;
	for(int i = 0; i < 26; i++)
		if(!visited[i] && (graph[cur][i] || graph[i][cur])) DFS(graph, visited, i);
}

int main() {
	bool graph[30][30], inWords[30], visited[30];
	int inDeg[30], outDeg[30];

	int numCases;
	cin >> numCases;
	while(numCases--) {
		for(int i = 0; i < 30; i++) {
			for(int j = 0; j < 30; j++) graph[i][j] = false;
			inWords[i] = false, visited[i] = false;
			inDeg[i] = 0, outDeg[i] = 0;
		}

		int numWords;
		cin >> numWords;
		string word;
		int from, to;
		while(numWords--) {
			cin >> word;
			from = word[0] - 'a', to = word[word.length() - 1] - 'a';
			graph[from][to] = true;
			inWords[from] = true, inWords[to] = true;
			inDeg[to]++, outDeg[from]++;
		}

		int n = 0, start, connected = 0;
		for(int i = 0; i < 26; i++) if(inWords[i]) n++, start = i;
		DFS(graph, visited, start);
		for(int i = 0; i < 26; i++) if(visited[i]) connected++;

		if(n != connected) cout << "The door cannot be opened." << endl;
		else {
			bool isEulerCircuit = true;
			int inDegMore = 0, outDegMore = 0, nonValid = 0;
			for(int i = 0; i < 26; i++) {
				if(inWords[i]) {
					if(inDeg[i] == outDeg[i] + 1) inDegMore++;
					else if(inDeg[i] + 1 == outDeg[i]) outDegMore++;
					else if(inDeg[i] != outDeg[i]) {
						isEulerCircuit = false, nonValid++;
						break;
					}
				}
			}
			if(isEulerCircuit || ((inDegMore == outDegMore) && (nonValid == 0)))
				cout << "Ordering is possible." << endl;
			else
				cout << "The door cannot be opened." << endl;
		}
	}
}
