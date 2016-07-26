// Fibonacci Freeze *AC*

#include <stdio.h>

const int BIG_NUM_SIZE = 1045;

class BigNum {
public:
	BigNum() {}

	BigNum(int n) {
		for(int i = 0; i < BIG_NUM_SIZE; ++i) {
			if(n > 0) {
				this->num[i] = n % 10;
				n /= 10;
			}
			else
				this->num[i] = 0;
		}
	}

	BigNum operator+(BigNum rhs) {
		BigNum result = 0;
		int carry = 0;
		for(int i = 0; i < BIG_NUM_SIZE; ++i) {
			result.num[i] = carry + this->num[i] + rhs.num[i];

			carry = 0;
			if(result.num[i] >= 10) {
				carry += result.num[i] / 10;
				result.num[i] %= 10;
			}
		}
		return result;
	}

	void operator+=(BigNum rhs) {
		*this = *this + rhs;
	}

	bool operator<=(BigNum rhs) {
		bool equal = false;
		for(int i = BIG_NUM_SIZE - 1; i >= 0; --i) {
			if(this->num[i] < rhs.num[i])
				return true;
			else if(this->num[i] == rhs.num[i])
				equal = true;
			else
				return false;
		}
		
		return equal;
	}

	void print() {
		bool changed = false;
		for(int i = BIG_NUM_SIZE - 1; i >= 0; --i) {
			if(this->num[i] != 0)
				changed = true;
			if(changed)
				printf("%d", this->num[i]);
		}
	}
private:
	int num[BIG_NUM_SIZE];
};

int main() {
	// fibonacci calculation
	BigNum* results = new BigNum [5001];
	results[0] = 0, results[1] = 1, results[2] = 1;
	for (int i = 3; i <= 5000; ++i)
		results[i] = results[i - 1] + results[i - 2];

	int n = 0;
	while(scanf("%d", &n) != EOF) {
		// output
		if (n == 0 || n == 1)
			printf("The Fibonacci number for %d is %d\n", n, n);
		else {
			printf("The Fibonacci number for %d is ", n);
			results[n].print();
			printf("\n");
		}
	}
}

