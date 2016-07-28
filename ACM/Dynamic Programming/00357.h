#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int MAX = 30005, NUM_CENTS = 5;

int main() {
	int arr[MAX];
	int cents[] = { 1, 5, 10, 25, 50 };

	int n;
	while(cin >> n) {

		memset(arr, MAX, sizeof(arr));
		arr[0] = 0;
		int m = 0;

		for(int i = 0; i < NUM_CENTS; i++) {
			for(int j = cents[i]; j <= n; j++) {
				if(arr[j - cents[i]] + 1 < arr[j]) {
					arr[j] = arr[j - cents[i]] + 1;
					if(j == n)
						m++;
				}
			}
		}

		cout << arr[n] << endl;
	}
}
