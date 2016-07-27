// Brick Wall Patterns *AC*

#include <iostream>

using namespace std;

const int MAX_SIZE = 55;

int main() {
	int fib[MAX_SIZE];
	fib[0] = 1, fib[1] = 1;
	for(int i = 2; i < MAX_SIZE; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	int n;
	cin >> n;
	while(n != 0) {
		cout << fib[n] << endl;
		cin >> n;
	}
}
