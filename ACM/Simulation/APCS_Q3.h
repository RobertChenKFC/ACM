#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

const int MAX = 10000005;

int main() {
	int *arr = new int[MAX];
	memset(arr, 0, sizeof(int) * MAX);

	int n;
	cin >> n;

	int a, b, max = INT_MIN;
	while(n--) {
		cin >> a >> b;
		arr[a]++, arr[b + 1]--;

		if(b > max) max = b;
	}

	int cnt = 0;
	for(int i = 1; i <= max; i++) {
		arr[i] += arr[i - 1];
		if(arr[i - 1] > 0 && arr[i] > 0) cnt++;
	}

	cout << cnt << endl;

	delete[] arr;
}
