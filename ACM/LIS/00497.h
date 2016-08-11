// Strategic Defense Initiative *AC*

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	cin.ignore();
	for(int curCase = 1; curCase <= n; curCase++) {
		vector<int> missles;
		string input;
		while(getline(cin, input) && input.length() != 0) {
			stringstream ss;
			int height;
			ss << input, ss >> height;
			missles.push_back(height);
		}

		int numMissles = missles.size();
		vector<int> lis, pos(numMissles, -1);
		lis.push_back(missles.front()), pos[0] = 0;
		for(int i = 0; i < numMissles; i++) {
			int cur = missles[i];
			if(cur > lis.back()) pos[i] = lis.size(), lis.push_back(cur);
			else {
				vector<int>::iterator it = upper_bound(lis.begin(), lis.end(), cur);
				int curPos = it - lis.begin();
				if(curPos < lis.size()) *it = cur, pos[i] = it - lis.begin();
				else pos[i] = lis.size() - 1;
			}
		}
		if(curCase != 1) cout << endl;
		cout << "Max hits: " << lis.size() << endl;

		deque<int> content;
		int cur = lis.size() - 1;
		for(int i = numMissles - 1; i >= 0 && cur >= 0; i--) {
			if(pos[i] == cur) {
				content.push_front(missles[i]);
				cur--;
			}
		}
		for(int i = 0; i < content.size(); i++)
			cout << content[i] << endl;
	}
}
