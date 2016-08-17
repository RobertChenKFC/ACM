#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef long long LONG;

struct Remain {
	int pos;
	int q;
};

const int NOT_USED = -1;

int main() {
	LONG a, b;
	cin >> a >> b;

	cout << a << " / " << b << " = " << a / b << "." << flush;
	a %= b;
	Remain *used = new Remain[b];
	for(int i = 0; i < b; i++) used[i] = { -1, -1 };
	string s = "";
	while(true) {
		if(a < b) a *= 10;

		int q = a / b;
		a %= b;
		if(used[a].pos != NOT_USED && used[a].q == q) {
			if(used[a].q != 0) {
				s.insert(used[a].pos, "(");
				s += ")";
			}
			else {
				s.erase(s.length() - 1);
			}
			break;
		}
		else {
			used[a] = { s.length(), q };
			s += char(q + '0');
		}
	}
	cout << s << endl;
	delete[] used;
}
