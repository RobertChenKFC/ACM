#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int BUF_SIZE = 36, LL_MAX_DIGITS = 19;
const long long LL_MAX = 1000000000000000000;
class BigNum {
public:
	BigNum() {
		num[0] = 0, num[1] = 0;
	}

	void set() {

	}

	bool isZero() {
		return num[0] == 0 && num[1] == 0;
	}

	void operator+=(long long rhs) {
		num[1] += rhs;
		while(num[1] >= LL_MAX)
			num[0]++, num[1] -= LL_MAX;
	}

	bool operator==(BigNum rhs) {
		return (num[0] == rhs.num[0]) && (num[1] == rhs.num[1]);
	}

	void print() {
		if(num[0] != 0)
			cout << num[0];
		cout << num[1];
	}

	long long num[2];
};

const int EMPTY = -1;
int main() {
	int numOfDiscs;
	long long num[2] = {0};
	while(cin >> numOfDiscs) {
		// get number of moves (Big Number)
		char input[BUF_SIZE];
		cin >> input;
		char curPartition[LL_MAX_DIGITS];
		memset(curPartition, '0', LL_MAX_DIGITS);
		int curPartitionIndex = 1;
		for(int i = strlen(input) - 1, partitionIndex = LL_MAX_DIGITS - 1; i >= 0; i--) {
			curPartition[partitionIndex--] = input[i];
			if(partitionIndex == 0 && curPartitionIndex != 0) {
				partitionIndex = LL_MAX_DIGITS - 1;
				num[curPartitionIndex--] = atoll(curPartition);
				memset(curPartition, '0', LL_MAX_DIGITS);
			}
		}
		num[curPartitionIndex] = atoll(curPartition);

		// end of input check
		if(numOfDiscs == 0 && num[0] == 0 && num[1] == 0)
			return 0;

		// generate new tower of hanoi
		int** state = new int*[3];
		for(int i = 0; i < 3; i++) {
			state[i] = new int[numOfDiscs];
			for(int j = 0, curSize = numOfDiscs; j < numOfDiscs; j++, curSize--)
				state[i][j] = (i == 0) ? curSize : EMPTY;
		}

		// tower of hanoi simulation starts here
		int disc1Peg = 0;
		int pegTop[3] = {0};
		pegTop[0] = numOfDiscs - 1;
		bool curMoveIsEven = true;
		bool continueOn = true;

		while(true) {
			// counter
			if(num[1] != 0) {
				num[1]--;
				continueOn = true;
			}
			else if(num[0] != 0){
				num[0]--;
				num[1] = LL_MAX;
				continueOn = true;
			}
			else
				continueOn = false;

			if(!continueOn)
				break;

			if(curMoveIsEven) {
				state[disc1Peg][pegTop[disc1Peg]] = EMPTY;
				if(pegTop[disc1Peg] != 0)
					pegTop[disc1Peg]--;

				disc1Peg++;
				if(disc1Peg == 3)
					disc1Peg = 0;

				if(state[disc1Peg][pegTop[disc1Peg]] == EMPTY)
					state[disc1Peg][pegTop[disc1Peg]] = 1;
				else
					state[disc1Peg][pegTop[disc1Peg] + 1] = 1, pegTop[disc1Peg]++;
			}
			else {
				int peg1, peg2;
				if(disc1Peg == 0)
					peg1 = 1, peg2 = 2;
				else if(disc1Peg == 1)
					peg1 = 0, peg2 = 2;
				else
					peg1 = 0, peg2 = 1;

				if(state[peg1][pegTop[peg1]] == EMPTY) {
					state[peg1][pegTop[peg1]] = state[peg2][pegTop[peg2]];
					state[peg2][pegTop[peg2]] = EMPTY;
					if(pegTop[peg2] != 0)
						pegTop[peg2]--;
				}
				else if(state[peg2][pegTop[peg2]] == EMPTY) {
					state[peg2][pegTop[peg2]] = state[peg1][pegTop[peg1]];
					state[peg1][pegTop[peg1]] = EMPTY;
					if(pegTop[peg1] != 0)
						pegTop[peg1]--;
				}
				else if(state[peg1][pegTop[peg1]] < state[peg2][pegTop[peg2]]) {
					state[peg2][pegTop[peg2] + 1] = state[peg1][pegTop[peg1]];
					state[peg1][pegTop[peg1]] = EMPTY;
					if(pegTop[peg1] != 0)
						pegTop[peg1]--;
					pegTop[peg2]++;
				}
				else {
					state[peg1][pegTop[peg1] + 1] = state[peg2][pegTop[peg2]];
					state[peg2][pegTop[peg2]] = EMPTY;
					if(pegTop[peg2] != 0)
						pegTop[peg2]--;
					pegTop[peg1]++;
				}
			}

			curMoveIsEven = !curMoveIsEven;
		}
		// final total
		int discCountTotal = 0;
		for(int i = 0, discCount = 0; i < 2; i++, discCount = 0) {
			for(int j = 0; j < numOfDiscs; j++) {
				if(state[i][j] != EMPTY)
					discCount++;
			}
			cout << discCount << " ";
			discCountTotal += discCount;
		}
		cout << numOfDiscs - discCountTotal << endl;

		for(int i = 0; i < 3; i++)
			delete[] state[i];
		delete[] state;
	}
}
