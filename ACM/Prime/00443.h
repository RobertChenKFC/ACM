// Humble Numbers *AC*

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	const long long limit = 5842, humbleNumberLimit = 2000000000;
	long humbleNumbers[limit];
	memset(humbleNumbers, -1, limit);

	// calculate humble numbers
	int curIndex = 0;
	humbleNumbers[curIndex++] = 1;
	long long curNum2 = 1;
	while(curNum2 * 2 <= humbleNumberLimit) {
		long long curNum3 = curNum2;

		while(curNum3 * 3 <= humbleNumberLimit) {
			long long curNum5 = curNum3;

			while(curNum5 * 5 <= humbleNumberLimit) {
				long long curNum7 = curNum5;

				while(curNum7 * 7 <= humbleNumberLimit) {
					curNum7 *= (long long)7;
					humbleNumbers[curIndex++] = curNum7;
				}

				curNum5 *= (long long)5;
				humbleNumbers[curIndex++] = curNum5;
			}

			curNum3 *= (long long)3;
			humbleNumbers[curIndex++] = curNum3;
		}

		curNum2 *= (long long)2;
		humbleNumbers[curIndex++] = curNum2;
	}

	// sort
	for(int i = 0; i < limit; i++) {
		for(int j = 0; j + i < limit - 1; j++) {
			if(humbleNumbers[j] > humbleNumbers[j + 1]) {
				long long t = humbleNumbers[j];
				humbleNumbers[j] = humbleNumbers[j + 1], humbleNumbers[j + 1] = t;
			}
		}
	}

	// getting input
	int index;
	while(cin >> index) {
		if(index == 0)
			break;

		cout << "The " << index;
		if((index % 100) / 10 != 1) {
			switch(index % 10) {
			case 1:
				cout << "st";
				break;
			case 2:
				cout << "nd";
				break;
			case 3:
				cout << "rd";
				break;
			default:
				cout << "th";
				break;
			}
		}
		else
			cout << "th";

		cout << " humble number is " << humbleNumbers[index - 1] << "." << endl;
	}
}
