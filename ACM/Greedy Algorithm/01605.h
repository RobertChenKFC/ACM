// Building for UN *AC*

#include <iostream>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		cout << "2 " << n << " " << n << endl;
		char cur = 'A';
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				cout << cur;
			cout << endl;
			if(cur == 'Z')
				cur = 'a';
			else
				cur++;
		}
		cout << endl;
		for(int i = 0; i < n; i++) {
			cur = 'A';
			for(int j = 0; j < n; j++) {
				cout << cur;
				if(cur == 'Z')
					cur = 'a';
				else
					cur++;
			}
			cout << endl;
		}
	}
}
