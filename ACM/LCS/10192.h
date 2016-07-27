// Vacation *AC*

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_CITIES = 105;

int main() {
	char a[MAX_CITIES], b[MAX_CITIES];
	int lcs[MAX_CITIES][MAX_CITIES];
	int num = 1;
	while(gets(a), a[0] != '#') {
		gets(b);
		int aSize = strlen(a), bSize = strlen(b);

		for(int i = 0; i <= aSize; i++)
			memset(lcs[i], 0, sizeof(lcs[i]));

		for(int i = 1; i <= aSize; i++) {
			for(int j = 1; j <= bSize; j++) {
				if(a[i - 1] == b[j - 1])
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

		cout << "Case #" << num++ << ": you can visit at most " << lcs[aSize][bSize] << " cities." << endl;
	}
}
