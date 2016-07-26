#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

int main() {
	int numCur;
	while(cin >> numCur) {
		vector< vector<double> > curs(numCur, vector<double>(numCur, 0));
		for(int i = 0; i < numCur; i++) {
			for(int j = 0; j < numCur; j++) {
				if(i == j)
					curs[i][j] = 1;
				else {
					cin >> curs[i][j];
					curs[j][i] = curs[i][j];
				}
			}
		}
	}
}
