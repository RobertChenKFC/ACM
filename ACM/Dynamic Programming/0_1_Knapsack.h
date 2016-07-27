#include <iostream>
#include <cstring>

using namespace std;

struct Pack {
	int value;
	int weight;
};

int main() {
	int n;
	cin >> n;
	Pack *packs = new Pack[n];
	for(int i = 0; i < n; i++)
		cin >> packs[i].weight >> packs[i].value;
	int lim;
	cin >> lim;

	// setup array for calculation
	int *arr = new int[lim + 1];
	bool **map = new bool*[lim];
	for(int i = 0; i < lim; i++) {
		map[i] = new bool[lim + 1];
		memset(map[i], false, sizeof(bool) * (lim + 1));
	}

	// calculate max value for knapsack and record knapsacks
	memset(arr, 0, sizeof(int) * (lim + 1));
	for(int i = 0; i < n; i++) {
		for(int j = lim; j >= packs[i].weight; j--) {
			if(arr[j - packs[i].weight] + packs[i].value > arr[j]) {
				arr[j] = arr[j - packs[i].weight] + packs[i].value;
				map[i][j] = true;
			}
		}
	}

	// get maximum value of knapsack
	cout << "Maximum value: " << arr[lim] << endl;

	// get contents of knapsack
	for(int i = lim - 1, j = lim; i >= 0; i--) {
		if(map[i][j]) {
			cout << "Used knapsack " << i + 1
				 << " (weight: " << packs[i].weight << ", value: " << packs[i].value << ")" << endl;
			j -= packs[i].weight;
		}
	}

	delete[] arr;
	for(int i = 0; i < lim; i++)
		delete[] map[i];
	delete[] map;

	delete[] packs;
}
