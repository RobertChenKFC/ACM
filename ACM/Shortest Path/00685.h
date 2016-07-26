// Least Path Cost *AC*

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <climits>
#include <cmath>

using namespace std;

class Vertex {
public:
	Vertex(int i = 0, int j = 0) :
	i(i), j(j) {

	}

	bool operator==(Vertex rhs) {
		return (i == rhs.i) && (j == rhs.j);
	}

	bool operator<(const Vertex rhs) const {
		if(i < rhs.i)
			return true;
		if(i == rhs.i && j < rhs.j)
			return true;
		return false;
	}

	int i, j;
};

int main() {
	int numTests;
	cin >> numTests;
	for(int a = 0; a < numTests; a++) {
		int numNodes, numSegs, overhead;
		cin >> numSegs >> numNodes >> overhead;

		vector< vector<int> > graph(numNodes, vector<int>(numNodes, INT_MAX));
		for(int i = 0, j = 0; i < numNodes; i++, j++)
			graph[i][j] = 0;
		vector<int> connected(numNodes, 0);
		map<Vertex, int> table;
		for(int i = 0; i < numSegs; i++) {
			int from, to, height;
			cin >> from >> to >> height;
			from--, to--;

			graph[from][to] = height, graph[to][from] = height;
			connected[from]++, connected[to]++;
			table[Vertex(from, to)] = i, table[Vertex(to, from)] = i;
		}

		vector< vector<int> > heights(numSegs, vector<int>(numSegs, INT_MAX));
		for(int i = 0, j = 0; i < numSegs; i++, j++)
			heights[i][j] = 0;
		vector<bool> endSegs(numSegs, false);
		for(int i = 0; i < numNodes; i++) {
			for(int j = 0; j < numNodes; j++) {
				for(int k = 0; k < numNodes; k++) {
					if(i != j && j != k && i != k && graph[i][j] != INT_MAX && graph[j][k] != INT_MAX) {
						int seg1 = table[Vertex(i, j)], seg2 = table[Vertex(j, k)];
						heights[seg1][seg2] = abs(graph[i][j] - graph[j][k]) + overhead,
						heights[seg2][seg1] = abs(graph[i][j] - graph[j][k]) + overhead;
						if(connected[i] == 1 || connected[j] == 1)
							endSegs[seg1] = true;
						if(connected[j] == 1 || connected[k] == 1)
							endSegs[seg2] = true;
					}
				}
			}
		}

		int leastPath = INT_MAX;
		for(int start = 0; start < numSegs; start++) {
			for(int end = 0; end < numSegs; end++) {
				if(start != end && endSegs[start] && endSegs[end]) {
					vector<int> dist(numSegs, INT_MAX);
					vector<bool> marked(numSegs, false);

					int curStart = start;
					dist[curStart] = overhead;
					while(true) {
						marked[curStart] = true;

						for(int i = 0; i < numSegs; i++) {
							if(curStart != i) {
								int newDist = dist[curStart] + heights[curStart][i];
								if(newDist < 0)
									newDist = INT_MAX;
								if(newDist < dist[i])
									dist[i] = newDist;
							}
						}

						int minDist = INT_MAX, minIndex = -1;
						for(int i = 0; i < numSegs; i++) {
							if(!marked[i] && dist[i] < minDist)
								minDist = dist[i], minIndex = i;
						}

						if(minIndex == -1)
							break;
						else
							curStart = minIndex;
					}

					if(dist[end] < leastPath)
						leastPath = dist[end];
				}
			}
		}

		cout << leastPath << endl;
	}
}
