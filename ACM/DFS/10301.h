// Rings and Glue *AC*

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define SQR(x) ((x) * (x))

class Ring {
public:
	void set() {
		cin >> x >> y >> r;
	}

	bool touching(Ring rhs) {
		float centerDistSqr = SQR(x - rhs.x) + SQR(y - rhs.y);
		float minR = r < rhs.r ? r : rhs.r, maxR = r > rhs.r ? r : rhs.r;

		return ((centerDistSqr <= SQR(minR + maxR)) && (centerDistSqr >= SQR(maxR - minR))) ||
			   (x == rhs.x && y == rhs.y && r == rhs.r);
	}

private:
	float x, y;
	float r;
};

int MaxConnectedBase(const vector< vector<bool> >& connected, vector<bool>& counted, int size, int curStart, int curNum = 0) {
	curNum++;

	for(int i = 0; i < size; i++) {
		if(i != curStart && !counted[i] && connected[curStart][i]) {
			counted[i] = true;
			curNum = MaxConnectedBase(connected, counted, size, i, curNum);
		}
	}
	return curNum;
}

int MaxConnected(const vector< vector<bool> >& connected, int size) {
	int maxNum = -1;
	vector<bool> counted(size, false);
	while(true) {
		bool found = false;
		for(int i = 0; i < size; i++) {
			if(!counted[i]) {
				found = true;
				counted[i] = true;
				int curNum = MaxConnectedBase(connected, counted, size, i);
				if(curNum > maxNum)
					maxNum = curNum;
			}
		}

		if(!found)
			break;
	}
	return maxNum;
}

int main() {
	while(true) {
		int numRings;
		cin >> numRings;

		if(numRings == -1)
			return 0;

		if(numRings == 0)
			cout << "The largest component contains 0 rings." << endl;
		else {
			Ring empty;
			vector<Ring> rings(numRings, empty);
			for(int i = 0; i < numRings; i++) {
				rings[i].set();
			}

			vector< vector<bool> > connected(numRings, vector<bool>(numRings, false));
			for(int i = 0; i < numRings; i++) {
				for(int j = 0; j < numRings; j++) {
					if(i == j)
						connected[i][j] = true;
					else {
						bool isConnected = rings[i].touching(rings[j]);
						connected[i][j] = isConnected, connected[j][i] = isConnected;
					}
				}
			}

			int maxConnected = MaxConnected(connected, numRings);
			cout << "The largest component contains " << maxConnected;
			if(maxConnected == 1)
				cout << " ring." << endl;
			else
				cout << " rings." << endl;
		}
	}
}
