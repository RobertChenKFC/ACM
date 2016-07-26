// Knight Moves *AC*

#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int CHESS_SIZE = 8;

const int ERR = -1, NORMAL = 0;
class Coord {
public:
	Coord() :
	i(0), j(0) {

	}

	Coord(string input) :
	i(CHESS_SIZE - (input[1] - '0')), j(input[0] - 'a') {

	}

	bool operator==(Coord rhs) {
		return (i == rhs.i) && (j == rhs.j);
	}

	bool operator!=(Coord rhs) {
		return !(*this == rhs);
	}

	int nextMove(int type, Coord& endPoint) {
		switch(type) {
		case 0:
			if(j - 1 >= 0 && i - 2 >= 0) {
				endPoint.j = j - 1, endPoint.i = i - 2;
				return NORMAL;
			}
			return ERR;
		case 1:
			if(j + 1 < CHESS_SIZE && i - 2 >= 0) {
				endPoint.j = j + 1, endPoint.i = i - 2;
				return NORMAL;
			}
			return ERR;
		case 2:
			if(j - 2 >= 0 && i - 1 >= 0) {
				endPoint.j = j - 2, endPoint.i = i - 1;
				return NORMAL;
			}
			return ERR;
		case 3:
			if(j + 2 < CHESS_SIZE && i - 1 >= 0) {
				endPoint.j = j + 2, endPoint.i = i - 1;
				return NORMAL;
			}
			return ERR;
		case 4:
			if(j - 2 >= 0 && i + 1 < CHESS_SIZE) {
				endPoint.j = j - 2, endPoint.i = i + 1;
				return NORMAL;
			}
			return ERR;
		case 5:
			if(j + 2 < CHESS_SIZE && i + 1 < CHESS_SIZE) {
				endPoint.j = j + 2, endPoint.i = i + 1;
				return NORMAL;
			}
			return ERR;
		case 6:
			if(j - 1 >= 0 && i + 2 < CHESS_SIZE) {
				endPoint.j = j - 1, endPoint.i = i + 2;
				return NORMAL;
			}
			return ERR;
		case 7:
			if(j + 1 < CHESS_SIZE && i + 2 < CHESS_SIZE) {
				endPoint.j = j + 1, endPoint.i = i + 2;
				return NORMAL;
			}
			return ERR;
		default:
			return ERR;
		}
	}

	int i, j;
};

const int UNREACHED = -1;

int main() {
	string fromStr, toStr;
	while(cin >> fromStr >> toStr) {
		Coord from(fromStr), to(toStr);

		if(from != to) {
			bool inQueue[CHESS_SIZE][CHESS_SIZE];
			int step[CHESS_SIZE][CHESS_SIZE];
			for(int i = 0; i < CHESS_SIZE; i++) {
				for(int j = 0; j < CHESS_SIZE; j++)
					step[i][j] = UNREACHED, inQueue[i][j] = false;
			}
			queue<Coord> posQueue;
			Coord cur = from;
			posQueue.push(cur);
			step[cur.i][cur.j] = 0;

			while(true) {
				cur = posQueue.front();
				posQueue.pop();
				inQueue[cur.i][cur.j] = false;

				for(int i = 0; i < CHESS_SIZE; i++) {
					Coord next;
					if(cur.nextMove(i, next) != ERR &&
					   !inQueue[next.i][next.j] && step[next.i][next.j] == UNREACHED) {
						posQueue.push(next);
						inQueue[next.i][next.j] = true, step[next.i][next.j] = step[cur.i][cur.j] + 1;

						if(next == to)
							goto FINISHED;
					}
				}
			}

			FINISHED:
			cout << "To get from " << fromStr << " to " << toStr
				 << " takes " << step[to.i][to.j] << " knight moves." << endl;
		}
		else
			cout << "To get from " << fromStr << " to " << toStr
				 << " takes " << 0 << " knight moves." << endl;
	}
}
