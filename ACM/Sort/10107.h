// What is the Median? *AC*

#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> arr, int target, int start, int end) {
	if(start == end) {
		if(arr[start] >= target)
			return start;
		return start + 1;
	}

	int size = end - start + 1;
	int m;
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
	vector<int> arr;
	int cur, curSize = 0;
	while(cin >> cur) {
		if(curSize == 0)
			arr.push_back(cur);
		else
			arr.insert(arr.begin() + BinarySearch(arr, cur, 0, curSize - 1), cur);
		curSize++;

		int m;
		if(curSize % 2 == 0)
			m = (arr[curSize / 2 - 1] + arr[curSize / 2]) / 2;
		else
			m = arr[(curSize + 1) / 2 - 1];

		cout << m << endl;
	}
}
