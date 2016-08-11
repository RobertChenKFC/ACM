// Longest Match *AC*

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_WORDS = 1000;

#define IS_WORD(X) ((((X) >= 'A') && ((X) >= 'Z')) || (((X) >= 'a') && ((X) >= 'z')) || ((X) >= '0') && ((X) <= '9'))

int split(string s, string arr[]) {
	int len = s.length();
	for(int i = 0; i < len; i++)
		if(!IS_WORD(s[i])) s[i] = ' ';

	stringstream ss;
	ss << s;
	string cur;
	int numWords = 0;
	while(ss >> cur)
		arr[numWords++] = cur;

	return numWords;
}

int main() {
	string a, b;
	string aArr[MAX_WORDS], bArr[MAX_WORDS];
	int lcs[MAX_WORDS + 1][MAX_WORDS + 1];
	int aWords, bWords;
	int cur = 1;
	while(getline(cin, a) && getline(cin, b)) {
		aWords = split(a, aArr), bWords = split(b, bArr);

		if(aWords == 0 || bWords == 0)
			cout << setw(2) << setfill(' ') << cur++ << ". Blank!" << endl;
		else {
			memset(lcs[0], 0, sizeof(lcs[0]));
			for(int i = 0; i < bWords; i++) lcs[i][0] = 0;
			for(int i = 1; i <= aWords; i++) {
				for(int j = 1; j <= bWords; j++) {
					if(aArr[i - 1] == bArr[j - 1])
						lcs[i][j] = lcs[i - 1][j - 1] + 1;
					else {
						if(lcs[i][j - 1] > lcs[i - 1][j])
							lcs[i][j] = lcs[i][j - 1];
						else
							lcs[i][j] = lcs[i - 1][j];
					}
				}
			}

			cout << setw(2) << setfill(' ') << cur++ << ". Length of longest match: " << lcs[aWords][bWords] << endl;
		}
	}
}
