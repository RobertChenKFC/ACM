#include <iostream>

using namespace std;

int main() {
	long i, j;
	while(cin >> i >> j) {
		long low, high;
		if(i < j)
			low = i, high = j;
		else
			low = j, high = i;

		long maxLength = -1;
		for(long a = low; a <= high; a++) {
			long num = a, curLength = 1;
			while(num != 1) {
				if(num % 2 != 0)
					num = num * 3 + 1;
				else
					num /= 2;
				curLength++;
			}

			if(curLength > maxLength)
				maxLength = curLength;
		}

		cout << i << " " << j << " " << maxLength << endl;
	}
}
