// Lotto *AC*

#include <iostream>
#include <cstring>

using namespace std;

string toString(int n) {
	string result;
	while(n != 0) {
		result.insert(0, 1, n % 10 + '0');
		n /= 10;
	}
	return result;
}

void Lotto(int allNums[], int numOfNums, string curSelection, int prevNumIndex = -1, int numPrinted = 0, bool first = true) {
	if(numPrinted == 6) {
		cout << curSelection << endl;
		return;
	}

	string calcSelection;
	if(prevNumIndex + 1 < numOfNums) {
		for(int i = prevNumIndex + 1; i < numOfNums; i++) {
			calcSelection = curSelection;
			if(!first)
				calcSelection += " ";
			calcSelection += toString(allNums[i]);
			prevNumIndex = i;
			Lotto(allNums, numOfNums, calcSelection, prevNumIndex, numPrinted + 1, false);
		}
	}
	else
		return;
}

int main() {
	int numOfNums;
	bool first = true;
	while(cin >> numOfNums) {
		if(numOfNums == 0)
			return 0;

		int* allNums = new int[numOfNums];
		for(int i = 0; i < numOfNums; i++)
			cin >> allNums[i];

		if(!first)
			cout << endl;
		first = false;

		string str;
		Lotto(allNums, numOfNums, str);

		delete allNums;
	}
}
