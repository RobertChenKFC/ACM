// The Snail *AC*

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	double height, climb, fall, fatigue;
	while(true) {
		cin >> height;
		if(height == 0)
			break;
		cin >> climb >> fall >> fatigue;

		fatigue = fatigue / (double)100 * climb;

		double cur = 0;
		int day = 0;
		do {
			day++;

			// climb
			cur += climb;
			if(cur > height)
				break;

			// fall
			cur -= fall;

			// fatigue
			climb -= fatigue;
			if(climb < 0)
				climb = 0;
		} while(cur >= 0);

		if(cur > height)
			cout << "success on day " << day << endl;
		else
			cout << "failure on day " << day << endl;
	}
}
