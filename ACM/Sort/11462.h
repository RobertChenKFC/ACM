// Age Sort *AC*

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int cmp(const void* a, const void* b) {
	if(*((int*)a) > *((int*)b))
		return 1;
	if(*((int*)a) < *((int*)b))
		return -1;
	return 0;
}

int main() {
	cout.sync_with_stdio(false);

	int numAge;
	cin >> numAge;
	while(numAge != 0) {
		int* arr = new int[numAge];

		for(int i = 0; i < numAge; i++)
			cin >> arr[i];

		qsort(arr, numAge, sizeof(int), cmp);

		cout << arr[0];
		for(int i = 1; i < numAge; i++)
			cout << " " << arr[i];
		cout << endl;

		delete[] arr;

		cin >> numAge;
	}
}
