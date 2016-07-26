// 487--3279 *AC*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSortBase(int arr[], int m, int n) {
	if(m >= n)
		return;

	int i = m, j = n + 1, t;
	do {
		do {
			i++;
		} while(arr[i] < arr[m] && i <= n);
		do {
			j--;
		} while(arr[j] > arr[m] && j >= 0);

		if(i < j) {
			t = arr[j];
			arr[j] = arr[i], arr[i] = t;
		}
	} while(i < j);

	t = arr[j];
	arr[j] = arr[m], arr[m] = t;

	quickSortBase(arr, m, j - 1);
	quickSortBase(arr, j + 1, n);
}

void quickSort(int arr[], int size) {
	quickSortBase(arr, 0, size - 1);
}

const int SIZE = 200;
int main() {
	int numOfDatasets;
	scanf("%d", &numOfDatasets);

	for(int a = 0; a < numOfDatasets; ++a) {
		int numOfNumbers;
		scanf("%d", &numOfNumbers);

		char input[SIZE];
		int* numbers = new int [numOfNumbers];
		for(int i = 0; i < numOfNumbers; ++i) {
			// initialize
			numbers[i] = 0;

			// get input
			scanf("%s", input);

			// change to number
			int size = strlen(input);
			for(int j = 0; j < size; ++j) {
				if(input[j] >= '0' && input[j] <= '9')
					numbers[i] *= 10, numbers[i] += (input[j] - '0');
				else if(input[j] >= 'A' && input[j] <= 'Z') {
					int curNum;
					switch(input[j]) {
					case 'A':
					case 'B':
					case 'C':
						curNum = 2;
						break;
					case 'D':
					case 'E':
					case 'F':
						curNum = 3;
						break;
					case 'G':
					case 'H':
					case 'I':
						curNum = 4;
						break;
					case 'J':
					case 'K':
					case 'L':
						curNum = 5;
						break;
					case 'M':
					case 'N':
					case 'O':
						curNum = 6;
						break;
					case 'P':
					case 'R':
					case 'S':
						curNum = 7;
						break;
					case 'T':
					case 'U':
					case 'V':
						curNum = 8;
						break;
					case 'W':
					case 'X':
					case 'Y':
						curNum = 9;
						break;
					}
					numbers[i] *= 10, numbers[i] += curNum;
				}
			}
		}

		// sort
		quickSort(numbers, numOfNumbers);

		bool printed = false;
		int curNumber, length = 1;
		for(int i = 0; i < numOfNumbers; ++i) {
			// print output
			if(i == 0)
				curNumber = numbers[i];
			else {
				if(numbers[i] != curNumber) {
					if(length > 1) {
						printed = true;
						printf("%003d-%004d %d\n", curNumber / 10000, curNumber % 10000, length);
					}
					curNumber = numbers[i], length = 1;
				}
				else
					length++;
			}
		}

		// last number check
		if(length > 1) {
			printed = true;
			printf("%003d-%004d %d\n", curNumber / 10000, curNumber % 10000, length);
		}

		// no duplicates check
		if(!printed)
			printf("No duplicates.\n");

		delete [] numbers;
		if(a != numOfDatasets - 1)
			printf("\n");
	}
}
