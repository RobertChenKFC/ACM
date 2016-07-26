// Audiophobia *AC*

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int numCross, numStr, numPath;
	bool first = true;
	for(int curCase = 1; true; curCase++) {
		cin >> numCross >> numStr >> numPath;

		if(numCross == 0 && numStr == 0 && numPath == 0)
			return 0;

		vector< vector<int> > graph(numCross, vector<int>(numCross, INT_MAX));

		for(int i = 0; i < numStr; i++) {
			int a, b, db;
			cin >> a >> b >> db;
			a--, b--;

			int finalDb = graph[a][b];
			finalDb = finalDb < db ? finalDb : db;
			graph[a][b] = finalDb, graph[b][a] = finalDb;
		}

		for(int i = 0; i < numCross; i++) {
			for(int j = 0; j < numCross; j++) {
				for(int k = 0; k < numCross; k++) {
					int total = graph[j][k];
					int first = graph[j][i], second = graph[i][k];

					int minimax = first > second ? first : second;
					minimax = minimax < total ? minimax : total;
					graph[j][k] = minimax;
				}
			}
		}

		if(!first)
			cout << endl;
		first = false;
		cout << "Case #" << curCase << endl;
		for(int a = 0; a < numPath; a++) {
			int from, to;
			cin >> from >> to;
			from--, to--;

			int db = graph[from][to];
			if(db == INT_MAX)
				cout << "no path" << endl;
			else
				cout << db << endl;
		}
	}
}
