// Points in Figures: Rectangles, Circles, Triangles *AC*

#include <iostream>
#include <cmath>

using namespace std;

const double ERROR = 1.e-9;

struct Range {
	Range() {}
	Range(double minX, double minY, double maxX, double maxY) :
		type('r'), x1(minX), x2(maxX), y1(minY), y2(maxY) {}
	Range(double x, double y, double r) :
		type('c'), x1(x), y1(y), sqrR(r * r) {}
	Range(double x1, double y1, double x2, double y2, double x3, double y3) :
		type('t'), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3),
		area(abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2) / 2)
	{}

	bool inRange(double x, double y) {
		if(type == 'r')
			return ((x > x1) && (x < x2) && (y > y1) && (y < y2));
		else if(type == 'c') {
			double dx = x - x1, dy = y - y1;
			return (dx * dx + dy * dy) < sqrR;
		}
		else {
			Range XAB(x, y, x1, y1, x2, y2),
				  XBC(x, y, x2, y2, x3, y3),
				  XAC(x, y, x1, y1, x3, y3);

			return ((XAB.area != 0) && (XBC.area != 0) && (XAC.area != 0) &&
					(abs(XAB.area + XBC.area + XAC.area - area) < ERROR));
		}
	}

	char type;
	double x1, x2, x3;
	double y1, y2, y3;
	double sqrR;
	double area;
};

const int MAX = 15;

int main() {
	Range ranges[MAX];

	char type;
	double x1, y1, x2, y2, x3, y3, r;
	int curRange = 0;
	while(cin >> type, type != '*') {
		if(type == 'r') {
			double t;
			cin >> x1 >> y1 >> x2 >> y2;
			if(x1 > x2) t = x1, x1 = x2, x2 = t;
			if(y1 > y2) t = y1, y1 = y2, y2 = t;
			ranges[curRange++] = Range(x1, y1, x2, y2);
		}
		else if(type == 'c') {
			cin >> x1 >> y1 >> r;
			ranges[curRange++] = Range(x1, y1, r);
		}
		else {
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			ranges[curRange++] = Range(x1, y1, x2, y2, x3, y3);
		}
	}

	double x, y;
	int curPoint = 1;
	while(cin >> x >> y, !(x == 9999.9 && y == 9999.9)) {
		bool contained = false;
		for(int i = 0; i < curRange; i++) {
			if(ranges[i].inRange(x, y)) {
				contained = true;
				cout << "Point " << curPoint << " is contained in figure " << i + 1 << endl;
			}
		}
		if(!contained) cout << "Point " << curPoint << " is not contained in any figure" << endl;
		curPoint++;
	}
}
