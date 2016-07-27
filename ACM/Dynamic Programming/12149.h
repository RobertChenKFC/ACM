// Feynman *AC*

#include <iostream>

using namespace std;

const int SIZE = 105;

int main() {
	int feynman[SIZE + 1];
	feynman[0] = 0;
	for(int i = 1; i <= SIZE; i++)
		feynman[i] = feynman[i - 1] + i * i;

	int n;
	while(cin >> n, n != 0)
		cout << feynman[n] << endl;
}
