#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000005;
const int MAX_R = 50005;

struct Toy {
	int w;
	int v;
	bool picked;
};

struct Robot {
	int lim;
	int useTime;
};

int main() {
	int nweak, nsmall, ntoys;
	cin >> nweak >> nsmall >> ntoys;

	Robot *weak = new Robot[MAX_R], *small = new Robot[MAX_R];
	Toy *toys = new Toy[MAX];
	bool *toysPicked = new bool[MAX];
	int maxWeak, maxSmall;
	Toy maxw = {-1, -1}, maxv = {-1, -1};
	for(int i = 0; i < nweak; i++) { cin >> weak[i].lim; weak[i].useTime = -1; maxWeak = max(weak[i].lim, maxWeak); }
	for(int i = 0; i < nsmall; i++) { cin >> small[i].lim; small[i].useTime = -1; maxSmall = max(small[i].lim, maxSmall); }
	for(int i = 0; i < ntoys; i++) {
		cin >> toys[i].w >> toys[i].v; toys[i].picked = false;
		if(toys[i].w > maxw.w) maxw = toys[i];
		if(toys[i].v > maxv.v) maxv = toys[i];
	}

	if(maxWeak <= maxv.w || maxSmall <= maxw.v) {
		cout << -1 << endl;
		return 0;
	}

	sort(weak, weak + nweak, [](const Robot &a, const Robot &b) { return a.lim > b.lim; } );
	sort(small, small + nsmall, [](const Robot &a, const Robot &b) { return a.lim > b.lim; } );

	int left = 1, right = ntoys + 1, m;
	int time, picked;
	while(left + 1 < right) {
		m = (left + right) >> 1;

		time = 0, picked = 0;
		for(int i = 0; i < ntoys; i++) toys[i].picked = false;
		while(time <= m) {
			sort(toys, toys + ntoys, [](const Toy &a, const Toy &b) { return (a.w == b.w) ? (a.v > b.v) : (a.w < b.w); } );
			for(int i = 0; i < ntoys; i++) {
				if(!toys[i].picked) {
					for(int j = 0; j < nweak; j++) {
						if(weak[j].lim > toys[i].w && weak[j].useTime != time) {
							picked++, toys[i].picked = true, weak[j].useTime = time;
							break;
						}
					}
				}
			}

			sort(toys, toys + ntoys, [](const Toy &a, const Toy &b) { return (a.v == b.v) ? (a.w > b.w) : (a.v < b.v); } );
			for(int i = 0; i < ntoys; i++) {
				if(!toys[i].picked) {
					for(int j = 0; j < nsmall; j++) {
						if(small[j].lim > toys[i].v && small[j].useTime != time) {
							picked++, toys[i].picked = true, small[j].useTime = time;
							break;
						}
					}
				}
			}

			time++;
		}

		if(picked < ntoys) left = m;
		else right = m;
	}

	cout << left << endl;

	delete[] weak;
	delete[] small;
	delete[] toys;
	delete[] toysPicked;
}
