// Pizza Cutting *AC*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20
int main() {
	int cuts;
	while(true) {
		// get input
		scanf("%d", &cuts);

		// end of file
		if(cuts < 0)
			break;

		// calculation (Max slices = (n+2)(n-1)/2+2)
		int a = cuts + 2, b = cuts - 1;
		if(a % 2 == 0) a /= 2; else b /= 2;
		int results[SIZE + 1] = {0};
		for(int i = SIZE; i > 0; --i) {
			results[i] += (a % 10) * b;
			while(results[i] >= 10)
				results[i - 1] += results[i] / 10, results[i] %= 10;
			a /= 10;
		}
		results[SIZE] += 2;
		for(int i = SIZE; i > 0; --i) {
			while(results[i] >= 10)
				results[i - 1] += results[i] / 10, results[i] %= 10;
		}

		// output
		bool changed = false;
		for(int i = 0; i < SIZE + 1; ++i) {
			if(results[i] != 0)
				changed = true;
			if(changed)
				printf("%d", results[i]);
		}
		printf("\n");
	}
}
