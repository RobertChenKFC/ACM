// Prime Land *AC*

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string numToStr(int num) {
	string result;
	while(num != 0) {
		result.insert(0, 1, (num % 10) + '0');
		num /= 10;
	}
	return result;
}

int strToNum(string str) {
	int result = 0;
	int size = str.length();
	for(int i = 0; i < size; i++)
		result = result * 10 + (str[i] - '0');
	return result;
}

long Pow(long base, long power) {
	long result = 1;
	for(int i = 0; i < power; i++)
		result *= base;
	return result;
}

int main() {
	string input;
	while(true) {
		getline(cin, input);
		input += " ";

		if(input[0] == '0')
			return 0;

		long num = 1, size = input.length(), curBase = 0, curPower = 0;
		bool curIsBase = true;
		for(int i = 0; i < size; i++) {
			if(input[i] == ' ') {
				if(curIsBase) {
					curIsBase = false;
					curPower = 0;
				}
				else {
					curIsBase = true;
					num *= Pow(curBase, curPower);
					curBase = 0;
				}
				continue;
			}

			if(curIsBase)
				curBase = curBase * 10 + (input[i] - '0');
			else
				curPower = curPower * 10 + (input[i] - '0');
		}

		string factors;
		num--;
		long numCopy = num;
		bool first = true;

		// loop for 2
		curBase = 2, curPower = 0;
		if(numCopy % 2 == 0) {
			do {
				numCopy /= 2;
				curPower++;
				first = false;
			} while(numCopy % 2 == 0);
			factors.insert(0, numToStr(curBase) + " " + numToStr(curPower));
		}

		// loop for 3
		curBase = 3, curPower = 0;
		if(numCopy % 3 == 0) {
			do {
				numCopy /= 3;
				curPower++;
				first = false;
			} while(numCopy % 3 == 0);
			if(!first)
				factors.insert(0, " ");
			factors.insert(0, numToStr(curBase) + " " + numToStr(curPower));
		}

		// loop for others
		long limit = (long)sqrt(num) + 1;
		for(long i = 5, gap = 2; i < limit; i += gap, gap = 6 - gap) {
			curBase = i, curPower = 0;
			if(numCopy % i == 0) {
				do {
					numCopy /= i;
					curPower++;
					first = false;
				} while(numCopy % i == 0);
				if(!first)
					factors.insert(0, " ");
				factors.insert(0, numToStr(curBase) + " " + numToStr(curPower));
			}

		}

		// for left prime factors
		if(numCopy != 1) {
			if(!first)
				factors.insert(0, numToStr(numCopy) + " " + numToStr(1) + " ");
			else
				factors.insert(0, numToStr(numCopy) + " " + numToStr(1));
		}

		// remove last space
		if(factors[factors.length() - 1] == ' ')
			factors.erase(factors.length() - 1);

		cout << factors << endl;
	}
}
