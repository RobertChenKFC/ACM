#include <iostream>
#include <functional>

using namespace std;

enum { ROTATE = 0, FLIP = 1 };
enum { TOP_LEFT_RIGHT = 0, RIGHT_TOP_BOTTOM = 1, BOTTOM_RIGHT_LEFT = 2, LEFT_BOTTOM_TOP = 3 };

int main() {
	int row, col, n;
	cin >> row >> col >> n;
	int midrow = row / 2;

	int **mat = new int*[row];
	for(int i = 0; i < row; i++) {
		mat[i] = new int[col];
		for(int j = 0; j < col; j++) cin >> mat[i][j];
	}

	int dir = TOP_LEFT_RIGHT;
	int *ins = new int[n];
	for(int i = 0; i < n; i++) cin >> ins[i];

	for(int i = n - 1; i >= 0; i--) {
		if(ins[i] == ROTATE) {
			switch(dir) {
			case TOP_LEFT_RIGHT: dir = RIGHT_TOP_BOTTOM; break;
			case RIGHT_TOP_BOTTOM: dir = BOTTOM_RIGHT_LEFT; break;
			case BOTTOM_RIGHT_LEFT: dir = LEFT_BOTTOM_TOP; break;
			case LEFT_BOTTOM_TOP: dir = TOP_LEFT_RIGHT; break;
			}
		}
		else if(ins[i] == FLIP) {
			if(dir == TOP_LEFT_RIGHT || dir == BOTTOM_RIGHT_LEFT)
				for(int i = 0, j = row - 1; i < midrow; i++, j--) swap(mat[i], mat[j]);
			else {
				for(int i = 0; i < row; i++)
					for(int j = 0, k = col - 1; j < midrow; j++, k--) swap(mat[i][j], mat[j][k]);
			}
		}
	}

	switch(dir) {
	case TOP_LEFT_RIGHT:
		cout << row << ' ' << col << endl;
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(j != 0) cout << ' ';
				cout << mat[i][j];
			}
			cout << endl;
		}
		break;
	case RIGHT_TOP_BOTTOM:
		cout << col << ' ' << row << endl;
		for(int j = col - 1; j >= 0; j--) {
			for(int i = 0; i < row; i++) {
				if(i != 0) cout << ' ';
				cout << mat[i][j];
			}
			cout << endl;
		}
		break;
	case BOTTOM_RIGHT_LEFT:
		cout << row << ' ' << col << endl;
		for(int i = row - 1; i >= 0; i--) {
			for(int j = col - 1; j >= 0; j--) {
				if(j != col - 1) cout << ' ';
				cout << mat[i][j];
			}
			cout << endl;
		}
		break;
	case LEFT_BOTTOM_TOP:
		cout << col << ' ' << row << endl;
		for(int j = 0; j < col; j++) {
			for(int i = row - 1; i >= 0; i--) {
				if(i != row - 1) cout << ' ';
				cout << mat[i][j];
			}
			cout << endl;
		}
		break;
	}

	delete[] ins;
	for(int i = 0; i < row; i++) delete[] mat[i];
	delete[] mat;
}
