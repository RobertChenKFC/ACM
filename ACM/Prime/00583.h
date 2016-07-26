// Prime Factors *AC*

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long originalNum;
	while(cin >> originalNum) {
		if(originalNum == 0)
			return 0;

		long num = originalNum;

		if(num < 0) {
			num *= -1;
			cout << originalNum << " = -1 x ";
		}
		else
			cout << originalNum << " = ";

		bool first = true;
		// loop for 2
		while(num % 2 == 0) {
			if(!first)
				cout << " x ";
			else
				first = false;
			cout << 2;
			num /= 2;
		}
		// loop for 3
		while(num % 3 == 0) {
			if(!first)
				cout << " x ";
			else
				first = false;
			cout << 3;
			num /= 3;
		}

		// loop for other factors
		long factorLimit = sqrt(originalNum > 0 ? originalNum : -originalNum) + 1;
		for(int i = 5, gap = 2; num != 1 && i <= factorLimit; i += gap, gap = 6 - gap) {
			while(num % i == 0) {
				if(!first)
					cout << " x ";
				else
					first = false;
				cout << i;
				num /= i;
			}
		}

		// if there's something left
		if(num != 1) {
			if(!first)
				cout << " x ";
			cout << num;
		}

		cout << endl;
	}
}
