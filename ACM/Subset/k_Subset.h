#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s;
	while(getline(cin, s)) {
		int n;
		cin >> n;
		cin.ignore();

		stringstream ss;
		ss << s;
		char t;
		vector<char> arr;
		while(ss >> t) arr.push_back(t);

		sort(arr.begin(), arr.end());

		vector<int> cur(n, 0);
		for(int i = 0; i < n; i++) cur[i] = i;
		for(int i = 0; i < cur.size(); i++) cout << arr[cur[i]] << " ";
		cout << endl;

		bool done = false;
		while(!done) {
			done = true;
			for(int curI = cur.size() - 1, arrI = arr.size() - 1; curI >= 0; curI--, arrI--) {
				if(arr[cur[curI]] < arr[arrI]) {
					done = false;

					cur[curI]++;
					for(int curJ = curI + 1, arrJ = cur[curI] + 1; curJ < cur.size(); curJ++, arrJ++)
						cur[curJ] = arrJ;

					for(int i = 0; i < cur.size(); i++) cout << arr[cur[i]] << " ";
					cout << endl;

					break;
				}
			}
		}
	}
}
