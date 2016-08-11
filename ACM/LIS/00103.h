#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

const int MAX_DIM = 10, MAX_BOXES = 30;

struct Box {
	int d;
	int s[MAX_DIM];
	int i;

	void dSort() { sort(s, s + d); }
	void operator=(const Box &rhs) {
		d = rhs.d, i = rhs.i;
		memcpy(s, rhs.s, sizeof(s));
	}
	bool operator<(const Box &rhs) const {
		bool less = true;
		for(int i = 0; i < d; i++) {
			if(s[i] > rhs.s[i]) {
				less = false;
				break;
			}
		}
		return less;
	}
	bool operator>(const Box &rhs) const {
		bool greater = true;
		for(int i = 0; i < d; i++) {
			if(s[i] < rhs.s[i]) {
				greater = false;
				break;
			}
		}
		return greater;
	}
	bool operator>=(const Box &rhs) const { return !(*this < rhs); }
	bool operator<=(const Box &rhs) const { return !(*this > rhs); }
};

int main() {
	int n, d;
	Box boxes[MAX_BOXES];
	int pos[MAX_BOXES];

	while(cin >> n >> d) {
		for(int i = 0; i < n; i++) {
			boxes[i].d = d, boxes[i].i = i;
			for(int j = 0; j < d; j++)
				cin >> boxes[i].s[j];
			boxes[i].dSort();
		}

		sort(boxes, boxes + n);

		vector<Box> lis;
		lis.push_back(boxes[0]), pos[0] = 0;
		for(int i = 1; i < n; i++) {
			Box cur = boxes[i];
			if(cur > lis.back()) pos[i] = lis.size(), lis.push_back(cur);
			else {
				vector<Box>::iterator it = lower_bound(lis.begin(), lis.end(), cur);
				*it = cur, pos[i] = it - lis.begin();
			}
		}

		cout << lis.size() << endl;
		int cur = lis.size() - 1;
		stringstream ss;
		for(int i = cur; i >= 0; i--) {
			if(pos[i] == cur) {
				ss << boxes[pos[i]].i + 1 << " ";
				cur--;
			}
		}
		string s;
		ss >> s, cout << s;
		while(cout << " ", ss >> s, cout << s);
		cout << endl;
	}
}
