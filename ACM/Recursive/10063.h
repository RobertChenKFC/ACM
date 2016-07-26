#include <iostream>
#include <string>

using namespace std;

void GeneratePermutation(string input, string curStr, int curIndex = 0) {
	if(input.length() == curStr.length()) {
		cout << curStr << endl;
		return;
	}

	string calcStr;
	for(int i = 0; i <= curStr.length(); i++) {
		calcStr = curStr;
		calcStr.insert(i, 1, input[curIndex]);
		GeneratePermutation(input, calcStr, curIndex + 1);
	}
}

int main() {
	string input;
	bool first = true;
	while(cin >> input) {
		string buf;
		if(!first)
			cout << endl;
		GeneratePermutation(input, buf);
		first = false;
	}
}
