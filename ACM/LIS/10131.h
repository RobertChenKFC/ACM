#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

struct Elephant {
	int w;
	int iq;

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
	else return a.w < b.w;
}

int main() {
	int n = 0;
	int w, iq;
	Elephant elephants[MAX_ELEPHANTS];
	int pos[MAX_ELEPHANTS] = { 0 };
	while(cin >> w >> iq)
		elephants[n++] = { w, iq };

	vector<Elephant> lis;
	lis.push_back(elephants[0]), pos[0] = 0;
	for(int i = 1; i < n; i++) {
		Elephant cur = elephants[i];
		if(cur > lis.back()) pos[i] = lis.size(), lis.push_back(cur);
		else {
			vector<Elephant>::iterator it = lower_bound(lis.begin(), lis.end(), cur);
			int curPos = it - lis.begin();
			if(curPos < lis.size()) *it = cur, pos[i] = curPos;
			else curPos = lis.size() - 1;
		}
	}


	cout << lis.size() << endl;
	deque<int> content;
	int cur = lis.size() - 1 ;
	for(int i = n - 1; i >= 0 && cur >= 0; i--) {
		if(pos[i] == cur) {
			content.push_front(i + 1);
			cur--;
		}
	}
	for(int i = 0; i < content.size(); i++)
		cout << content[i] << endl;

	// test
	cout << "LIS elephants: " << endl;
	for(int i = 0; i < content.size(); i++)
		cout << elephants[(content[i] - 1)].w << " " << elephants[(content[i] - 1)].iq << endl;


	// eof: 
}
