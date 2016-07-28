#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SONGS = 55, MAX_TIME = 10000;

int main() {
	int songs[MAX_SONGS], arr[MAX_TIME];

	int numCases;
	while(numCases--) {
		int numSongs, timeLim;
		cin >> numSongs >> timeLim;
		for(int i = 0; i < numSongs; i++)
			cin >> songs[i];
		timeLim--;

		memset(arr, 0, sizeof(arr));
		for(int i = 0; i < numSongs; i++) {
			for(int j = timeLim - 1; j >= songs[i]; j--) {
				if(arr[j - songs[i]] + 1 > arr[j])
					arr[j] = arr[j - songs[i]] + 1;
			}
		}


	}
}
