
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_D = 15, MAX_BOX = 35;

struct Box {
	int id;
	int s[MAX_D];
	int d;

	void dSort() { sort(s, s + d); }
	bool operator<(const Box &rhs) const {
		for(int i = 0; i < d; i++)
			if(s[i] >= rhs.s[i]) return false;
		return true;
	}
};

bool cmp(const Box &a, const Box &b) {
	for(int i = 0; i < a.d; i++) {
		if(a.s[i] < b.s[i]) return true;
		if(a.s[i] > b.s[i]) return false;
	}
	return true;
}

int main() {
	Box boxes[MAX_BOX];
	int len[MAX_BOX], out[MAX_BOX];

	int n, d;
	while(cin >> n >> d) {
		for(int i = 0; i < n; i++) {
			boxes[i].id = i, boxes[i].d = d;
			for(int j = 0; j < d; j++)
				cin >> boxes[i].s[j];
			boxes[i].dSort();
		}

		sort(boxes, boxes + n, cmp);

		fill(len, len + n, 1);
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if((boxes[i] < boxes[j]) && (len[i] + 1 > len[j]))
					len[j] = len[i] + 1;
			}
		}
		int maxLen = *max_element(len, len + n);
		cout << maxLen << endl;
		for(int i = n - 1, cur = maxLen; i >= 0; i--) {
			if(len[i] == cur)
				out[--cur] = boxes[i].id + 1;
		}
		for(int i = 0; i < maxLen; i++) {
			if(i != 0) cout << " ";
			cout << out[i];
		}
		cout << endl;
	}
}
