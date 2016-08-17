// Vertex *AC*

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 105;

void GetReachables(int vertex, int n, bool graph[MAX][MAX], bool reachable[MAX], bool checked[MAX]) {
	checked[vertex] = true;
	for(int i = 0; i < n; i++) {
		if(graph[vertex][i]) {
			reachable[i] = true;
			if(!checked[i]) GetReachables(i, n, graph, reachable, checked);
		}
	}
}

int main() {
	bool graph[MAX][MAX];
	bool reachable[MAX], checked[MAX];

	int n;
	while(cin >> n, n != 0) {
		cin.ignore();

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) graph[i][j] = false;

		string s;
		while(getline(cin, s), s != "0") {
			stringstream ss;
			ss << s;
			int from, to;
			ss >> from;
			while(ss >> to, to != 0) graph[from - 1][to - 1] = true;
		}

		getline(cin, s);
		stringstream ss;
		ss << s;
		int numCheck, vertex;
		ss >> numCheck;
		while(numCheck--) {
			ss >> vertex;
			vertex--;
			memset(reachable, 0, n);
			memset(checked, 0, n);
			GetReachables(vertex, n, graph, reachable, checked);
			int cnt = 0;
			for(int i = 0; i < n; i++) if(!reachable[i]) cnt++;
			cout << cnt;
			if(cnt != 0)
				for(int i = 0; i < n; i++) if(!reachable[i]) cout << " " << i + 1;
			cout << endl;
		}
	}
}
