// Prime Gap *AC*

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_PRIME = 1299709;
const int PRIME_COUNT = 100000;

int main() {
	bool isPrime[MAX_PRIME + 1];
	memset(isPrime, true, sizeof(isPrime));

	for(int i = 2; true; i++) {
		if(isPrime[i]) {
			if(i * i > MAX_PRIME)
				break;
			for(int j = i * 2; j <= MAX_PRIME; j += i)
				isPrime[j] = false;
		}
	}

	int n;
	cin >> n;
	while(n != 0) {
		if(isPrime[n])
			cout << 0 << endl;
		else {
			int left, right;
			for(left = n - 1; !isPrime[left] && left > 0; left--);
			for(right = n + 1; !isPrime[right] && right < MAX_PRIME - 1; right++);
			cout << right - left << endl;
		}

		cin >> n;
	}
}
