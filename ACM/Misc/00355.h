// The Bases Are Loaded *AC*

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int ToNum(const char &c) {
	if(c <= '9') return c - '0';
	else return 10 + c - 'A';
}

char ToChar(const int &n) {
	if(n < 10) return n + '0';
	else return 'A' + n - 10;
}

typedef long long ToLong;

int main() {
	int base1, base2;
	string num;
	while(cin >> base1 >> base2 >> num) {
		bool valid = true;
		for(int i = num.length() - 1; i >= 0; i--) {
			if(ToNum(num[i]) >= base1) {
				valid = false;
				break;
			}
		}
		if(!valid) cout << num << " is an illegal base " << base1 << " number" << endl;
		else {
			long long nBase10;
			if(base1 != 10) {
				long long multiply = 1;
				nBase10 = 0;
				for(int i = num.length() - 1; i >= 0; i--, multiply *= ToLong(base1))
					nBase10 += ToNum(num[i]) * multiply;
			}
			else nBase10 = atoll(num.c_str());

			string out = "";
			if(base2 != 10) {
				do {
					long long q = nBase10 / base2;
					out.insert(0, string(1, ToChar(nBase10 - q * base2)));
					nBase10 = q;
				} while(nBase10 != 0);
			}
			else {
				stringstream ss;
				ss << nBase10;
				ss >> out;
			}
			cout << num << " base " << base1 << " = " << out << " base " << base2 << endl;
		}
	}
}
