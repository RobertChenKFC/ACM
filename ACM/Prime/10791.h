#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int num;
	cin >> num;
	for(int caseNum = 1; num != 0; caseNum++) {
		if(num == 1)
			cout << "Case " << caseNum << ": " << 2 << endl;
		else {
			int limit = sqrt(num);
			int divisors = 0;

			int sum = 0, curNum = 1;

			while(num % 2 == 0)
				num /= 2, curNum *= 2;
			if(curNum != 1)
				divisors++, sum += curNum, curNum = 1;

			while(num % 3 == 0)
				num /= 3, curNum *= 3;
			if(curNum != 1)
				divisors++, sum += curNum, curNum = 1;

			for(int i = 5, gap = 2; i <= limit; i += gap, gap = 6 - gap) {
				while(num % i == 0)
					num /= i, curNum *= i;
				if(curNum != 1)
					divisors++, sum += curNum, curNum = 1;
			}

			if(num != 1)
				divisors++, sum += num;
			if(divisors <= 1)
				sum++;

			cout << "Case " << caseNum << ": " << sum << endl;
		}

		cin >> num;
	}
}
