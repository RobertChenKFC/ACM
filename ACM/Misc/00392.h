// Polynomial Showdown *AC*

#include <iostream>

using namespace std;

#define ABS(X) (((X) > 0) ? (X) : (-X))

const int SIZE = 8;

int main() {
	int c;
	bool first = true;
	for(int i = SIZE; true; i--) {
		if(i < 0) {
			i = SIZE;
			cout << endl;
			first = true;
		}

		if(!(cin >> c))
			return 0;
		if(i != 0) {
			if(c != 0) {
				if(c > 0) {
					if(first) {
						if(c != 1)
							cout << c;
					}
					else {
						if(c == 1)
							cout << " + ";
						else
							cout << " + " << c;
					}
				}
				else {
					if(first) {
						if(c == -1)
							cout << "-";
						else
							cout << c;
					}
					else {
						if(c == -1)
							cout << " - ";
						else
							cout << " - " << -c;
					}
				}
				cout << "x";
				if(i != 1)
					cout << "^" << i;

				first = false;
			}
		}
		else {
			if(c == 0) {
				if(first)
					cout << 0;
			}
			else {
				if(c > 0) {
					if(first)
						cout << c;
					else
						cout << " + " << c;
				}
				else {
					if(first)
						cout << c;
					else
						cout << " - " << -c;
				}
			}
		}
	}
}
