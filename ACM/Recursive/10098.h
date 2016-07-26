// Generating Fast *AC*

#include <iostream>
#include <string>
#include <cstring>
#include <deque>

using namespace std;

struct Section {
	char s;
	bool used;
};

void GenPerm(deque<Section> strings, const int& size, string curPerm = "", int curSize = 0) {
	if(curSize == size) {
		cout << curPerm << endl;
		return;
	}

	for(int i = 0; i < size; i++) {
		if(!strings[i].used) {
			if(!(i != 0 && strings[i].s == strings[i - 1].s && !strings[i - 1].used)) {
				strings[i].used = true;
				string permCpy = curPerm + strings[i].s;
				GenPerm(strings, size, permCpy, curSize + 1);
				strings[i].used = false;
			}
		}
	}
}

int main() {
	int numCases;
	cin >> numCases;
	while(numCases--) {
		string s;
		cin >> s;
		int size = s.length();

		// sort
		for(int i = 0; i < size; i++) {
			for(int j = 0; j + i + 1 < size; j++) {
				if(s[j] > s[j + 1]) {
					char t = s[j];
					s[j] = s[j + 1], s[j + 1] = t;
				}
			}
		}

		// gather into groups
		deque<Section> strings;
		for(int i = 0; i < size; i++) {
			Section cur;
			cur.s = s[i], cur.used = false;
			strings.push_back(cur);
		}

		GenPerm(strings, strings.size());
		cout << endl;
	}
}
