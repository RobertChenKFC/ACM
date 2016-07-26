// Train Swapping *AC*

#include <stdio.h>

int main() {
	int numOfTests;
	scanf("%d", &numOfTests);
	for(int a = 0; a < numOfTests; ++a) {
		int numOfCarrages;
		scanf("%d", &numOfCarrages);
		int* trains = new int [numOfCarrages];

		for(int i = 0; i < numOfCarrages; ++i)
			scanf("%d", &trains[i]);

		int swaps = 0;
		for(int i = 0; i < numOfCarrages - 1; ++i) {
			for(int j = 0; j + i < numOfCarrages - 1; ++j) {
				if(trains[j] > trains[j + 1]) {
					int t = trains[j];
					trains[j] = trains[j + 1], trains[j + 1] = t;
					swaps++;
				}
			}
		}

		printf("Optimal train swapping takes %d swaps.\n", swaps);

		delete [] trains;
	}
}
