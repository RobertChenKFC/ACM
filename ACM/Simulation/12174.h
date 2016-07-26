#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int numCases;
	cin >> numCases;
	for(int curCase = 0; curCase < numCases; curCase++) {
		int numSongs, numHistory;
		cin >> numSongs >> numHistory;

		int* history = new int[numHistory];
		for(int i = 0; i < numHistory; i++) {
			cin >> history[i];
			history[i]--;
		}

		int numValids = 0;
		bool* counted = new bool[numSongs];
		for(int i = 0, start = 0, end = i; i < numSongs; i++, start = 0, end = i) {
			if(end >= numHistory)
				end = numHistory - 1;
			do {

				memset(counted, false, sizeof(bool) * numSongs);

				for(int j = start; j <= end; j++) {
					if(counted[history[j]])
						goto DONE;
					counted[history[j]] = true;
				}

				start = end + 1, end = start + numSongs - 1;
				if(end >= numHistory)
					end = numHistory - 1;
			} while(start < numHistory);

			numValids++;

			DONE:
			continue;
		}
		delete[] counted;

		cout << numValids << endl;

		delete[] history;
	}
}
