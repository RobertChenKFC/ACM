#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int *arr = new int[n + 5];
	bool bestCase = true, worstCase = true;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if(arr[i] >= 60) worstCase = false;
		else bestCase = false;
	}

	sort(arr, arr + n);
	for(int i = 0; i < n; i++) {
		if(i != 0) cout << ' ';
		cout << arr[i];
	}
	cout << endl;


	if(bestCase) cout << "best case" << endl;
	else cout << *(lower_bound(arr, arr + n, 60) - 1) << endl;

	if(worstCase) cout << "worst case" << endl;
	else cout << *upper_bound(arr, arr + n, 60) << endl;

	delete[] arr;
}
