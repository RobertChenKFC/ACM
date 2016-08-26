// Let Me Count The Ways *AC*

#include <iostream>

using namespace std;

const int MAX = 30005;
const int NUM_COINS = 5;

typedef long long int64;

int main() {
	int64 dp[MAX] = { 0 };
	dp[0] = 1;
	int cents[] = { 1, 5, 10, 25, 50 };
	for(int i = 0; i < NUM_COINS; i++) {
		for(int j = cents[i]; j < MAX; j++)
			dp[j] += dp[j - cents[i]];
	}

	int money;
	while(cin >> money) {
		if(dp[money] == 1) cout << "There is only 1 way to produce " << money << " cents change." << endl;
		else cout << "There are " << dp[money] << " ways to produce " << money << " cents change." << endl;
	}
}
