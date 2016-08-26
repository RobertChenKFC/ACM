// 4 Values whose Sum is 0 *AC*

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 4005;

int main() {
	int a[MAX], b[MAX], c[MAX], d[MAX];
	int *ab = new int[MAX * MAX];
	int n;

	int numCases;
	cin >> numCases;
	bool first = true;
	while(numCases--) {
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

		int cur = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				ab[cur++] = a[i] + b[j];
		}

		int *abEnd = ab + cur;
		sort(ab, abEnd);

		int cnt = 0;
		int target, found;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				target = -c[i] - d[j];
				found = lower_bound(ab, abEnd, target) - ab;
				while(found < cur && ab[found] == target) cnt++, found++;
			}
		}

		if(first) first = false;
		else cout << endl;
		cout << cnt << endl;
	}

	delete[] ab;
}
