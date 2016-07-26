// Hartals *AC*

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_DAYS = 3650;

int main() {
	bool days[MAX_DAYS];
	int numCases;
	cin >> numCases;
	while(numCases--) {
		int numDays, numParties;
		cin >> numDays >> numParties;

		memset(days, false, sizeof(bool) * numDays);

		int hartalCnt = 0;
		while(numParties--) {
			int factor;
			cin >> factor;
			for(int i = factor - 1; i < numDays; i += factor) {
				int curDay = i % 7;
				if(curDay != 5 && curDay != 6) {
					if(!days[i])
						hartalCnt++;
					days[i] = true;
				}
			}
		}

		cout << hartalCnt << endl;
	}
}
