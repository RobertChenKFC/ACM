// The Twin Towers *AC*

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int a, b;
	int num = 1;
	while(cin >> a >> b, a != 0 || b != 0) {
		int *towerA = new int[a], *towerB = new int[b];
		for(int i = 0; i < a; i++)
			cin >> towerA[i];
		for(int i = 0; i < b; i++)
			cin >> towerB[i];

		int **lcs = new int *[a + 1];
		for(int i = 0; i <= a; i++) {
			lcs[i] = new int [b + 1];
			memset(lcs[i], 0, sizeof(int) * (b + 1));
		}

		for(int i = 1; i <= a; i++) {
			for(int j = 1; j <= b; j++) {
				if(towerA[i - 1] == towerB[j - 1])
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else {
					int left = lcs[i][j - 1], top = lcs[i - 1][j];
					if(left > top)
						lcs[i][j] = left;
					else
						lcs[i][j] = top;
				}
			}
		}

		cout << "Twin Towers #" << num++ << endl
			 << "Number of Tiles : " << lcs[a][b] << endl << endl;

		delete[] towerA;
		delete[] towerB;
	}
}
