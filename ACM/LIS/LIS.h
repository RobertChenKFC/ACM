#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	// getting input
	int n;
	cin >> n;
	vector<int> seq(n, 0);
	for(int i = 0; i < n; i++)
		cin >> seq[i];

	// calculating length only (nonstrictly increasing)
	cout << "Calculating length only: " << endl;
	vector<int> lisLen;
	lisLen.push_back(seq.front());
	for(int i = 1; i < n; i++) {
		int cur = seq[i];
		// greater than current greatest -> append
		if(cur > lisLen.back()) lisLen.push_back(cur);
		// less than current least -> replace
		else if(cur < lisLen.front()) lisLen.front() = cur;
		// between -> replace upper bound
		else *upper_bound(lisLen.begin(), lisLen.end(), cur) = cur;
	}
	cout << "LIS length: " << lisLen.size() << endl;

	// calculating length and getting content
	cout << "Calculating length and getting content: " << endl;
	vector<int> lis, pos(n, 0);
	int curPos = 0;
	lis.push_back(seq.front()), pos[0] = curPos++;
	for(int i = 1; i < n; i++) {
		int cur = seq[i];
		// position is the last
		if(cur > lis.back()) lis.push_back(cur), pos[i] = lis.size() - 1;
		// position is the first
		else if(cur < lis.front()) lis.front(), pos[i] = 0;
		// position is the upper bound's position
		else {
			vector<int>::iterator it = upper_bound(lis.begin(), lis.end(), cur);
			*it = cur, pos[i] = it - lis.begin();
		}
	}
	int len = lis.size(), foundPos = len - 1;
	deque<int> lisContent;
	cout << "LIS length: " << len << endl;
	for(int i = n - 1; i >= 0 && foundPos >= 0; i--) {
		// retrace positions
		if(pos[i] == foundPos) {
			lisContent.push_front(seq[i]);
			foundPos--;
		}
	}
	cout << "LIS: ";
	for(int i = 0; i < lisContent.size(); i++)
		cout << lisContent[i] << " ";
	cout << endl;
}
