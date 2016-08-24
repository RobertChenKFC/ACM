// Polly the Polynomial *AC*

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	string coEffStr, xValStr;
	while(getline(cin, coEffStr) && getline(cin, xValStr)) {
		vector<long long> coEff;
		stringstream ss;
		ss << coEffStr;
		long long curCoEff;
		while(ss >> curCoEff) coEff.push_back(curCoEff);

		ss.clear();
		ss << xValStr;
		long long curX;
		bool first = true;
		while(ss >> curX) {
			long long multiply = 1, result = 0;
			for(int i = coEff.size() - 1; i >= 0; i--, multiply *= curX)
				result += multiply * coEff[i];

			if(!first) cout << " ";
			else first = false;
			cout << fixed << result;
		}
		cout << endl;
	}
}
