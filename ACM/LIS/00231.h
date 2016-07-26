// Testing the CATCHER *AC*

#include <iostream>
#include <deque>

using namespace std;

int main() {
	int h;
	for(int test = 1; true; test++) {
		cin >> h;
		if(h == -1)
			break;
		else {
			deque<int> missles;
			missles.clear();
			do {
				missles.push_back(-h);
				cin >> h;
			} while(h != -1);

			int size = missles.size();
			deque<int> calc;
			calc.clear();
			calc.push_back(missles.front());
			for(int i = 1; i < size; i++) {
				int cur = missles[i];
				if(cur < calc.front())
					calc.front() = cur;
				else if(cur >= calc.back())
					calc.push_back(cur);
				else {
					int j;
					for(j = 0; calc[j] < cur; j++);
					calc[j] = cur;
				}
			}

			if(test != 1)
				cout << endl;
			cout << "Test #" << test << ":" << endl;
			cout << "  maximum possible interceptions: " << calc.size() << endl;
		}
	}
}
