#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int MAX = 505 / 5;
const int NUM_COINS = 6;

int main() {
	int coins[] = { 1, 2, 4, 10, 20, 40 };
	int dp[MAX];
	int coinLim[NUM_COINS];
	double money;
	int cents;

	while(true) {
		bool allZero = true;
		for(auto &x : coinLim) {
			cin >> x;
			if(x != 0) allZero = false;
		}
		if(allZero) break;

		cin >> money;
		cents = money * 20;

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int limit;
		for(int i = 0; i < NUM_COINS; i++) {
			limit = coins[i] * (coinLim[i] + 1) - 1;
			for(int j = coins[i]; j <= cents; j++) {
				if(j <= limit) dp[j] += dp[j - coins[i]];
			}
		}
		cout << setw(3) << setfill(' ') << dp[cents] << endl;
	}
}
