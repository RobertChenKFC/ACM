// Kindergarten Counting Game *AC*

#include <iostream>
#include <string>

using namespace std;

#define IS_LETTER(X) ((X >= 'A' && X <= 'Z') || (X >= 'a' && X <= 'z'))

int main() {
	string s;
	while(getline(cin, s)) {
		int size = s.length();
		if(size == 1)
			cout << 1 << endl;
		else {
			int wordCount = 0;
			for(int i = 1; i < size; i++) {
				if(IS_LETTER(s[i - 1]) && !IS_LETTER(s[i]))
					wordCount++;
			}
			cout << wordCount << endl;
		}
	}
}
