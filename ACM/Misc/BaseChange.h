#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string nStr;
	int base;
	cin >> nStr;
	do { cin >> base; } while(base > 10);

	cout << nStr << " from base 10 to base " << base << ": ";
	stringstream ss;
	ss << nStr;
	int n;
	ss >> n;
	string out;
	while(n != 0) {
		out.insert(0, string(1, char((n % base) + '0')));
		n /= base;
	}
	cout << out << endl;

	n = 0;
	cout << nStr << " from base " << base << " to base 10: ";
	for(int i = nStr.length() - 1, multiply = 1; i >= 0; i--, multiply *= base)
		n += (nStr[i] - '0') * multiply;
	cout << n << endl;
}
