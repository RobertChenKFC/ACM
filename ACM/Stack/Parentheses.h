#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define IS_LEFT(X) (((X) == '{') || ((X) == '[') || ((X) == '('))

int main() {
	string s;
	cin >> s;

	stack<char> lefts;
	bool isValid = true;
	for(int i = 0; i < s.length(); i++) {
		if(IS_LEFT(s[i])) lefts.push(s[i]);
		else {
			if((lefts.size() != 0) &&
			   (((s[i] == '}') && (lefts.top() == '{')) ||
				((s[i] == ']') && (lefts.top() == '[')) ||
				((s[i] == ')') && (lefts.top() == '('))))
				lefts.pop();
			else {
				isValid = false;
				break;
			}
		}
	}
	if(isValid && lefts.size() == 0)
		cout << "Parentheses are in pairs" << endl;
	else
		cout << "Parentheses are not in pairs" << endl;
}
