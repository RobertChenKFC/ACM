#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool Recursive(stack<char> &s) {
	if(s.size() == 0) return 0;
	char top = s.top();
	s.pop();

	if(top == '1') {
		if(!Recursive(s)) return false;
		else return Recursive(s);
	}
	else return true;
}

bool RecursiveMethod(const string &s) {
	stack<char> stk;
	for(int i = s.length() - 1; i >= 0; i--) stk.push(s[i]);
	return Recursive(stk) && (stk.size() == 0);
}

int main() {
	// description and input
	cout << "An H-sequence is correct if: " << endl
		 << "(1) Sequence is 0" << endl
		 << "(2) Sequence is 1 followed by 2 H-Sequences" << endl
		 << "Please enter your sequence: ";
	string s;
	cin >> s;

	// recursive method
	cout << "Recursive method: ";
	if(RecursiveMethod(s)) cout << "Sequence correct" << endl;
	else cout << "Sequence incorrect" << endl;

	// non recursive method
	cout << "Non recursive method: ";
	int stat = 1, i;
	for(i = 0; i < s.length(); i++) {
		if(s[i] == '0') stat--;
		else stat += 1;

		if(stat <= 0) break;
	}
	if(stat == 0 && i == s.length() - 1) cout << "Sequence correct" << endl;
	else cout << "Sequence incorrect" << endl;
}
