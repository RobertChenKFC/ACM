// Product *AC*

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 505;

typedef unsigned long long int64;

int main() {
	string a, b;
	int aSize, bSize;
	int64 res[MAX];
	while(getline(cin, a) && getline(cin, b)) {
		memset(res, 0, sizeof(res));

		aSize = a.length(), bSize = b.length();
		for(int i = aSize - 1; i >= 0; i--) {
			for(int j = bSize - 1, k = MAX - (aSize - i); j >= 0; j--, k--)
				res[k] += int64(a[i] - '0') * int64(b[j] - '0');
		}

		int64 remains;
		for(int i = MAX - 1; i > 0; i--) {
			if(res[i] >= 10) {
				remains = res[i] % 10;
				res[i - 1] += (res[i] - remains) / 10, res[i] = remains;
			}
		}

		bool changed = false;
		for(int i = 0; i < MAX; i++) {
			if(res[i] != 0) changed = true;
			if(changed) cout << res[i];
		}
		if(!changed) cout << 0;
		cout << endl;
	}
}
