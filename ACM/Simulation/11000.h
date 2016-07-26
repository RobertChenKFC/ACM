#include <iostream>

using namespace std;

int main() {
	int numYears;
	while(true) {
		cin >> numYears;
		if(numYears == -1)
			return 0;

		long male = 0, female = 0;
		long newMale = 0, newFemale = 0;
		for(int i = 0; i < numYears; i++) {
			// female bees
			newMale += female;
			newFemale = 0;

			// male bees
			newFemale += male;

			// magical female bee
			newMale++;

			male = newMale, female = newFemale;
		}
		// magical female bee
		female++;

		cout << male << " " << male + female << endl;
	}
}
