// Adding Reversed Numbers *AC*

#include <iostream>
#include <string>

using namespace std;

int main() {
	int numCases;
	cin >> numCases;
	for(int caseNum = 0; caseNum < numCases; caseNum++) {
		string a, b;
		cin >> a >> b;

		int aSize = a.length(), bSize = b.length();
		bool start = false;
		int carry = 0;
		for(int aI = 0, bI = 0; aI < aSize || bI < bSize; aI++, bI++) {
			int curDigit = carry;
			carry = 0;

			if(aI < aSize)
				curDigit += a[aI] - '0';
			if(bI < bSize)
				curDigit += b[bI] - '0';

			if(curDigit >= 10)
				curDigit -= 10, carry++;

			if(curDigit != 0)
				start = true;
			if(start)
				cout << curDigit;
		}
		if(carry != 0)
			cout << carry;

		cout << endl;
	}
}
