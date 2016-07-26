// Bubbles and Buckets *AC*

#include <iostream>
#include <cstring>

using namespace std;

int MergeSort(int *arr, int left, int right, int swaps = 0) {
	if(right == left)
		return swaps;

	int mid = (right + left) / 2;
	swaps += MergeSort(arr, left, mid, swaps);
	swaps += MergeSort(arr, mid + 1, right);

	int *t = new int[right - left + 1], cur = 0;
	for(int i = left, j = mid + 1; i <= mid || j <= right;) {
		if(i > mid)
			t[cur++] = arr[j++];
		else if(j > right)
			t[cur++] = arr[i++];
		else if(arr[i] < arr[j])
			t[cur++] = arr[i++];
		else {
			swaps += mid - i + 1;
			t[cur++] = arr[j++];
		}
	}
	memcpy(&arr[left], t, sizeof(int) * (right - left + 1));
	delete[] t;
	return swaps;
}

int main() {
	int n;
	cin >> n;
	while(n != 0) {
		int *arr = new int[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];

		int swaps = MergeSort(arr, 0, n - 1);
		if(swaps % 2 != 0)
			cout << "Marcelo" << endl;
		else
			cout << "Carlos" << endl;

		delete[] arr;

		cin >> n;
	}
}
