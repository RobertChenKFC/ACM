// Shipping Routes *AC*

#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int numOfSets;
	cin >> numOfSets;

	cout << "SHIPPING ROUTES OUTPUT" << endl << endl;
	for(int dataNum = 1; dataNum <= numOfSets; dataNum++) {
		cout << "DATA SET  " << dataNum << endl << endl;

		int numOfContainers, numOfRelations, numOfShipments;
		cin >> numOfContainers >> numOfRelations >> numOfShipments;

		map<string, int> table;
		table.clear();
		for(int i = 0; i < numOfContainers; i++) {
			string container;
			cin >> container;
			if(table.find(container) == table.end())
				table[container] = table.size() - 1;
		}

		vector< vector<int> > graph(numOfContainers, vector<int>(numOfContainers, INT_MAX));
		for(int i = 0; i <  numOfRelations; i++) {
			string a, b;
			cin >> a >> b;
			graph[table[a]][table[b]] = 1;
			graph[table[b]][table[a]] = 1;
		}

		for(int x = 0; x < numOfShipments; x++) {
			int size;
			cin >> size;

			vector<int> dist(numOfContainers, INT_MAX);
			vector<bool> marked(numOfContainers, false);

			string a, b;
			cin >> a >> b;
			int start = table[a], end = table[b];
			dist[start] = 0;
			while(true) {
				marked[start] = true;

				for(int i = 0; i < numOfContainers; i++) {
					int curDist = dist[start] + graph[start][i];
					if(curDist < 0)
						curDist = INT_MAX;

					if(curDist < dist[i] && i != start)
						dist[i] = curDist;
				}

				int minI = -1, minDist = INT_MAX;
				for(int i = 0; i < numOfContainers; i++) {
					if(dist[i] < minDist && !marked[i])
						minI = i, minDist = dist[i];
				}

				if(minI == -1)
					break;
				else
					start = minI;
			}

			if(dist[end] == INT_MAX)
				cout << "NO SHIPMENT POSSIBLE" << endl;
			else
				cout << "$" << size * dist[end] * 100 << endl;
		}

		cout << endl;
	}

	cout << "END OF OUTPUT" << endl;
}
