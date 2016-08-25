// Prime Time *AC*

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

#define FORMULA(X) ((X) * (X) + (X) + 41)

const int MAX_N = 10000;
const int MAX = FORMULA(MAX_N);
const double EPS = 1.e-10;

const char NOTHING = 0, IS_PRIME = 1, IS_CORRECT = 2;

int main() {
	bool correct[MAX_N + 1];
	for(int i = 0, cur; cur = FORMULA(i), cur <= MAX; i++) {
		int lim = sqrt(cur) + 1;
		bool isPrime = true;
		for(int j = 2; j <= lim; j++) {
			if(cur % j == 0) {
				isPrime = false;
				break;
			}
		}
		if(isPrime) correct[i] = true;
		else correct[i] = false;
	}

	int from, to;
	while(cin >> from >> to) {
		int total = to - from + 1, cnt = 0;
		for(int i = from; i <= to; i++)
			if(correct[i]) cnt++;

		cout << fixed << setprecision(2) << static_cast<double>(cnt) / total * 100 + EPS << endl;
	}
}
