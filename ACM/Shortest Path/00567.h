#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	for(int curScenario = 1; true; curScenario++) {
		int graph[20][20];
		for(int i = 0; i < 20; i++) {
			for(int j = 0; j < 20; j++)
				graph[i][j] = INT_MAX;
		}

		for(int i = 0; i < 19; i++) {
			int contacts;
			if(!(cin >> contacts)) {
				cout << endl;
				return 0;
			}

			for(int j = 0; j < contacts; j++) {
				int neighbor;
				cin >> neighbor;
				graph[i][neighbor - 1] = 1, graph[neighbor - 1][i] = 1;
			}
		}

		if(curScenario != 1)
			cout << endl;
		cout << "Test Set #" << curScenario << endl;
		int calculations;
		cin >> calculations;
		for(int i = 0; i < calculations; i++) {
			int from, to;
			cin >> from >> to;
			from--, to--;

			int length[20];
			bool marked[20];
			for(int j = 0; j < 20; j++)
				length[j] = INT_MAX, marked[j] = false;

			int start = from;
			length[start] = 0;
			while(true) {
				marked[start] = true;

				for(int j = 0; j < 20; j++) {
					int curDist = length[start] + graph[start][j];
					if(curDist < 0)
						curDist = INT_MAX;
					if(curDist < length[j] && j != start)
						length[j] = curDist;
				}

				int minDist = INT_MAX, minIndex = -1;
				for(int j = 0; j < 20; j++) {
					if(length[j] < minDist && !marked[j])
						minDist = length[j], minIndex = j;
				}

				if(minIndex == -1)
					break;
				else
					start = minIndex;
			}

			 if(from + 1 < 10)
				 cout << " ";
			 cout << from + 1 << " to ";
			 if(to + 1 < 10)
				 cout << " ";
			 cout << to + 1 << ": " << length[to] << endl;
		}
	}
}
