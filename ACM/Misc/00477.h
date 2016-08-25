// Points in Figures: Rectangles and Circles *AC*

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Rect { double minX, minY, maxX, maxY; };
struct Circle { double x, y, r; };
struct Range {
	Rect r;
	Circle c;
	char type;
};

const int MAX = 15;

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
		while(ss >> type) {
			cur.type = type;
			if(type == 'r') {
				ss >> x1 >> y1 >> x2 >> y2;
				if(x1 < x2) cur.r.minX = x1, cur.r.maxX = x2;
				else cur.r.minX = x2, cur.r.maxX = x1;
				if(y1 < y2) cur.r.minY = y1, cur.r.maxY = y2;
				else cur.r.minY = y2, cur.r.maxY = y1;
			}
			else ss >> cur.c.x >> cur.c.y >> cur.c.r;

			ranges[curRange++] = cur;
		}
	}

	double x, y;
	int curPoint = 1;
	while(cin >> x >> y, !(x == 9999.9 && y == 9999.9)) {
		bool contained = false;
		for(int i = 0; i < curRange; i++) {
			if(ranges[i].type == 'r') {
				if((x > ranges[i].r.minX) && (x < ranges[i].r.maxX) &&
				   (y > ranges[i].r.minY) && (y < ranges[i].r.maxY)) {
					contained = true;
					cout << "Point " << curPoint << " is contained in figure " << i + 1 << endl;
				}
			}
			else {
				double dx = x - ranges[i].c.x, dy = y - ranges[i].c.y;
				if((dx * dx + dy * dy) < (ranges[i].c.r * ranges[i].c.r)) {
					contained = true;
					cout << "Point " << curPoint << " is contained in figure " << i + 1 << endl;
				}
			}
		}
		if(!contained) cout << "Point " << curPoint << " is not contained in any figure" << endl;
		curPoint++;
	}
}
