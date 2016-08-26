// Coin Change *AC*

#include <iostream>

using namespace std;

const int MAX = 7500;
const int NUM_COINS = 5;

typedef long long int64;

int main() {
	int64 dp[MAX] = { 0 };
	dp[0] = 1;
	int coins[] = { 1, 5, 10, 25, 50 };
	for(int i = 0; i < NUM_COINS; i++) {
		for(int j = coins[i]; j < MAX; j++)
			dp[j] += dp[j - coins[i]];
	}

	int money;
	while(cin >> money) cout << dp[money] << endl;
}
