// Frogger *AC*

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>
#include <deque>
#include <vector>

using namespace std;

#define sqr(x) ((x) * (x))

class Vertex {
public:
	double x;
	double y;

	Vertex() :
	x(0), y(0) {}

	void set() {
		cin >> x >> y;
	}

	double operator-(Vertex rhs) {
		return sqrt(sqr(x - rhs.x) + sqr(y - rhs.y));
	}

	bool operator==(Vertex rhs) {
		return ((x == rhs.x) && (y == rhs.y));
	}
};

struct Path {
	double dist;
	bool jumped;
};

int main() {
	cout << fixed;

	int numOfRocks;
	for(int curScenario = 1; true; curScenario++) {
		cin >> numOfRocks;
		if(numOfRocks == 0)
			return 0;

		deque<Vertex> rocks;
		for(int i = 0; i < numOfRocks; i++) {
			Vertex input;
			input.set();
			rocks.push_back(input);
		}

		Path empty = {DBL_MAX, false};
		vector< vector<Path> > graph(numOfRocks, vector<Path>(numOfRocks, empty));
		for(int i = 0; i < numOfRocks; i++) {
			for(int j = 0; j < numOfRocks; j++)
				graph[i][j].dist = rocks[i] - rocks[j];
		}

		for(int i = 0; i < numOfRocks; i++) { // between
			for(int j = 0; j < numOfRocks; j++) { // from
				for(int k = 0; k < numOfRocks; k++) { // to
					double totalDist = graph[j][k].dist;
					double firstDist = graph[j][i].dist, secondDist = graph[i][k].dist;

					double minimaxDist = firstDist > secondDist ? firstDist : secondDist;
					minimaxDist = minimaxDist < totalDist ? minimaxDist : totalDist;
					graph[j][k].dist = minimaxDist;
				}
			}
		}

		cout << "Scenario #" << curScenario << endl
			 << "Frog Distance = " << fixed << setprecision(3) << graph[0][1].dist << endl << endl;
	}
}
