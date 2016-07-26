// Shopaholic *AC*

#include <iostream>
#include <cstdlib>

using namespace std;

int cmp(const void* a, const void* b) {
	if(*((int*)a) > *((int*)b))
		return 1;
	else if(*((int*)a) < *((int*)b))
		return -1;
	else
		return 0;
}

int main() {
	int numScenarios;
	cin >> numScenarios;
	for(int curScenario = 0; curScenario < numScenarios; curScenario++) {
		int numItems;
		cin >> numItems;

		if(numItems < 3) {
			cout << 0 << endl;
			int t;
			for(int i = 0; i < numItems; i++)
				cin >> t;
		}
		else {
			int* items = new int[numItems];
			for(int i = 0; i < numItems; i++)
				cin >> items[i];
			qsort(items, numItems, sizeof(int), cmp);

			int discount = 0;
			for(int i = numItems - 3; i >= 0; i -= 3)
				discount += items[i];

			cout << discount << endl;

			delete[] items;
		}
	}
}
