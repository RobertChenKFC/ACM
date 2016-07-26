// Big Mod *AC*

#include <iostream>

using namespace std;

long BigMod(const long& b, long p, const long& m) {
	if(p == 0)
		return 1;
	if(p == 1)
		return b;

	if(p % 2 == 0) {
		long t = BigMod(b, p / 2, m);
		return (t * t) % m;
	}
	return (b * BigMod(b, p - 1, m)) % m;
}

int main() {
	long b, p, m;
	while(cin >> b >> p >> m)
		cout << BigMod(b, p, m) % m << endl;
}
