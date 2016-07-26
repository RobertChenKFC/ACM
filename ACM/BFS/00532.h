// Dungeon Master *AC*

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Vertex {
public:
	Vertex() :
	i(0), j(0), k(0) {}

	bool operator==(Vertex rhs) {
		return (i == rhs.i) && (j == rhs.j) && (k == rhs.k);
	}

	bool operator!=(Vertex rhs) {
		return !(*this == rhs);
	}

	int i, j, k;
};

const char FROM = 'S', TO = 'E', ROCK = '#', CLEAR = '.';
const int UNREACHED = -1;

int main() {
	int l, r, c;
	while(true) {
		cin >> l >> r >> c;

		if(l == 0 && r == 0 && c == 0)
			return 0;

		vector< vector< vector<char> > > dungeon(l, vector< vector<char> >(r, vector<char>(c, 0)));
		Vertex from, to;
		for(int i = 0; i < l; i++) {
			for(int j = 0; j < r; j++) {
				for(int k = 0; k < c; k++) {
					cin >> dungeon[i][j][k];
					if(dungeon[i][j][k] == FROM)
						from.i = i, from.j = j, from.k = k;
					else if(dungeon[i][j][k] == TO)
						to.i = i, to.j = j, to.k = k;
				}
			}
		}

		queue<Vertex> posQ;
		posQ.push(from);
		vector< vector< vector<bool> > > marked(l, vector< vector<bool> >(r, vector<bool>(c, false)));
		vector< vector< vector<bool> > > inQ(l, vector< vector<bool> >(r, vector<bool>(c, false)));
		vector< vector< vector<int> > > step(l, vector< vector<int> >(r, vector<int>(c, UNREACHED)));
		marked[from.i][from.j][from.k] = true, inQ[from.i][from.j][from.k] = true;
		step[from.i][from.j][from.k] = 0;

		Vertex cur;
		while(posQ.size() != 0) {
			cur = posQ.front();
			posQ.pop();
			inQ[cur.i][cur.j][cur.k] = false;

			// up
			Vertex next;
			next.i = cur.i - 1, next.j = cur.j, next.k = cur.k;
			if(cur.i > 0 && dungeon[next.i][next.j][next.k] != ROCK &&
			   !marked[next.i][next.j][next.k] && !inQ[next.i][next.j][next.k]) {
				posQ.push(next);
				marked[next.i][next.j][next.k] = true, inQ[next.i][next.j][next.k] = true;
				step[next.i][next.j][next.k] = step[cur.i][cur.j][cur.k] + 1;

				if(next == to)
					break;
			}

			// down
			next.i = cur.i + 1, next.j = cur.j, next.k = cur.k;
			if(cur.i < l - 1 && dungeon[next.i][next.j][next.k] != ROCK &&
			   !marked[next.i][next.j][next.k] && !inQ[next.i][next.j][next.k]) {
				posQ.push(next);
				marked[next.i][next.j][next.k] = true, inQ[next.i][next.j][next.k] = true;
				step[next.i][next.j][next.k] = step[cur.i][cur.j][cur.k] + 1;

				if(next == to)
					break;
			}

			// left
			next.i = cur.i, next.j = cur.j, next.k = cur.k - 1;
			if(cur.k > 0 && dungeon[next.i][next.j][next.k] != ROCK &&
			   !marked[next.i][next.j][next.k] && !inQ[next.i][next.j][next.k]) {
				posQ.push(next);
				marked[next.i][next.j][next.k] = true, inQ[next.i][next.j][next.k] = true;
				step[next.i][next.j][next.k] = step[cur.i][cur.j][cur.k] + 1;

				if(next == to)
					break;
			}

			// right
			next.i = cur.i, next.j = cur.j, next.k = cur.k + 1;
			if(cur.k < c - 1 && dungeon[next.i][next.j][next.k] != ROCK &&
			   !marked[next.i][next.j][next.k] && !inQ[next.i][next.j][next.k]) {
				posQ.push(next);
				marked[next.i][next.j][next.k] = true, inQ[next.i][next.j][next.k] = true;
				step[next.i][next.j][next.k] = step[cur.i][cur.j][cur.k] + 1;

				if(next == to)
					break;
			}

			// front
			next.i = cur.i, next.j = cur.j - 1, next.k = cur.k;
			if(cur.j > 0 && dungeon[next.i][next.j][next.k] != ROCK &&
			   !marked[next.i][next.j][next.k] && !inQ[next.i][next.j][next.k]) {
				posQ.push(next);
				marked[next.i][next.j][next.k] = true, inQ[next.i][next.j][next.k] = true;
				step[next.i][next.j][next.k] = step[cur.i][cur.j][cur.k] + 1;

				if(next == to)
					break;
			}

			// back
			next.i = cur.i, next.j = cur.j + 1, next.k = cur.k;
			if(cur.j < r - 1 && dungeon[next.i][next.j][next.k] != ROCK &&
			   !marked[next.i][next.j][next.k] && !inQ[next.i][next.j][next.k]) {
				posQ.push(next);
				marked[next.i][next.j][next.k] = true, inQ[next.i][next.j][next.k] = true;
				step[next.i][next.j][next.k] = step[cur.i][cur.j][cur.k] + 1;

				if(next == to)
					break;
			}
		}

		if(step[to.i][to.j][to.k] != UNREACHED)
			cout << "Escaped in " << step[to.i][to.j][to.k] << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
	}
}
