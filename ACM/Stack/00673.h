// Parentheses Balance *AC*

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	string s;
	while(n--) {
		getline(cin, s);
		stack<char> lefts;
		bool valid = true;
		for(int i = 0; i < s.length(); i++) {
			char cur = s[i];
			if((cur == '(') || (cur == '[')) lefts.push(cur);
			else if((lefts.size() != 0) &&
					(((cur == ')') && (lefts.top() == '(')) ||
					 ((cur == ']') && (lefts.top() == '['))))
				lefts.pop();
			else {
				valid = false;
				break;
			}
		}
		if((lefts.size() == 0) && valid)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
