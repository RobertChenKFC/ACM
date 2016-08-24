#include <iostream>

using namespace std;

const int MAX = 100;

struct BinaryField {
	unsigned n : MAX;
};

int main() {
	int arr[MAX];

	int len;
	cin >> len;
	for(int i = 0; i < len; i++) cin >> arr[i];

	BinaryField cap, maskCap;
	cap.n = 1, maskCap.n = 1 << (len - 1);
	for(int i = 0; i < len - 1; i++) cap.n <<= 1, cap.n |= 1;
	cap.n++;

	BinaryField cur;
	int setNum = 1;
	cur.n = 0;
	do {
		cout << setNum++ << ": ";

		BinaryField mask;
		int i;
		for(mask.n = 1, i = 0; mask.n < maskCap.n; mask.n <<= 1, i++)
			if(cur.n & mask.n) cout << arr[i] << " ";
		if(cur.n & mask.n) cout << arr[i] << " ";

		cout << endl;
	} while(cur.n++, cur.n != cap.n);
}
