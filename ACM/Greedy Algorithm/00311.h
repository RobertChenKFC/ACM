// Packets *AC*

#include <iostream>

using namespace std;

int main() {
	int parcels[7];
	while(true) {
		for(int i = 1; i <= 6; i++)
			cin >> parcels[i];

		bool quit = true;
		for(int i = 1; i <= 6; i++) {
			if(parcels[i] != 0) {
				quit = false;
				break;
			}
		}
		if(quit)
			return 0;

		int cnt = 0;

		// 6x6
		cnt += parcels[6];

		// 5x5
		for(int i = 0; i < parcels[5]; i++) {
			cnt++;
			// 1x1
			parcels[1] -= 11; // 11 is the space left after 1 5x5 is placed
		}

		// 4x4
		while(parcels[4]--) {
			cnt++;
			int spaceLeft = 20; // 20 is the space left after 1 4x4 is placed
			// 2x2
			int palletsPut = spaceLeft / 4;
			if(parcels[2] < palletsPut)
				palletsPut = parcels[2], parcels[2] = 0;
			else
				parcels[2] -= palletsPut;
			spaceLeft -= palletsPut * 4;
			// 1x1
			parcels[1] -= spaceLeft;
		}

		// 3x3
		while(parcels[3] > 0) {
			cnt++;
			if(parcels[3] >= 4)
				parcels[3] -= 4;
			else if(parcels[3] == 3) {
				parcels[3] = 0;
				int spaceLeft = 9; // 9 is the space left after 3 3x3s are placed
				// 2 x 2
				if(parcels[2] >= 1) // 1 is the maximum for placing 2x2s
					parcels[2]--, spaceLeft -= 4;
				// 1 x 1
				parcels[1] -= spaceLeft;
			}
			else if(parcels[3] == 2) {
				parcels[3] = 0;
				int spaceLeft = 18; // 18 is the space left after 2 3x3s are placed
				// 2 x 2
				if(parcels[2] >= 3) // 3 is the maximum for placing 2x2s
					parcels[2] -= 3, spaceLeft -= 12;
				else
					spaceLeft -= parcels[2] * 4, parcels[2] = 0; // 4 is the space taken by each 2 x 2
				// 1 x 1
				parcels[1] -= spaceLeft;
			}
			else if(parcels[3] == 1) {
				parcels[3] = 0;
				int spaceLeft = 27; // 27 is the space left after 1 3x3 is placed
				// 2 x 2
				if(parcels[2] >= 5) // 5 is the maximum for placing 2x2s
					parcels[2] -= 5, spaceLeft -= 20; // 20 is the space taken by the 2x2s
				else
					spaceLeft -= parcels[2] * 4, parcels[2] = 0; // 4 is the space taken by each 2 x 2
				// 1 x 1
				parcels[1] -= spaceLeft;
			}
		}

		// 2 x 2
		while(parcels[2] > 0) {
			cnt++;
			int spaceLeft = 36; // 36 is the parcel size
			if(parcels[2] >= 9)
				parcels[2] -= 9, spaceLeft = 0; // no more space after 2x2s are placed
			else
				spaceLeft -= parcels[2] * 4, parcels[2] = 0; // 4 is the space taken by each 2x2
			// 1 x 1
			parcels[1] -= spaceLeft;
		}

		// 1 x 1
		while(parcels[1] > 0) {
			cnt++;
			parcels[1] -= 36;
		}

		cout << cnt << endl;
	}
}
