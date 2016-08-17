#include <iostream>
#include <cstring>
#include <cstddef>

using namespace std;

const int MAX = 55;
const char NOT_FOUND = -1;

struct Vertex {
	int i, j;
};

enum Dir { LEFT, RIGHT, UP, DOWN };

void FoundSol(const char &maze[MAX][MAX], const int &w, const int &h,
			  const Vertex &in, const Vertex &out, const char &sol[MAX],
			  const char &mirrors[MAX], const int& n = w * h, int cur = 0) {
	if(cur == n) {
		int i = in.i, j = in.j;
		Dir dir;
		if(i == 0)
		while(true) {
			if(maze[i][j] == '*') break;
			if(maze[i][j])
		}
	}

	char mirrorCpy[MAX];
	memcpy(mirrorCpy, mirrors, n);
	FoundSol(maze, w, h, in, out, sol, mirrorCpy, n, cur + 1);
	if(sol[0] != NOT_FOUND) return;

	memcpy(mirrorCpy, mirrors, n);
	mirrorCpy[cur] = '\\';
	FoundSol(maze, w, h, in, out, sol, mirrorCpy, n, cur + 1);
}

int main() {
	char maze[MAX][MAX];
	char mirrors[MAX * MAX];
	Vertex in, out;

	int w, h;
	while(cin >> w >> h) {
		bool inFound = false;
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				cin >> maze[i][j];
				if((maze[i][j] == '.') &&
				   (i == 0 || i == w - 1 || j == 0 || j == w - 1)) {
					if(inFound) out = { i, j };
					else in = { i, j }, inFound = true;
				}
			}
		}

		memset(mirrors, '/', w * h);
	}
}
