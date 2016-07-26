#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 1000000, NOT_FOUND = -1, MAX = 10;

int linearSearch(long arr[], long target, int size) {
	for(int i = 0; i < size; i++) {
		if(arr[i] == target)
			return i;
	}
	return NOT_FOUND;
}

int binarySearch(long arr[], long target, int start, int end) {
	while(start < end) {
		int mid = (start + end) / 2;
		if(arr[mid] > target)
			end = mid - 1;
		else if(arr[mid] < target)
			start = mid + 1;
		else
			return mid;
	}
	if(arr[start] != target)
		return NOT_FOUND;
	return start;
}

int cmp(const void* a, const void* b) {
	if(*((long*)a) > *((long*)b))
		return 1;
	else if(*((long*)a) < *((long*)b))
		return -1;
	else
		return 0;
}

int main() {
	// generate array
	long arr[SIZE];
	srand(time(NULL));
	for(int i = 0; i < SIZE; i++)
		arr[i] = rand();
	qsort(arr, SIZE, sizeof(long), cmp);

	// test
	int target = arr[rand() % SIZE], res;
	cout << "target: " << target << endl;

	// Linear search
	cout << "Linear search: " << endl;
	clock_t start = clock();
	// add calulations
	for(int i = 0; i < 10; i++)
		res = linearSearch(arr, target, SIZE);
	cout << clock() - start << " ticks, ";
	if(res == NOT_FOUND)
		cout << "not found" << endl;
	else
		cout << "found in arr[" << res << "]" << endl;

	// Binary Search
	cout << "Binary search: " << endl;
	start = clock();
	// add calulations
	for(int i = 0; i < 10; i++)
		res = binarySearch(arr, target, 0, SIZE - 1);
	cout << clock() - start << " ticks, ";
	if(res == NOT_FOUND)
		cout << "not found" << endl;
	else
		cout << "found in arr[" << res << "]" << endl;
}
