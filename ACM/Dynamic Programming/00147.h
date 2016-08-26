// Dollars *AC*

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 30005 / 5;
const int NUM_CURRENCY = 11;

typedef long long int64;

int main() {
	int currency[] = { 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000 };
	int64 dp[MAX] = { 0 };
	dp[0] = 1;
	for(int i = 0; i < NUM_CURRENCY; i++) {
		for(int j = currency[i]; j < MAX; j++)
			dp[j] += dp[j - currency[i]];
	}

	double money;
	int cents;
	while(cin >> money, money != 0) {
		cents = money * 20;
		cout << setfill(' ') << setw(6) << setprecision(2) << fixed << money << setw(17) << dp[cents] << endl;
	}
}
