// Erratic Expansion *AC*

#include <iostream>
#include <cstring>

using namespace std;

long long Pow(const long long& b, const long long& p) {
	if(p == 0) return 1;
	if(p == 1) return b;

	if(p % 2 == 0) {
		long long t = Pow(b, p >> 1);
		return t * t;
	}
	return b * Pow(b, p - 1);
}

long long Expand(int hour, int row, int mid) {
	if(hour == 0) {
		if(row == 1) return 1;
		return 0;
	}

	if(row <= mid)
		return Expand(hour - 1, row, mid >> 1) << 1;
	return Expand(hour - 1, row - mid, mid >> 1) + (Pow(3, hour - 1) << 1);
}

int main() {
	int numCases;
	cin >> numCases;
	for(int caseNum = 1; caseNum <= numCases; caseNum++) {
		int k, a, b;
		cin >> k >> a >> b;

		if(k == 0)
			cout << "Case " << caseNum << ": 1" << endl;
		else {
			long long bCount = Expand(k, b, 1 << (k - 1)), aCount = Expand(k, a - 1, 1 << (k - 1));

			cout << "Case " << caseNum << ": " << bCount - aCount << endl;
		}
	}
}
