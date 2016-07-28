#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

struct Song {
	int length;
	int value;
};

struct Knapsack {
	int length;
	int value;
};

const int MAX_SONGS = 55, MAX_TIME_LIM = 10000;
const int LONG_SONG_TIME = 678;
const Knapsack EMPTY = { 0, 0 };

#define ABS(X) ((X) > 0 ? (X) : -(X))

int main() {
	Song songs[MAX_SONGS];
	Knapsack arr[MAX_TIME_LIM];
	bool map[MAX_SONGS][MAX_TIME_LIM];
	int num = 1;

	int numCases;
	cin >> numCases;
	while(numCases--) {
		int numSongs, timeLim;
		cin >> numSongs >> timeLim;
		for(int i = 0; i < numSongs; i++) {
			cin >> songs[i].length;
			songs[i].value = 1;
		}

		for(int i = 0; i <= timeLim; i++)
			arr[i] = EMPTY;
		for(int i = 0; i < MAX_SONGS; i++)
			memset(map[i], false, sizeof(map[i]));
		for(int i = 0; i < numSongs; i++) {
			for(int j = timeLim; j >= songs[i].length; j--) {
				if(arr[j - songs[i].length].value + songs[i].value > arr[j].value) {
					arr[j].value = arr[j - songs[i].length].value + songs[i].value;
					arr[j].length = arr[j - songs[i].length].length + songs[i].length;
					map[i][j] = true;
				}
				else if((arr[j - songs[i].length].value + songs[i].value == arr[j].value) &&
						(arr[j - songs[i].length].length + songs[i].length > arr[j].length)) {
					arr[j].value = arr[j - songs[i].length].value + songs[i].value;
					arr[j].length = arr[j - songs[i].length].length + songs[i].length;
					map[i][j] = true;
				}
			}
		}

		if(arr[timeLim].length == timeLim) {
			int songsChosen = 0, minGap = INT_MAX, replace, replaceWith;
			for(int i = numSongs - 1, j = timeLim; i >= 0; i--) {
				if(map[i][j]) {
					songsChosen++;
					int curGap = INT_MAX, curReplaceWith;
					for(int j = 0; j < numSongs; j++) {
						int diff = songs[i].length - songs[j].length;
						if(diff > 0 && diff < curGap)
							curGap = diff, curReplaceWith = j;
					}
					if(curGap < minGap)
						minGap = curGap, replace = i, replaceWith = curReplaceWith;
				}
			}

			int totalTime = arr[timeLim].length - songs[replace].length + songs[replaceWith].length + LONG_SONG_TIME;

			cout << "Case " << num++ << ": "
				 << songsChosen << " " << totalTime << endl;
		}
		else {
			int songsChosen = 0;
			for(int i = numSongs - 1, j = timeLim; i >= 0; i--) {
				if(map[i][j]) {
					songsChosen++;
					j -= songs[i].length;
				}
			}

			cout << "Case " << num++ << ": "
				 << songsChosen + 1 << " " << arr[timeLim].length + LONG_SONG_TIME << endl;
		}
	}
}
