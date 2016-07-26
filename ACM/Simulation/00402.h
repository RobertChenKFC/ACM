// M*A*S*H *AC*

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_PEOPLE = 50, NUM_CARDS = 20;

int main() {
	bool people[MAX_PEOPLE];
	int cards[NUM_CARDS];
	int numPeople, numSpots;
	for(int curSelection = 1; true; curSelection++) {
		if(!(cin >> numPeople))
			return 0;
		cin >> numSpots;

		memset(people, true, sizeof(bool) * numPeople);
		for(int i = 0; i < NUM_CARDS; i++)
			cin >> cards[i];

		int totalSpots = numPeople;
		for(int i = 0; i < NUM_CARDS && totalSpots > numSpots; i++) {
			int cur = 0, eliminate = 0;
			while(eliminate < numPeople && totalSpots > numSpots) {
				bool found = false;
				for(cur = 0; eliminate < numPeople; eliminate++) {
					if(people[eliminate])
						cur++;
					if(cur == cards[i]) {
						found = true;
						break;
					}
				}
				if(found) {
					people[eliminate] = false;
					totalSpots--;
				}

				eliminate++;
			}
		}

		cout << "Selection #" << curSelection << endl;
		bool first = true;
		for(int i = 0; i < numPeople; i++) {
			if(people[i]) {
				if(!first)
					cout << " ";
				else
					first = false;
				cout << i + 1;
			}
		}
		cout << endl << endl;
	}
}
