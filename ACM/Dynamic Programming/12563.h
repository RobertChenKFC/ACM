// Jin Ge Jin Qu hao *AC*

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SONGS = 55, MAX_TIME = 10000;

struct Song {
	int len;
	int val;
};

int main() {
	int songs[MAX_SONGS];
	Song arr[MAX_TIME];

	int numCases;
	cin >> numCases;
	for(int caseNum = 1; caseNum <= numCases; caseNum++) {
		int numSongs, timeLim, totalSongs = 0;
		cin >> numSongs >> timeLim;
		for(int i = 0; i < numSongs; i++)
			cin >> songs[i], totalSongs += songs[i];
		timeLim--;
		if(totalSongs <= timeLim) {
			cout << "Case " << caseNum << ": " << numSongs + 1 << " " << totalSongs + 678 << endl;
			continue;
		}

		for(int i = 0; i <= timeLim; i++) arr[i] = { 0, 0 };

		for(int i = 0; i < numSongs; i++) {
			for(int j = timeLim; j >= songs[i]; j--) {
				if(arr[j - songs[i]].val + 1 > arr[j].val) {
					arr[j].val = arr[j - songs[i]].val + 1;
					arr[j].len = arr[j - songs[i]].len + songs[i];
				}
				else if((arr[j - songs[i]].val + 1 == arr[j].val) &&
						(arr[j - songs[i]].len + songs[i] > arr[j].len))
					arr[j].len = arr[j - songs[i]].len + songs[i];
			}
		}

		cout << "Case " << caseNum << ": " << arr[timeLim].val + 1 << " " << arr[timeLim].len + 678 << endl;
	}
}
