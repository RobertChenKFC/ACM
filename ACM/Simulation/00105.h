// Skyline Problem *AC*

#include <iostream>

using namespace std;

const int MAX = 10000;
int main() {
	int skyline[MAX] = { 0 };
	int start, end, height;
	bool first = true;
	int shift;
	while(cin >> start >> height >> end) {
		if(first) {
			shift = start;
			first = false;
		}

		start -= shift, end -= shift + 1;

		for(int i = start; i <= end; i++) {
			if(skyline[i] < height)
				skyline[i] = height;
		}
	}

	int curHeight = skyline[0];
	cout << shift << " " << skyline[0];
	for(int i = 0; i < MAX; i++) {
		if(skyline[i] != curHeight) {
			curHeight = skyline[i];
			cout << " " << i + shift << " " << curHeight;
		}
	}
	cout << endl;
}
