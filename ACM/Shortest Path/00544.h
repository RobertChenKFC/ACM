// Heavy Cargo *AC*

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
	int numCities, numRoads;
	for(int curScenario = 1; true; curScenario++) {
		cin >> numCities >> numRoads;

		if(numCities == 0 && numRoads == 0)
			return 0;

		vector< vector<int> > graph(numCities, vector<int>(numCities, 0));

		map<string, int> table;
		table.clear();
		for(int i = 0; i < numRoads; i++) {
			string fromCity, toCity;
			cin >> fromCity >> toCity;
			if(table.find(fromCity) == table.end())
				table[fromCity] = table.size() - 1;
			if(table.find(toCity) == table.end())
				table[toCity] = table.size() - 1;

			int dist;
			cin >> dist;
			int from = table[fromCity], to = table[toCity];
			int finalDist = graph[from][to];
			finalDist = finalDist > dist ? finalDist : dist;
			graph[from][to] = finalDist, graph[to][from] = finalDist;
		}

		for(int i = 0; i < numCities; i++) { // between
			for(int j = 0; j < numCities; j++) { // from
				for(int k = 0; k < numCities; k++) { // to
					int total = graph[j][k];
					int first = graph[j][i], second = graph[i][k];

					int maximin = first < second ? first : second;
					maximin = maximin > total ? maximin : total;
					graph[j][k] = maximin;
				}
			}
		}
		string startCity, endCity;
		cin >> startCity >> endCity;
		int start = table[startCity], end = table[endCity];
		cout << "Scenario #" << curScenario << endl
			 << graph[start][end] << " tons" << endl << endl;

		for(int i = 0; i < numCities; i++)
			graph[i].clear();
		graph.clear();
		table.clear();
	}
}
