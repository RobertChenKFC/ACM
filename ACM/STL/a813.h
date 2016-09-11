#include <iostream>
#include <climits>

using namespace std;

typedef long long BigInt;
const BigInt MAX = 1000005;

#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

int main() {
	BigInt heights[MAX];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> heights[i];

	BigInt c = 0;
	for(int i = 0; i < n; i++) {
		BigInt minh, maxh = INT_MIN;
		for(int j = i - 1; j >= 0; j--) {
			minh = min(heights[i], heights[j]);
			if(minh >= maxh) c++;
			maxh = max(maxh, heights[j]);
		}
		maxh = INT_MIN;
		for(int j = i + 1; j < n; j++) {
			minh = min(heights[i], heights[j]);
			if(minh >= maxh) c++;
			maxh = max(maxh, heights[j]);
		}
	}
	cout << c << endl;
}
