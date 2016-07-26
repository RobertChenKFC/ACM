// The Sultan's Successor *AC*

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 8;
const int NUM_SOL = 92;
const int NOT_SET = -1;

void GenBoards(int sols[][SIZE], int curSol[], int& curSolIndex, int curQueen = 0) {
	// last queen placed
	if(curQueen == SIZE) {
		memcpy(sols[curSolIndex], curSol, sizeof(int) * SIZE);
		curSolIndex++;
		return;
	}

	for(int i = 0; i < SIZE; i++) {
		bool valid = true;
		// check if queen is not attacked
		for(int j = curQueen - 1, topH = i - 1, bottomH = i + 1; j >= 0; j--, topH--, bottomH++) {
			if(curSol[j] == i || curSol[j] == topH || curSol[j] == bottomH) {
				valid = false;
				break;
			}
		}
		// copies the board and keep on placing
		if(valid) {
			int solCpy[SIZE];
			memcpy(solCpy, curSol, sizeof(int) * SIZE);
			solCpy[curQueen] = i;
			GenBoards(sols, solCpy, curSolIndex, curQueen + 1);
		}
	}
}

int main() {
	// generate queen boards
	int sols[NUM_SOL][SIZE], buf[SIZE], index = 0;
	for(int i = 0; i < NUM_SOL; i++)
		memset(sols[i], NOT_SET, sizeof(buf));
	memset(buf, 0, sizeof(buf));
	GenBoards(sols, buf, index);

	// get input
	int numCases;
	cin >> numCases;
	while(numCases--) {
		int scores[SIZE][SIZE];
		for(int i = 0; i < SIZE; i++) {
			for(int j = 0; j < SIZE; j++)
				cin >> scores[i][j];
		}

		int maxScore = -1;
		for(int i = 0, curScore = 0; i < NUM_SOL; i++, curScore = 0) {
			for(int col = 0; col < SIZE; col++) {
				int row = sols[i][col];
				curScore += scores[row][col];
			}

			if(curScore > maxScore)
				maxScore = curScore;
		}

		for(int limit = 10000; limit > 1; limit /= 10) {
			if(maxScore < limit)
				cout << " ";
		}
		cout << maxScore << endl;
	}
}
