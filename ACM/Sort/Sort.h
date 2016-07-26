// Sort

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE = 10000;

void arrCpy(long a[], long b[]) {
	memcpy(b, a, sizeof(long) * SIZE);
}

bool sortCheck(long arr[]) {
	for(int i = 0; i < SIZE - 1; i++) {
		if(arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void bubbleSort(long arr[]) {
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j + i < SIZE - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				long t = arr[j];
				arr[j] = arr[j + 1], arr[j + 1] = t;
			}
		}
	}
}

void selectionSort(long arr[]) {
	long minIndex;
	for(int i = 0; i < SIZE; i++) {
		minIndex = i;
		for(int j = i + 1; j < SIZE; j++) {
			if(arr[minIndex] > arr[j])
				minIndex = j;
		}

		long t = arr[i];
		arr[i] = arr[minIndex], arr[minIndex] = t;
	}
}

void mergeSort(long arr[], int start = 0, int end = SIZE - 1) {
	int curSize = end - start + 1;

	// if there is only 1 or 2 items left in the array
	if(curSize == 1)
		return;
	else if(curSize == 2) {
		if(arr[start] > arr[end]) {
			long t = arr[start];
			arr[start] = arr[end], arr[end] = t;
		}
		return;
	}

	// recursive call
	int mid;
	if(curSize % 2 == 0)
		mid = start + curSize / 2 - 1;
	else
		mid = start + (curSize - 1) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	// merge
	long* tArr = new long[curSize];
	int curElem = 0;
	for(int i = start, j = mid + 1; curElem < curSize;) {
		if(i > mid)
			tArr[curElem++] = arr[j++];
		else if(j > end)
			tArr[curElem++] = arr[i++];
		else if(arr[i] < arr[j])
			tArr[curElem++] = arr[i++];
		else
			tArr[curElem++] = arr[j++];
	}
	memcpy(&arr[start], tArr, sizeof(long) * curSize);
	delete[] tArr;
}

void quickSort(long arr[], int m = 0, int n = SIZE - 1) {
	// recursive ends when array size is less than 0
	if(n <= m)
		return;

	int i = m, j = n + 1;
	long t;
	// arr[m] is the pivot
	do {
		do {
			i++;
		} while(arr[i] < arr[m] && i <= n);
		do {
			j--;
		} while(arr[j] > arr[m] && j >= 0);

		if(i < j) {
			t = arr[i];
			arr[i] = arr[j], arr[j] = t;
		}
	} while(i < j);

	t = arr[j];
	arr[j] = arr[m], arr[m] = t;

	// recursive call for right of pivot and left of pivot
	quickSort(arr, m, j - 1);
	quickSort(arr, j + 1, n);
}

// for qsort
int compare(const void * a, const void * b) {
	if (*(long*)a < *(long*)b)
		return -1;
	if (*(long*)a > *(long*)b)
		return 1;
	return 0;
}

int main() {
	long number[SIZE], calc[SIZE];

	srand(time(NULL));
	for(int i = 0; i < SIZE; ++i)
		number[i] = rand() * rand();

	// bubble sort
	cout << "Bubble sort: ";
	arrCpy(number, calc);
	clock_t start = clock();
	bubbleSort(calc);
	cout << clock() - start << " ticks" << endl;
	if(sortCheck(calc))
		cout << "Bubble sort OK" << endl;
	else
		cout << "Bubble sort incorrect" << endl;

	// selection sort
	cout << "Selection sort: ";
	arrCpy(number, calc);
	start = clock();
	selectionSort(calc);
	cout << clock() - start << " ticks" << endl;
	if(sortCheck(calc))
		cout << "Selection sort OK" << endl;
	else
		cout << "Selection sort incorrect" << endl;

	// merge sort
	cout << "Merge sort: ";
	arrCpy(number, calc);
	start = clock();
	mergeSort(calc);
	cout << clock() - start << " ticks" << endl;
	if(sortCheck(calc))
		cout << "Merge sort OK" << endl;
	else
		cout << "Merge sort incorrect" << endl;

	// quick sort
	cout << "Quick sort: ";
	arrCpy(number, calc);
	start = clock();
	quickSort(calc);
	cout << clock() - start << " ticks" << endl;
	if(sortCheck(calc))
		cout << "Quick sort OK" << endl;
	else
		cout << "Quick sort incorrect" << endl;

	// qsort
	cout << "qSort: ";
	arrCpy(number, calc);
	start = clock();
	qsort(calc, SIZE, sizeof(long), compare);
	cout << clock() - start << " ticks" << endl;
	if(sortCheck(calc))
		cout << "qSort sort OK" << endl;
	else
		cout << "qSort sort incorrect" << endl;

	// STL sort
	cout << "STL sort: ";
	arrCpy(number, calc);
	start = clock();
	sort(calc, calc + SIZE);
	cout << clock() - start << " ticks" << endl;
	if(sortCheck(calc))
		cout << "STL sort OK" << endl;
	else
		cout << "STL sort incorrect" << endl;
}
