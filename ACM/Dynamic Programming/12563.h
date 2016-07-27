#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int MAX_SONGS = 55, MAX_TIME = 10000;
const int JIN_GE_JIN_QU_TIME = 678;

int main() {
	int songs[MAX_SONGS], times[MAX_TIME];
	bool table[MAX_SONGS][MAX_TIME];

	int numCases;
	cin >> numCases;
	for(int caseNum = 1; caseNum <= numCases; caseNum++) {
		int numSongs, timeLim;
		cin >> numSongs >> timeLim;
		int songTime = 0;
		for(int i = 0; i < numSongs; i++)
			cin >> songs[i], songTime += songs[i];

		if(songTime + JIN_GE_JIN_QU_TIME <= timeLim)
			cout << "Case " << caseNum << ": " << numSongs + 1 << " " << songTime + JIN_GE_JIN_QU_TIME << endl;
		else {
			memset(times, 0, sizeof(times));
			for(int i = 0; i < numSongs; i++)
				memset(table[i], false, sizeof(table[i]));
			for(int i = 0; i < numSongs; i++) {
				for(int j = timeLim - 1; j >= songs[i]; j--) {
					if(times[j - songs[i]] + songs[i] > times[j]) {
						times[j] = times[j - songs[i]] + songs[i];
						table[i][j] = true;
					}
				}
			}

			// test
			/*
			cout << "table: " << endl;
			for(int i = 0; i < numSongs; i++) {
				for(int j = 0; j < timeLim; j++)
					cout << table[i][j] << " ";
				cout << endl;
			}
			*/

			int songsChosen = 0, totalTime;
			if(times[timeLim - 1] == timeLim) {
				int shortest = INT_MAX;
				int i = numSongs - 1, j = timeLim - 1;
				while(true) {
					if(!table[i][j]) {
						if(i == 0)
							break;
						i--;
					}
					else {
						songsChosen++;
						if(shortest > songs[i])
							shortest = songs[i];
						if(i == 0)
							break;
						j = timeLim - songs[i] - 1, i--;
					}
				}
				totalTime = times[timeLim - 1] - shortest + JIN_GE_JIN_QU_TIME;
			}
			else {
				int i = numSongs - 1, j = timeLim - 1;
				while(true) {
					if(!table[i][j]) {
						if(i == 0)
							break;
						i--;
					}
					else {
						songsChosen++;
						if(i == 0)
							break;
						j = timeLim - songs[i] - 1, i--;
					}
				}
				songsChosen++, totalTime = times[timeLim - 1] + JIN_GE_JIN_QU_TIME;
			}
			cout << "Case " << caseNum << ": " << songsChosen << " " << totalTime << endl;
		}
	}
}
