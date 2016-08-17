// Repeating Decimals *AC*

#include <iostream>
#include <string>

using namespace std;

struct Remain {
	int pos;
	int q;
};

int main() {
	int a, b;
	while(cin >> a >> b) {
		Remain *remains = new Remain[b];
		for(int i = 0; i < b; i++) remains[i] = { -1, -1 };

		cout << a << "/" << b << " = " << a / b << "." << flush;
		a %= b;
		string s = "";
		int repLen;
		int q, r;
		while(true) {
			if(a < b) a *= 10;

			q = a / b, r = a % b;
			if(remains[r].pos != -1 && remains[r].q == q) {
				repLen = s.length() - remains[r].pos;
				break;
			}
			else {
				s += char(q + '0');
				remains[r].pos = s.length() - 1, remains[r].q = q;
			}

			a = r;
		}

		if(s.length() > 50) {
			s = s.substr(0, 50);
			s += "...";
		}
		s.insert(remains[r].pos, "(");
		s += ")";

		cout << s << endl
			 << "   " << repLen << " = number of digits in repeating cycle" << endl << endl;

		delete[] remains;
	}
}
