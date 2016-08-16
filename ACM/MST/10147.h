#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

struct Edge {
	int a, b;
	double cost;
};

struct Vertex {
	double x, y;
	int set;

	double distFrom(const Vertex &rhs) {
		double dX = x - rhs.x, dY = y - rhs.y;
		return sqrt(dX * dX + dY * dY);
	}
};

const int MAX_TOWNS = 755;

bool cmp(const Edge &a, const Edge &b) {
	return a.cost < b.cost;
}

int main() {
	int numCases;
	cin >> numCases;

	Vertex towns[MAX_TOWNS];
	bool connected[MAX_TOWNS][MAX_TOWNS];
	Edge highways[MAX_TOWNS * (MAX_TOWNS - 1) / 2];

	for(int curCase = 0; curCase < numCases; curCase++) {
		int numTowns;
		cin >> numTowns;
		for(int i = 0; i < numTowns; i++) {
			cin >> towns[i].x >> towns[i].y;
			towns[i].set = i;
		}

		for(int i = 0; i < numTowns; i++) memset(connected, 0, numTowns);
		int connections;
		cin >> connections;
		int a, b;
		while(connections--) {
			cin >> a >> b;
			connected[a - 1][b - 1] = true, connected[b - 1][a - 1] = true;
		}

		int curHighway = 0;
		for(int i = 0; i < numTowns; i++) {
			for(int j = i + 1; j < numTowns; j++, curHighway++) {
				highways[curHighway].a = i;
				highways[curHighway].b = j;
				if(connected[i][j]) highways[curHighway].cost = 0;
				else highways[curHighway].cost = towns[i].distFrom(towns[j]);
			}
		}

		sort(highways, highways + curHighway, cmp);

		if(curCase != 0) cout << endl;

		bool fullyConnected = true;
		for(int i = 0; i < curHighway; i++) {
			int a = highways[i].a, b = highways[i].b;
			if(towns[a].set != towns[b].set) {
				int setToChange = towns[a].set, changeToSet = towns[b].set;
				for(int j = 0; j < numTowns; j++)
					if(towns[j].set == setToChange) towns[j].set = changeToSet;
				if(!connected[a][b]) {
					cout << a + 1 << " " << b + 1 << endl;
					fullyConnected = false;
				}
			}
		}
		if(fullyConnected) cout << "No new highways need" << endl;
	}
}
