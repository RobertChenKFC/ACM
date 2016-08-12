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

	// calculating length only (strictly increasing)
	cout << "Calculating length only (strictly increasing): " << endl;
	vector<int> lisLen;
	lisLen.push_back(seq.front());
	for(int i = 1; i < n; i++) {
		int cur = seq[i];
		// greater than current greatest -> append
		if(cur > lisLen.back()) lisLen.push_back(cur);
		// less or equal to current greatest -> replace lower bound
		else *lower_bound(lisLen.begin(), lisLen.end(), cur) = cur;
	}
	cout << "LIS length: " << lisLen.size() << endl;

	// calculating length only (nonstrictly increasing)
	cout << "Calculating length only (nonstrictly increasing): " << endl;
	lisLen.clear();
	lisLen.push_back(seq.front());
	for(int i = 1; i < n; i++) {
		int cur = seq[i];
		// greater than current greatest -> append
		if(cur > lisLen.back()) lisLen.push_back(cur);
		// less than current least -> replace
		else if(cur < lisLen.front()) lisLen.front() = cur;
		// between -> replace upper bound
		else {
			vector<int>::iterator it = upper_bound(lisLen.begin(), lisLen.end(), cur);
			if(it - lisLen.begin() >= lisLen.size()) lisLen.push_back(cur);
			else *it = cur;
		}
	}
	cout << "LIS length: " << lisLen.size() << endl;

	// calculating length and getting content (strictly increasing)
	cout << "Calculating length and getting content (strictly increasing): " << endl;
	vector<int> lens(n, 1);
	int maxLen;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if((seq[j] > seq[i]) && (lens[i] + 1 > lens[j]))
				lens[j] = lens[i] + 1, maxLen = lens[j];
		}
	}
	cout << "LIS length: " << maxLen << endl;
	cout << "LIS: ";
	deque<int> content;
	int curLen = maxLen;
	for(int i = n - 1; i >= 0 && curLen > 0; i--) {
		if(lens[i] == curLen)
			content.push_front(seq[i]), curLen--;
	}
	for(int i = 0; i < maxLen; i++)
		cout << content[i] << " ";
	cout << endl;

	// calculating length and getting content (nonstrictly increasing)
	cout << "Calculating length and getting content (nonstrictly increasing): " << endl;
	fill(lens.begin(), lens.end(), 1);
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if((seq[j] >= seq[i]) && (lens[i] + 1 > lens[j]))
				lens[j] = lens[i] + 1, maxLen = lens[j];
		}
	}
	cout << "LIS length: " << maxLen << endl;
	cout << "LIS: ";
	content.clear();
	curLen = maxLen;
	for(int i = n - 1; i >= 0 && curLen > 0; i--) {
		if(lens[i] == curLen)
			content.push_front(seq[i]), curLen--;
	}
	for(int i = 0; i < maxLen; i++)
		cout << content[i] << " ";
	cout << endl;
}
