// Network *AC*

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 105;
const int NOT_FOUND = -1;

int APCnt = 0;

void DFS(bool graph[MAX][MAX], int n,
		int order[MAX], int lowest[MAX],
		int me = 0, int father = NOT_FOUND, int cur = 0) {
	order[me] = lowest[me] = cur;
	int child = 0;
	bool isAP = false;
	for(int i = 0; i < n; i++) {
		if(graph[me][i]) {
			if(order[i] == NOT_FOUND) {
				child++;
				DFS(graph, n, order, lowest, i, me, cur + 1);
				if(lowest[i] < lowest[me]) lowest[me] = lowest[i];
				if(lowest[i] >= order[me]) isAP = true;
			}
			else if(i != father && lowest[me] > order[i]) lowest[me] = order[i];
		}
	}

	if((father == NOT_FOUND && child >= 2) || (father != NOT_FOUND && isAP)) APCnt++;
}

int FindAP(bool graph[MAX][MAX], int n) {
	int order[MAX], lowest[MAX];
	for(int i = 0; i < n; i++) order[i] = NOT_FOUND;
	APCnt = 0;
	DFS(graph, n, order, lowest);
	return APCnt;
}

int main() {
	bool graph[MAX][MAX];

	int n;
	string s;
	while(cin >> n, n != 0) {
		cin.ignore();

		memset(graph, 0, sizeof(graph));

		while(getline(cin, s), s != "0") {
			stringstream ss;
			ss << s;
			int a, b;
			ss >> a;
			a--;
			while(ss >> b) {
				b--;
				graph[a][b] = true, graph[b][a] = true;
			}
		}

		cout << FindAP(graph, n) << endl;
	}
}
