#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// getting input
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// algorithm starts here
	vector<int> t;
	t.push_back(arr[0]);
	for(int i = 1; i < n; i++) {
		// if current element is greater than the largest element in subsequence - append
		if(arr[i] > t.back())
			t.push_back(arr[i]);
		else {
			// get the index in which the element will be inserted or replaced
			vector<int>::iterator it = lower_bound(t.begin(), t.end(), arr[i]);
			// if index contains an element that's greater than the current element - replace
			if(*it > arr[i])
				*it = arr[i];
			// if index contains an element that's equal to the current element -
			else
				*upper_bound(t.begin(), t.end(), arr[i]) = arr[i];
		}
		// test
		cout << i << ": ";
		for(int j = 0; j < t.size(); j++)
			cout << t[j] << " ";
		cout << endl;
	}

	// get length of LIS
	cout << "Length of LIS: " << t.size() << endl;
}
