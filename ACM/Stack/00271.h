// Simply Syntax *AC*

#include <iostream>
#include <string>

using namespace std;

#define NEEDS_TWO(X) (((X) == 'C') || ((X) == 'D') || ((X) == 'E') || ((X) == 'I'))
#define NEEDS_ONE(X) ((X) == 'N')
#define IS_SENTENCE(X) (((X) >= 'p') && ((X) <= 'z'))

int main() {
	string s;
	while(cin >> s) {
		int stat = 1, i;
		for(i = 0; i < s.length(); i++) {
			char cur = s[i];
			if(NEEDS_TWO(cur)) stat++;
			else if(IS_SENTENCE(cur)) stat--;

			if(stat <= 0) break;
		}
		if((stat == 0) && (i == s.length() - 1) && IS_SENTENCE(s[s.length() - 1]))
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
