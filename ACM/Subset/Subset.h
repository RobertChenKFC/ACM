#include <iostream>

using namespace std;

const int MAX = 64;

typedef unsigned long long int64;

int main() {
	int arr[MAX];

	int len;
	cin >> len;
	for(int i = 0; i < len; i++) cin >> arr[i];

	int64 cap = 1, maskCap = 1 << (len - 1);
	for(int i = 0; i < len - 1; i++) cap <<= 1, cap |= 1;
	cap++;

	int64 cur = 0;
	int setNum = 1;
	do {
		cout << setNum++ << ": ";

		int64 mask;
		int i;
		for(mask = 1, i = 0; mask < maskCap; mask <<= 1, i++)
			if(cur & mask) cout << arr[i] << " ";
		if(cur & mask) cout << arr[i] << " ";

		cout << endl;
	} while(cur++, cur != cap);
}
