// Financial Management *AC*

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int numCases;
	cin >> numCases;
	for(int caseNum = 1; caseNum <= numCases; caseNum++) {
		double average = 0, cur;
		for(int i = 0; i < 12; i++) {
			cin >> cur;
			average += cur;
		}
		average /= (double)12;

		cout << caseNum << " $";
		stringstream ss;
		ss.imbue(locale("en_US.UTF-8"));
		ss << setprecision(2) << fixed << average;
		cout << ss.str() << endl;
	}
}
