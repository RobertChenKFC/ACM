#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

enum { EMPTY, TOP, LEFT, TOP_LEFT };

int main() {
	// get input
	string a, b;
	cin >> a >> b;

	// setup table for calculation and recording subsequence
	int lenA = a.length(), lenB = b.length();
	int **lcs = new int *[lenA + 1], **map = new int *[lenA + 1];
	for(int i = 0; i < lenA + 1; i++) {
		lcs[i] = new int[lenB + 1], map[i] = new int [lenB + 1];
		memset(lcs[i], 0, sizeof(int) * (lenB + 1));
		memset(map[i], 0, sizeof(int) * (lenB + 1));
	}

	// calculating subsequence
	for(int i = 1; i <= lenA; i++) {
		for(int j = 1; j <= lenB; j++) {
			// if the elements of the array are the same
			if(a[i - 1] == b[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1, map[i][j] = TOP_LEFT;
			else {
				// get the maximum of not taking current element
				int top = lcs[i - 1][j], left = lcs[i][j - 1];
				if(top > left)
					lcs[i][j] = top, map[i][j] = TOP;
				else
					lcs[i][j] = left, map[i][j] = LEFT;
			}
		}
	}

	// get length of LCS
	int lcsLen = lcs[lenA][lenB];
	cout << "LCS length: " << lcsLen << endl;


	// get content of LCS
	int i = lenA, j = lenB, curLen = 0;
	string lcsContent;
	while(curLen <= lcsLen && map[i][j] != EMPTY) {
		switch(map[i][j]) {
		case TOP:
			i--;
			break;
		case LEFT:
			j--;
			break;
		case TOP_LEFT:
			lcsContent.insert(lcsContent.begin(), a[i - 1]);
			i--, j--;
			curLen++;
			break;
		}
	}
	cout << "LCS: " << lcsContent << endl;

	for(int i = 0; i < lenA; i++)
		delete[] lcs[i];
	delete[] lcs;
}
