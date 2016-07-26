// Check the Check *AC*

#include <iostream>

using namespace std;

const int SIZE = 8;
const char W_PAWN = 'P', W_ROOK = 'R', W_BISHOP = 'B', W_KING = 'K', W_QUEEN = 'Q', W_KNIGHT = 'N',
		B_PAWN = 'p', B_ROOK = 'r', B_BISHOP = 'b', B_KING = 'k', B_QUEEN = 'q', B_KNIGHT = 'n',
		EMPTY = '.';

bool rookCheck(char board[][SIZE], int i, int j, char king) {
	for(int k = i - 1; k >= 0; k--) {
		// up
		if(board[k][j] == king)
			return true;
		else if(board[k][j] != EMPTY)
			break;
	}
	for(int k = i + 1; k < SIZE; k++) {
		// down
		if(board[k][j] == king)
			return true;
		else if(board[k][j] != EMPTY)
			break;
	}
	for(int k = j - 1; k >= 0; k--) {
		// left
		if(board[i][k] == king)
			return true;
		else if(board[i][k] != EMPTY)
			break;
	}
	 for(int k = j + 1; k < SIZE; k++) {
		// right
		if(board[i][k] == king)
			return true;
		else if(board[i][k] != EMPTY)
			break;
	}
	return false;
}

bool bishopCheck(char board[][SIZE], int i, int j, char king) {
	// top left
	for(int k = i - 1, l = j - 1; k >= 0 && l >= 0; k--, l--) {
		if(board[k][l] == king)
			return true;
		else if(board[k][l] != EMPTY)
			break;
	}
	// bottom right
	for(int k = i + 1, l = j + 1; k < SIZE && l < SIZE; k++, l++) {
		if(board[k][l] == king)
			return true;
		else if(board[k][l] != EMPTY)
			break;
	}
	// top right
	for(int k = i - 1, l = j + 1; k >= 0 && l < SIZE; k--, l++) {
		if(board[k][l] == king)
			return true;
		else if(board[k][l] != EMPTY)
			break;
	}
	// bottom right
	for(int k = i + 1, l = j - 1; k < SIZE && l >= 0; k++, l--) {
		if(board[k][l] == king)
			return true;
		else if(board[k][l] != EMPTY)
			break;
	}
	return false;
}

bool queenCheck(char board[][SIZE], int i, int j, char king) {
	if(rookCheck(board, i, j, king))
		return true;
	else if(bishopCheck(board, i, j, king))
		return true;
	else
		return false;
}

bool knightCheck(char board[][SIZE], int i, int j, char king) {
	if(i - 2 >= 0) {
		if(j - 1 >= 0 && board[i - 2][j - 1] == king)
			return true;
		else if(j + 1 < SIZE && board[i - 2][j + 1] == king)
			return true;
	}
	if(i - 1 >= 0) {
		if(j - 2 >= 0 && board[i - 1][j - 2] == king)
			return true;
		else if(j + 2 < SIZE && board[i - 1][j + 2] == king)
			return true;
	}
	if(i + 1 < SIZE) {
		if(j - 2 >= 0 && board[i + 1][j - 2] == king)
			return true;
		else if(j + 2 < SIZE && board[i + 1][j + 2] == king)
			return true;
	}
	if(i + 2 < SIZE) {
		if(j - 1 >= 0 && board[i + 2][j - 1] == king)
			return true;
		else if(j + 1 < SIZE && board[i + 2][j + 1] == king)
			return true;
	}
	return false;
}

int main() {
	char board[SIZE][SIZE];
	for(int game = 1; true; game++) {
		bool empty = true;
		bool wInCheck = false, bInCheck = false;
		for(int i = 0; i < SIZE; i++) {
			for(int j = 0; j < SIZE; j++) {
				cin >> board[i][j];
				if(board[i][j] != EMPTY)
					empty = false;
			}
		}

		if(empty)
			return 0;

		for(int i = 0; i < SIZE; i++) {
			for(int j = 0; j < SIZE; j++) {
				switch(board[i][j]) {
				case W_PAWN:
					if(i > 0) {
						// top left
						if(j > 0 && board[i - 1][j - 1] == B_KING) {
							bInCheck = true;
							goto FINISHED;
						}
						// top right
						else if(j < SIZE - 1 && board[i - 1][j + 1] == B_KING) {
							bInCheck = true;
							goto FINISHED;
						}
					}
					break;
				case B_PAWN:
					if(i < SIZE - 1) {
						// bottom left
						if(j > 0 && board[i + 1][j - 1] == W_KING) {
							wInCheck = true;
							goto FINISHED;
						}
						// bottom right
						else if(j < SIZE - 1 && board[i + 1][j + 1] == W_KING) {
							wInCheck = true;
							goto FINISHED;
						}
					}
					break;
				case W_ROOK:
					if(rookCheck(board, i, j, B_KING)) {
						bInCheck = true;
						goto FINISHED;
					}
					break;
				case B_ROOK:
					if(rookCheck(board, i, j, W_KING)) {
						wInCheck = true;
						goto FINISHED;
					}
					break;
				case W_BISHOP:
					if(bishopCheck(board, i, j, B_KING)) {
						bInCheck = true;
						goto FINISHED;
					}
					break;
				case B_BISHOP:
					if(bishopCheck(board, i, j, W_KING)) {
						wInCheck = true;
						goto FINISHED;
					}
					break;
				case W_QUEEN:
					if(queenCheck(board, i, j, B_KING)) {
						bInCheck = true;
						goto FINISHED;
					}
					break;
				case B_QUEEN:
					if(queenCheck(board, i, j, W_KING)) {
						wInCheck = true;
						goto FINISHED;
					}
					break;
				case W_KNIGHT:
					if(knightCheck(board, i, j, B_KING)) {
						bInCheck = true;
						goto FINISHED;
					}
					break;
				case B_KNIGHT:
					if(knightCheck(board, i, j, W_KING)) {
						wInCheck = true;
						goto FINISHED;
					}
					break;
				} // end of switch
			}
		}

		FINISHED:
		cout << "Game #" << game << ": ";
		if(wInCheck)
			cout << "white king is in check." << endl;
		else if(bInCheck)
			cout << "black king is in check." << endl;
		else
			cout << "no king is in check." << endl;
	}
}
