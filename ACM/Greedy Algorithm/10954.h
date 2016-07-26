// Add All *AC*

#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(const vector<long>& arr, long target, int start, int end) {
	if(arr.size() == 0)
		return 0;

	if(start == end) {
		if(arr[start] >= target)
			return start;
		return start + 1;
	}

	int size = end - start + 1, mid;
	if(size % 2 == 0)
		mid = start + size / 2 - 1;
	else
		mid = start + (size - 1) / 2;

	if(target > arr[mid])
		return BinarySearch(arr, target, (mid + 1 > end) ? end : (mid + 1), end);
	if(target < arr[mid])
		return BinarySearch(arr, target, start, (mid - 1 < start) ? start : (mid - 1));
	return mid;
}

int main() {
	int numNums;
	cin >> numNums;
	while(numNums != 0) {
		vector<long> arr;
		arr.reserve(numNums);

		int cur;
		cin >> cur;
		arr.push_back(cur);
		for(int i = 1; i < numNums; i++) {
			cin >> cur;
			int index = BinarySearch(arr, cur, 0, i - 1);
			arr.insert(arr.begin() + index, cur);
		}

		int sum, cost = 0;
		while(numNums-- > 1) {
			sum = arr[0] + arr[1];
			cost += sum;
			arr.erase(arr.begin());
			arr.erase(arr.begin());
			arr.insert(arr.begin() + BinarySearch(arr, sum, 0, arr.size() - 1), sum);
		}

		cout << cost << endl;

		cin >> numNums;
	}
}
