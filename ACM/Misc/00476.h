// Points in Figures: Rectangle *AC*

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int MAX = 15;

struct Range {
	double minX, maxX;
	double minY, maxY;
};

int main() {
	Range ranges[MAX];

	string s;
	char type;
	double x1, y1, x2, y2;
	Range cur;
	int curRange = 0;
	while(getline(cin, s), s != "*") {
		stringstream ss;
		ss << s;
		while(ss >> type >> x1 >> y1 >> x2 >> y2) {
			if(x1 < x2) cur.minX = x1, cur.maxX = x2;
			else cur.minX = x2, cur.maxX = x1;
			if(y1 < y2) cur.minY = y1, cur.maxY = y2;
			else cur.minY = y2, cur.maxY = y1;
			ranges[curRange++] = cur;
		}
	}

	double x, y;
	int curPoint = 1;
	while(cin >> x >> y, !(x == 9999.9 && y == 9999.9)) {
		bool contained = false;
		for(int i = 0; i < curRange; i++) {
			if((x > ranges[i].minX) && (y > ranges[i].minY) &&
			   (x < ranges[i].maxX) && (y < ranges[i].maxY)) {
				cout << "Point " << curPoint << " is contained in figure " << i + 1 << endl;
				contained = true;
			}
		}
		if(!contained) cout << "Point " << curPoint << " is not contained in any figure" << endl;
		curPoint++;
	}
}
