// Is Bigger Smarter? *AC*

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

struct Elephant {
	int w;
	int iq;
	int i;

	bool operator==(const Elephant &rhs) const { return ((w == rhs.w) && (iq == rhs.iq)); }
	bool operator!=(const Elephant &rhs) const { return !(*this == rhs); }
	bool operator<(const Elephant &rhs) const { return ((w < rhs.w) && (iq > rhs.iq)); }
	bool operator>(const Elephant &rhs) const { return ((w > rhs.w) && (iq < rhs.iq)); }
	bool operator<=(const Elephant &rhs) const { return !(*this > rhs); }
	bool operator>=(const Elephant &rhs) const { return !(*this < rhs); }
};

const int MAX_ELEPHANTS = 1005;

bool cmp(const Elephant &a, const Elephant &b) {
	if(a.w == b.w) return a.iq > b.iq;
	return a.w < b.w;
}

deque<int> getLis(Elephant elephants[], int pos[], int n) {
	vector<int> len(n, 1);
	for(int i = n - 1; i >= 0; i--) {
		for(int j = i - 1; j >= 0; j--) {
			if(elephants[i] > elephants[j] && (len[i] + 1 > len[j]))
				len[j] = len[i] + 1;
		}
	}
	int maxLen = *max_element(len.begin(), len.end());
	deque<int> content;
	for(int i = 0, cur = maxLen; i < n; i++)
		if(len[i] == cur) content.push_back(elephants[i].i), cur--;
	return content;
}

int main() {
	int n = 0;
	int w, iq;
	Elephant elephants[MAX_ELEPHANTS];
	int pos[MAX_ELEPHANTS] = { 0 };
	while(cin >> w >> iq)
		elephants[n++] = { w, iq, n };


	sort(elephants, elephants + n, cmp);
	deque<int> content = getLis(elephants, pos, n);
	cout << content.size() << endl;
	for(int i = 0; i < content.size(); i++)
		cout << content[i] << endl;
}
