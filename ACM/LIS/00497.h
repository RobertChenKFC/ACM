#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <vector>
#include <map>

using namespace std;

int main() {
	int numCases;
	cin >> numCases;
	getchar();
	for(int caseNum = 0; caseNum < numCases; caseNum++) {
		deque<int> heights;
		map<int, int> table;
		int h;
		int curH = 0;
		while(cin >> h) {
			heights.push_back(h);
			table[curH++] = h;
		}

		int size = heights.size();
		vector<int> finals(size, 1);
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				if(finals[i] + 1 > finals[j])
					finals[j] = finals[i] + 1;
			}
		}

		int maxHits = finals.size();
		cout << "Max hits: " << maxHits;
		int curLen = -1;
		for(int i = maxHits - 1; i >= 0; i--) {
			if(finals[i] != curLen) {
				curLen = finals[i];
				cout << endl << table[finals[i]];
			}
		}
	}
}
