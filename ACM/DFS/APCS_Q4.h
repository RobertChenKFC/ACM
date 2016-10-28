#include <iostream>
#include <cstring>

using namespace std;

struct Info {
	int point;
	int depth;
};

bool **graph;
int n;

Info DFS(const int &start, const int &parent, int depth) {
	int maxi = -1;
	Info max = { -1, -1 }, cur;
	for(int i = 0; i < n; i++) {
		if(graph[start][i] && i != parent) {
			cur = DFS(i, start, depth + 1);
			if(cur.depth > max.depth) maxi = i, max = cur;
		}
	}

	if(maxi == -1) return { start, depth };
	else return max;
}

int main() {
	cin >> n;

	graph = new bool*[n];
	for(int i = 0; i < n; i++) {
		graph[i] = new bool[n];
		memset(graph[i], 0, sizeof(bool) * n);
	}

	int a, b;
	for(int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		graph[a][b] = graph[b][a] = true;
	}

	int start = DFS(0, 0, 0).point;
	cout << DFS(start, start, 0).depth << endl;

	for(int i = 0; i < n; i++) delete[] graph[i];
	delete[] graph;
}
