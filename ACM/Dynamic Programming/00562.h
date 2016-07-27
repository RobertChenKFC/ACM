// Dividing Coins *AC*

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int numCases;
	cin >> numCases;
	while(numCases--) {
		int numCoins;
		cin >> numCoins;
		int *coins = new int[numCoins], val = 0;
		for(int i = 0; i < numCoins; i++)
			cin >> coins[i], val += coins[i];

		int halfVal = val / 2;
		int *pack = new int[halfVal + 1];
		memset(pack, 0, sizeof(int) * (halfVal + 1));
		for(int i = 0; i < numCoins; i++) {
			for(int j = halfVal; j >= coins[i]; j--) {
				if(pack[j - coins[i]] + coins[i] > pack[j])
					pack[j] = pack[j - coins[i]] + coins[i];
			}
		}

		int otherHalf = val - pack[halfVal];
		cout << otherHalf - pack[halfVal] << endl;

		delete[] pack;

		delete[] coins;
	}
}
