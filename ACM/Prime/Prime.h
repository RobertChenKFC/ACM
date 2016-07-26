// Prime

#include <iostream>

using namespace std;

int main() {
	int limit;
	cout << "Please enter limit: ";
	cin >> limit;

	int* primes = new int[limit];
	primes[0] = 2, primes[1] = 3, primes[2] = 5;

	int gap = 2, curPrime = 3;
	for(int i = 7; i < limit; i += gap) {
		bool isPrime = true;
		for(int j = 0; primes[j] * primes[j] <= i; j++) {
			if(i % primes[j] == 0) {
				isPrime = false;
				break;
			}
		}

		if(isPrime)
			primes[curPrime++] = i;

		gap = 6 - gap;
	}

	cout << endl << "Primes less than " << limit << ": " << endl;
	for(int i = 0, count = 0; i < curPrime; i++, count++) {
		if(count > 30) {
			count = 0;
			cout << endl;
		}
		cout << primes[i] << " ";
		count++;
	}
	cout << endl;

	delete[] primes;
}
