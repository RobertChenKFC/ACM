#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int MAX_SONGS = 55, MAX_TIME = 10000;
const int JIN_GE_JIN_QU_TIME = 678;

int main() {
	int songs[MAX_SONGS], times[MAX_TIME];
	bool table[MAX_SONGS][MAX_TIME];
	bool chosen[MAX_SONGS];

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
				for(int j = timeLim; j >= songs[i]; j--) {
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

			memset(chosen, false, sizeof(chosen));
			int songsChosen = 0, totalTime = times[timeLim], largest = INT_MIN;
			for(int i = numSongs - 1, j = timeLim; i >= 0; i--) {
				if(table[i][j]) {
					songsChosen++, chosen[i] = true;
					if(songs[i] > largest)
						largest = songs[i];
					j -= songs[i];
				}
			}
			int secondLargest = INT_MIN;
			for(int i = 0; i < numSongs; i++) {
				if(!chosen[i] && songs[i] > secondLargest)
					secondLargest = songs[i];
			}

			if(totalTime == timeLim)
				totalTime += JIN_GE_JIN_QU_TIME - largest + secondLargest;
			else
				totalTime += JIN_GE_JIN_QU_TIME, songsChosen++;

			cout << "Case " << caseNum << ": " << songsChosen << " " << totalTime << endl;
		}
	}
}
