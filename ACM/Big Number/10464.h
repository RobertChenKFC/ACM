#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 2016;

int main() {
	int numCases;
	cin >> numCases;
	while(numCases--) {
		char inputA[SIZE], inputB[SIZE];
		memset(inputA, '0', sizeof(inputA));
		memset(inputB, '0', sizeof(inputB));

		cin >> inputA >> inputB;

		int decA = 0, decB = 0, decDiff, pointIndex;
		while(inputA[decA] != '.') decA++;
		while(inputB[decB] != '.') decB++;

		if(decA > decB) {
			decDiff = decA - decB, pointIndex = decDiff;
			char t[SIZE];
			memset(t, '0', sizeof(t));
			memcpy(&t[decDiff], inputB, sizeof(strlen(inputB) * sizeof(char)));
			memcpy(inputB, t, sizeof(inputB));
		}
		else if(decA < decB) {
			decDiff = decB - decA, pointIndex = decDiff;
			char t[SIZE];
			memset(t, '0', sizeof(t));
			memcpy(&t[decDiff], inputA, sizeof(strlen(inputA) * sizeof(char)));
			memcpy(inputA, t, sizeof(inputA));
		}
		else if(decA == 0 && decB == 0) {
			pointIndex = 1;
			char t[SIZE];
			memcpy(&t[1], inputA, sizeof(t) - sizeof(char));
			t[0] = '0';
			memcpy(inputA, t, sizeof(t) - sizeof(char));

			memcpy(&t[1], inputB, sizeof(t) - sizeof(char));
			t[0] = '0';
			memcpy(inputB, t, sizeof(t) - sizeof(char));
		}
		else
			pointIndex = decA;
		inputA[strlen(inputA)] = '0', inputB[strlen(inputB)] = '0';
		inputA[SIZE - 1] = '0', inputB[SIZE - 1] = '0';

		//cout << inputA << endl << inputB << endl;

		char result[SIZE] = {0};
		for(int i = SIZE - 1, resultIndex = SIZE - 1; i >= 0; i--) {
			if(i != pointIndex) {
				result[resultIndex] += inputA[i] + inputB[i] - 2 * '0';
				if(result[resultIndex] >= 10)
					result[resultIndex - 1]++, result[resultIndex] -= 10;
				resultIndex--;
			}
		}

		int start = 0, end = SIZE - 1;
		while(result[start] == 0) start++;
		while(result[end] == 0) end--;
		pointIndex += start;

		for(int i = start; i <= end; i++) {
			if(i == pointIndex)
				cout << '.';
			cout << (int)result[i];
		}
		cout << endl;
	}
}
