// What Goes Up *AC*

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main() {
	vector<int> v;
	int n;
	while(cin >> n) v.push_back(n);

	int size = v.size();
	vector<int> lis(1, v.front());
	vector<int> pos(size, -1);
	pos[0] = 0;
	vector<int>::iterator it;
	for(int i = 1; i < size; i++) {
		int &cur = v[i];
		if(cur > lis.back()) { pos[i] = lis.size(); lis.push_back(cur); }
		else {
			it = lower_bound(lis.begin(), lis.end(), cur);
			pos[i] = it - lis.begin(), *it = cur;
		}
	}

	int len = lis.size();
	cout << len << endl
		<< '-' << endl;

	deque<int> content;
	for(int i = size - 1, curpos = len - 1; pos[i] >= 0; i--)
		if(pos[i] == curpos) { content.push_front(v[i]); curpos--; }
	for(const auto &x : content) cout << x << endl;
}
