// Where is the Marble *AC*

#include <iostream>
#include <cstdlib>

using namespace std;

int cmp(const void* a, const void* b) {
	if(*((int*)a) > *((int*)b))
		return 1;
	if(*((int*)a) < *((int*)b))
		return -1;
	return 0;
}

const int NOT_FOUND = -1;

int BinarySearch(int arr[], int target, int start, int end) {
	if(start == end) {
		if(arr[start] == target)
			return start;
		return NOT_FOUND;
	}

	int size = end - start + 1, m;
	if(size % 2 == 0)
		m = start + size / 2 - 1;
	else
		m = start + (size - 1) / 2;

	if(target < arr[m])
		return BinarySearch(arr, target, start, (m - 1 < 0) ? 0 : (m - 1));
	if(target > arr[m])
		return BinarySearch(arr, target, (m + 1 > end) ? end : (m + 1), end);
	return m;
}

int main() {
	int n, q;
	for(int caseNum = 1; true; caseNum++) {
		cin >> n >> q;
		if(n == 0)
			return 0;

		int* marbles = new int[n];
		for(int i = 0; i < n; i++)
			cin >> marbles[i];

		qsort(marbles, n, sizeof(int), cmp);

		cout << "CASE# " << caseNum << ":" << endl;
		while(q--) {
			int target;
			cin >> target;
			int res = BinarySearch(marbles, target, 0, n - 1);

			cout << target;
			if(res == NOT_FOUND)
				cout << " not found" << endl;
			else {
				while(marbles[res] == target) res--;
				res += 2;

				cout << " found at " << res << endl;
			}
		}

		delete[] marbles;
	}
}
