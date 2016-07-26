// Divisor *AC*

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int numOfTests;
	cin >> numOfTests;

	long low, high;
	for(int a = 0; a < numOfTests; a++) {
		cin >> low >> high;

		long maxFactors = -1, maxFactorNum;
		for(long i = low; i <= high; i++) {
			long curNum = i, totalFactors = 1;

			// loop for 2
			int curPower = 1;
			while(curNum % 2 == 0) {
				curNum /= 2;
				curPower++;
			}
			totalFactors *= curPower, curPower = 1;

			// loop for 3
			while(curNum % 3 == 0) {
				curNum /= 3;
				curPower++;
			}
			totalFactors *= curPower, curPower = 1;

			// loop for others
			long factorLimit = sqrt(i) + 1;
			bool looped = false;
			for(long j = 5, gap = 2; curNum != 1 && j <= factorLimit; j += gap, gap = 6 - gap, looped = false) {
				while(curNum % j == 0) {
					looped = true;

					curNum /= j;
					curPower++;
				}

				if(looped)
					totalFactors *= curPower, curPower = 1;
			}

			// if there's something left
			if(curNum != 1)
				totalFactors *= 2;

			if(totalFactors > maxFactors)
				maxFactors = totalFactors, maxFactorNum = i;
		}

		cout << "Between " << low << " and " << high << ", "
				<< maxFactorNum << " has a maximum of " << maxFactors << " divisors." << endl;
	}
}
