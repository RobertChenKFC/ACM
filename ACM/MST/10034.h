#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

#define SQR(X) ((X) * (X))

struct V {
	double x, y;

	double distFrom(const V &rhs) const { return sqrt(SQR(x - rhs.x) + SQR(y - rhs.y)); }
};

struct Edge {
	int from, to;
	double cost;
};

bool cmp(const Edge &a, const Edge &b) {
	return a.cost < b.cost;
}

int main() {
	int numCases;
	cin >> numCases;
	for(int curCase = 0; curCase < numCases; curCase++) {
		int numFreckles;
		cin >> numFreckles;
		V *freckles = new V[numFreckles];
		for(int i = 0; i < numFreckles; i++)
			cin >> freckles[i].x >> freckles[i].y;

		int numEdges = numFreckles * (numFreckles - 1) / 2;
		Edge *edges = new Edge[numEdges];
		int curEdge = 0;
		for(int i = 0; i < numFreckles; i++) {
			for(int j = i + 1; j < numFreckles; j++) {
				edges[curEdge].from = i;
				edges[curEdge].to = j;
				edges[curEdge++].cost = freckles[i].distFrom(freckles[j]);
			}
		}
		sort(edges, edges + numEdges, cmp);

		// test
		/*
		for(int i = 0; i < numEdges; i++) {
			cout << "(" << edges[i].from << ", " << edges[i].to << ") = " << edges[i].cost << endl;
		}
		*/

		double cost = 0;
		int curEdges = 0, limit = numFreckles - 1;
		int *set = new int[numFreckles];
		for(int i = 0; i < numFreckles; i++) set[i] = i;
		for(int i = 0; i < numEdges && curEdges < limit; i++) {
			if(set[edges[i].from] != set[edges[i].to]) {
				int changeSet = set[edges[i].to];
				for(int j = 0; j < numFreckles; j++)
					if(set[j] == changeSet) set[j] = set[i];
				cost += edges[i].cost;
				curEdges++;
			}
		}
		delete[] set;

		if(curCase != 0) cout << endl;
		cout << setprecision(2) << fixed << cost << endl;

		delete[] edges;
		delete[] freckles;
	}
}
