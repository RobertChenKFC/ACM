// Simply Emirp *AC*

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long num) {
	bool isPrimeNum = num % 2 != 0 || num == 2;
	long limit = sqrt(num) + 1;
	for(int i = 3; i < limit && isPrimeNum; i += 2) {
		if(num % i == 0)
			isPrimeNum = false;
	}
	return isPrimeNum;
}

int main() {
	long input;
	while(cin >> input) {
		bool inputIsPrime = isPrime(input);

		long num = input, reverse = 0;
		while(num != 0) {
			reverse *= 10;
			reverse += num % 10;
			num /= 10;
		}
		bool reverseIsPrime = isPrime(reverse);

		if(inputIsPrime) {
			if(reverseIsPrime && reverse != input)
				cout << input << " is emirp." << endl;
			else
				cout << input << " is prime." << endl;
		}
		else
			cout << input << " is not prime." << endl;
	}
}
