// Pi *AC*

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int gcd(int a, int b) {
	if(a == 0)
		return b;
	if(b == 0)
		return a;

	if(a > b)
		return gcd(a % b, b);
	return gcd(b % a, a);
}

int main() {
	int numOfLines;
	while(cin >> numOfLines) {
		if(numOfLines == 0)
			return 0;

		int* data = new int[numOfLines];
		for(int i = 0; i < numOfLines; i++)
			cin >> data[i];

		int count = 0, coprimeCount = 0;
		for(int i = 0; i < numOfLines; i++) {
			for(int j = i + 1; j < numOfLines; j++) {
				if(gcd(data[i], data[j]) == 1)
					coprimeCount++;
				count++;
			}
		}

		double calc = (double)coprimeCount / (double)count;
		if(calc == 0)
			cout << "No estimate for this data set." << endl;
		else {
			char buf[20];
			sprintf(buf, "%10.6f", sqrt((float)6 / calc));
			for(int i = 0; buf[i] != 0; i++) {
				if(buf[i] != ' ')
					cout << buf[i];
			}
			cout << endl;
		}

		delete data;
	}
}
