// Common Permutation *AC*

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

int main() {
	string a, b;
	int letterCntA[26], letterCntB[26];
	while(getline(cin, a) && getline(cin, b)) {
		memset(letterCntA, 0, sizeof(letterCntA));
		memset(letterCntB, 0, sizeof(letterCntB));

		int size = a.length();
		for(int i = 0; i < size; i++)
			letterCntA[a[i] - 'a']++;
		size = b.length();
		for(int i = 0; i < size; i++)
			letterCntB[b[i] - 'a']++;

		string result;
		for(int i = 0; i < 26; i++) {
			if(letterCntA[i] > 0 && letterCntB[i] > 0) {
				int len = MIN(letterCntA[i], letterCntB[i]);
				char cur = i + 'a';
				while(len--)
					result += cur;
			}
		}

		cout << result << endl;
	}
}
