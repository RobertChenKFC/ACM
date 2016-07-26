// The Tourist Guide *AC*

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int numCities, numRds;
	for(int curScenario = 1; true; curScenario++) {
		cin >> numCities >> numRds;

		if(numCities == 0 && numRds == 0)
			return 0;

		vector< vector<int> > graph(numCities, vector<int>(numCities, 0));

		for(int i = 0; i < numRds; i++) {
			int from, to, maxLimit;
			cin >> from >> to >> maxLimit;
			from--, to--;

			int finalLimit = graph[from][to];
			finalLimit = finalLimit > maxLimit ? finalLimit : maxLimit;
			graph[from][to] = finalLimit, graph[to][from] = finalLimit;
		}

		for(int i = 0; i < numCities; i++) {
			for(int j = 0; j < numCities; j++) {
				for(int k = 0; k < numCities; k++) {
					int total = graph[j][k];
					int first = graph[j][i], second = graph[i][k];

					int maximin = first < second ? first : second;
					maximin = maximin > total ? maximin : total;
					graph[j][k] = maximin;
				}
			}
		}

		int start, end, numPeople;
		cin >> start >> end >> numPeople;
		start--, end--;
		double numTrips = (double)numPeople / (double)(graph[start][end] - 1);
		if(numTrips - (double)((int)numTrips) != 0)
			numTrips++;
		numTrips = (int)numTrips;
		cout << "Scenario #" << curScenario << endl
			 << "Minimum Number of Trips = " << numTrips << endl << endl;
	}
}
