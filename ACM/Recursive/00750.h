#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const char EMPTY = 0, HAS_QUEEN = 1, INVALID = 2;
const int SIZE = 8;
int slnNum = 1;
void GenerateValidBoards(int board[][SIZE], int inputQueenRow, int curQueenRow = 0) {
	if(curQueenRow == inputQueenRow)
		curQueenRow++;
	if(curQueenRow == SIZE) {
		int numOfQueens = 0;
		for(int j = 0; j < SIZE; j++) {
			for(int k = 0; k < SIZE; k++) {
				if(board[j][k] == HAS_QUEEN)
					numOfQueens++;
			}
		}

		if(numOfQueens == SIZE) {
			bool first = true;
			if(slnNum < 10)
				cout << " ";
			cout << slnNum++ << "      ";
			for(int j = 0; j < SIZE; j++) {
				for(int k = 0; k < SIZE; k++) {
					if(board[j][k] == HAS_QUEEN) {
						if(!first)
							cout << " ";
						first = false;

						cout << k + 1;
						break;
					}
				}
			}
			cout << endl;
		}
		return;
	}

	for(int i = 0; i < SIZE; i++) {
		// copy data
		int calcBoard[SIZE][SIZE];
		for(int j = 0; j < SIZE; j++) {
			for(int k = 0; k < SIZE; k++)
				calcBoard[j][k] = board[j][k];
		}

		// place queen
		if(calcBoard[curQueenRow][i] == EMPTY) {
			calcBoard[curQueenRow][i] = HAS_QUEEN;
			// vertical
			for(int j = 0; j < SIZE; j++) {
				if(j != curQueenRow)
					calcBoard[j][i] = INVALID;
			}
			// diagonal
			for(int j = curQueenRow + 1, k = i + 1; j < SIZE && k < SIZE; j++, k++)
				calcBoard[j][k] = INVALID;
			for(int j = curQueenRow - 1, k = i + 1; j >= 0 && k < SIZE; j--, k++)
				calcBoard[j][k] = INVALID;

			if(curQueenRow != 7)
				GenerateValidBoards(calcBoard, inputQueenRow, curQueenRow + 1);
			else {
				int numOfQueens = 0;
				for(int j = 0; j < SIZE; j++) {
					for(int k = 0; k < SIZE; k++) {
						if(calcBoard[j][k] == HAS_QUEEN)
							numOfQueens++;
					}
				}

				if(numOfQueens == SIZE) {
					bool first = true;
					if(slnNum < 10)
						cout << " ";
					cout << slnNum++ << "      ";
					for(int j = 0; j < SIZE; j++) {
						for(int k = 0; k < SIZE; k++) {
							if(calcBoard[j][k] == HAS_QUEEN) {
								if(!first)
									cout << " ";
								first = false;

								cout << k + 1;
								break;
							}
						}
					}
					cout << endl;
				}
			}
		}
	}
}

int main() {
	int numOfTests;
	cin >> numOfTests;

	for(int a = 0; a < numOfTests; a++) {
		cout << "SOLN       COLUMN" << endl
			 << " #      1 2 3 4 5 6 7 8" << endl << endl;

		int board[SIZE][SIZE] = {0};

		int row, column;
		cin >> column >> row;
		row--, column--;
		board[row][column] = HAS_QUEEN;
		// horizontal
		for(int j = 0; j < SIZE; j++) {
			if(j != column)
				board[row][j] = INVALID;
		}
		// vertical
		for(int j = 0; j < SIZE; j++) {
			if(j != row)
				board[j][column] = INVALID;
		}
		// diagonal
		for(int j = row - 1, k = column - 1; j >= 0 && k >= 0; j--, k--)
			board[j][k] = INVALID;
		for(int j = row + 1, k = column - 1; j < 8 && k >= 0; j++, k--)
			board[j][k] = INVALID;
		for(int j = row - 1, k = column + 1; j >= 0 && k < SIZE; j--, k++)
			board[j][k] = INVALID;
		for(int j = row + 1, k = column + 1; j < 8 && k < SIZE; j++, k++)
			board[j][k] = INVALID;

		GenerateValidBoards(board, row);
		slnNum = 1;

		if(a != numOfTests - 1)
			cout << endl;
	}

	return 0;
}
