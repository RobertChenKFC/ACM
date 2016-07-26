// Super Long Sums *AC*

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 1000001;

int main() {
	int bigNum[SIZE];

	int numCases;
	cin >> numCases;
	
	for(int caseNum = 0; caseNum < numCases; caseNum++) {
		int nums;
		cin >> nums;

		memset(bigNum, 0, sizeof(bigNum));

		for(int i = 1; i <= nums; i++) {
			int a, b;
			cin >> a >> b;
			bigNum[i] += a + b;
		}

		for(int i = nums; i >= 1; i--) {
			if(bigNum[i] >= 10)
				bigNum[i - 1]++, bigNum[i] -= 10;
		}

		if(caseNum != 0)
			cout << endl;
		bool changed = false;
		for(int i = 0; i <= nums; i++) {
			if(bigNum[i] != 0)
				changed = true;

			if(changed)
				cout << bigNum[i];
		}
		cout << endl;
	}
}
