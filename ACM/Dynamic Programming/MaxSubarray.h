#include <iostream>
#include <climits>
#include <ctime>
#include <cstdlib>

using namespace std;

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int MaxSubarray(int arr[], int left, int right) {
	if(left == right)
		return arr[left];

	// the subarray that spans across
	int m = (left + right) / 2;
	int maxSum = INT_MIN, curSum = 0;
	for(int i = m; i >= left; i--) {
		curSum += arr[i];
		if(curSum > maxSum)
			maxSum = curSum;
	}
	curSum = maxSum;
	for(int i = m + 1; i <= right; i++) {
		curSum += arr[i];
		if(curSum > maxSum)
			maxSum = curSum;
	}

	// the max between the left, right, and the subarray that spans across
	return MAX(maxSum, MAX(MaxSubarray(arr, left, m), MaxSubarray(arr, m + 1, right)));
}

int main() {
	// generating input
	int size = 10000;
	int *arr = new int[size];
	for(int i = 0; i < size; i++) {
		if(rand() % 2)
			arr[i] = rand() % 1000;
		else
			arr[i] = -rand() % 1000;
	}

	// brute force
	cout << "Brute Force: ";
	clock_t start = clock();
	int maxSum = INT_MIN, curSum = 0;
	for(int i = 0; i < size; i++) {
		curSum = 0;
		for(int j = i; j < size; j++) {
			curSum += arr[j];
			if(curSum > maxSum)
				maxSum = curSum;
		}
	}
	cout << maxSum << " (" << clock() - start << " ticks)" << endl;

	// divide and conquer
	cout << "Divide and Conquer: ";
	start = clock();
	maxSum = MaxSubarray(arr, 0, size - 1);
	cout << maxSum << " (" << clock() - start << " ticks)" << endl;

	// dynamic programming
	cout << "Dynamic Programming: ";
	start = clock();
	maxSum = INT_MIN, curSum = 0;
	for(int i = 0; i < size; i++) {
		curSum += arr[i];
		if(curSum < 0)
			curSum = 0;
		if(curSum > maxSum)
			maxSum = curSum;
	}
	cout << maxSum << " (" << clock() - start << " ticks)" << endl;

	delete[] arr;
}
