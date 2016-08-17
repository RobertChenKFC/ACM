// Pseudo-Random Numbers *AC*

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int multiply, increment, modulus, seed;
	int caseNum = 1;
	while(true) {
		cin >> multiply >> increment >> modulus >> seed;
		if(multiply == increment && increment == modulus && modulus == seed && seed == 0) break;

		bool *used = new bool[modulus];
		memset(used, 0, modulus);

		int len = 0, n = seed;
		while(n = (n * multiply + increment) % modulus, !used[n]) len++, used[n] = true;

		delete[] used;

		cout << "Case " << caseNum++ << ": " << len << endl;
	}
}
