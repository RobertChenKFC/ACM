// Prime Cuts *AC*

#include <iostream>

using namespace std;

int main() {
	int limit, center;
	while(cin >> limit >> center) {
		int* primes = new int[limit];
		primes[0] = 1, primes[1] = 2, primes[2] = 3, primes[3] = 5;

		int count;
		if(limit > 5) {
			count = 4;
			for(int i = 7, gap = 2; i <= limit; i += gap) {
				bool isPrime = true;
				for(int j = 1; primes[j] * primes[j] <= i; j++) {
					if(i % primes[j] == 0) {
						isPrime = false;
						break;
					}
				}

				if(isPrime)
					primes[count++] = i;

				gap = 6 - gap;
			}
		}
		else {
			switch(limit) {
			case 1:
				count = 1;
				break;
			case 2:
				count = 2;
				break;
			case 3:
				count = 3;
				break;
			case 4:
				count = 3;
				break;
			case 5:
				count = 4;
				break;
			}
		}

		int startIndex, endIndex;
		if(count % 2 == 0)
			startIndex = (count - center * 2) / 2, endIndex = startIndex + center * 2 - 1;
		else
			startIndex = (count - (center * 2 - 1)) / 2, endIndex = startIndex + (center * 2 - 1) - 1;
		if(startIndex < 0 || startIndex > count - 1)
			startIndex = 0, endIndex = count - 1;

		cout << limit << " " << center << ": ";
		for(int i = startIndex; i <= endIndex; i++) {
			cout << primes[i];
			if(i != endIndex)
				cout << " ";
		}
		cout << endl << endl;


		delete[] primes;
	}
}
