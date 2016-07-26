// Almost Prime Numbers *AC*

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE = 1000000, AP_SIZE = 9000000;
const long long LIMIT = 1000000000010;

int BinarySearch(long long *arr, long long target, int left, int right, bool higher) {
	int limit = right;
	while(left < right) {
		int mid = (left + right) / 2;
		if(arr[mid] > target)
			right = mid - 1;
		else if(arr[mid] < target)
			left = mid + 1;
		else
			return mid;
	}
	if(arr[left] == target)
		return left;
	if(higher) {
		while(arr[left] < target && left < limit) left++;
		return left;
	}
	else {
		while(arr[right] > target && right > 0) right--;
		return right;
	}
}

int main() {
	bool *isPrime = new bool[SIZE];
	memset(isPrime, 1, sizeof(bool) * SIZE);
	isPrime[2] = true, isPrime[3] = true, isPrime[5] = true;
	for(int i = 2; i < SIZE; i++) {
		if(isPrime[i]) {
			for(int j = i + i; j < SIZE; j += i)
				isPrime[j] = false;
		}
	}

	long long *almostPrime = new long long[AP_SIZE];
	int lim = 0;
	for(long long i = 2; i < SIZE; i++) {
		if(isPrime[i]) {
			for(long long j = i * i; j < LIMIT; j *= i)
				almostPrime[lim++] = j;
		}
	}
	delete[] isPrime;

	sort(almostPrime, almostPrime + lim + 1);

	int numCases;
	cin >> numCases;
	while(numCases--) {
		long long low, high;
		cin >> low >> high;

		int lowIndex = BinarySearch(almostPrime, low, 0, lim, true),
			highIndex = BinarySearch(almostPrime, high, 0, lim, false);

		if(lowIndex == highIndex && !(low <= almostPrime[lowIndex] && high >= almostPrime[highIndex]))
			cout << 0 << endl;
		else
			cout << highIndex - lowIndex + 1 << endl;
	}

	delete[] almostPrime;
}
