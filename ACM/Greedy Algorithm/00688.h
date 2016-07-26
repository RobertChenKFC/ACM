// Parliament *AC*

#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int numCases;
	cin >> numCases;
	for(int caseNum = 0; caseNum < numCases; caseNum++) {
		int n;
		cin >> n;
		int limit = (sqrt(8 * n + 9) - 1) / 2,
			parts = limit - 1,
			sum = (limit + 2) * (limit - 1) / 2,
			start = parts - (n - sum);
		bool addMore = false;
		if(start < 0)
			start = 0, addMore = true;

		if(caseNum != 0)
			cout << endl;
		for(int i = 0, cur = 2; i < parts; i++, cur++) {
			if(i == start || (addMore && i == parts - 1))
				cur++;
			if(i != 0)
				cout << " ";
			cout << cur;
		}
		cout << endl;
	}
}
