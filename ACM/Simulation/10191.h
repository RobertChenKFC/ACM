// Longest Nap *AC*

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

int str2Int(string s) {
	stringstream ss;
	ss << s;
	int res;
	ss >> res;
	return res;
}

void intPrint(int n) {
	if(n < 10)
		cout << 0;
	cout << n;
}

int main() {
	int numLec;
	bool time[24][60];
	stringstream ss;
	for(int day = 1; cin >> numLec; day++) {
		string start, end, lec;
		for(int i = 0; i < 24; i++)
			memset(time[i], false, sizeof(time[i]));
		for(int i = 0; i < numLec; i++)  {
			cin >> start >> end;
			cin.ignore(256, '\n');

			int startH = str2Int(start.substr(0, 2)), startM = str2Int(start.substr(3, 2)),
				endH = str2Int(end.substr(0, 2)), endM = str2Int(end.substr(3, 2));
			startH--, endH--;

			for(int h = startH; h <= endH; h++) {
				if(h == startH) {
					if(startH == endH) {
						for(int m = startM; m < endM; m++)
							time[h][m] = true;
						break;
					}
					else {
						for(int m = startM; m < 60; m++)
							time[h][m] = true;
					}
				}
				else if(h != endH) {
					for(int m = 0; m < 60; m++)
						time[h][m] = true;
				}
				else {
					for(int m = 0; m < endM; m++)
						time[h][m] = true;
				}
			}
		}

		int maxNap =  -1, curNap = 0;
		int maxNapH = 9, maxNapM = 0, curNapH = 9, curNapM = 0;
		for(int h = 9; h < 17; h++) {
			for(int m = 0; m < 60; m++) {
				if(time[h][m]) {
					if(maxNap < curNap) {
						maxNap = curNap;
						maxNapH = curNapH, maxNapM = curNapM;
					}
					curNap = 0;
				}
				else {
					if(curNap == 0)
						curNapH = h, curNapM = m;
					curNap++;
				}
			}
		}
		if(maxNap < curNap) {
			maxNap = curNap;
			maxNapH = curNapH, maxNapM = curNapM;
		}

		maxNapH++;

		cout << "Day #" << day << ": the longest nap starts at ";
		intPrint(maxNapH);
		cout << ":";
		intPrint(maxNapM);
		cout << " and will last for ";
		if(maxNap >= 60)
			cout << maxNap / 60 << " hours and " << maxNap % 60 << " minutes." << endl;
		else
			cout << maxNap << " minutes." << endl;
	}
}
