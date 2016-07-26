// Pascal's Triangle of Death *AC*

#include <stdio.h>
#include <stdlib.h>

const int BIG_NUM_SIZE = 61;
class BigNum {
public:
	BigNum() {
		for(int i = 0; i < BIG_NUM_SIZE; ++i)
			this->num[i] = 0;
	}

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
	
	void changeToMax() {
		this->num[60] = 1;
	}

	BigNum operator+(BigNum rhs) {
		BigNum result = 0;
		int carry = 0;
		for(int i = 0; i < BIG_NUM_SIZE; ++i) {
			result.num[i] = this->num[i] + rhs.num[i];
			result.num[i] += carry;

			carry = 0;
			if(result.num[i] >= 10) {
				carry += result.num[i] / 10;
				result.num[i] %= 10;
			}
		}

		return result;
	}

	bool operator>=(BigNum rhs) {
		for(int i = BIG_NUM_SIZE - 1; i >= 0; --i) {
			if(this->num[i] > rhs.num[i])
				return true;
			else if(this->num[i] < rhs.num[i])
				return false;
		}
		return true;
	}

	void print() {
		bool changed = false;
		for(int i = BIG_NUM_SIZE - 1; i >= 0; --i) {
			if(this->num[i] != 0)
				changed = true;
			if(changed)
				printf("%d", this->num[i]);
		}
		printf(" ");
	}

private:
	int num[BIG_NUM_SIZE];
};

const int ROW_SIZE = 300;

int main() {
	BigNum limit;
	limit.changeToMax();
	int curRowNumber = 1;
	int curRowIndex = 0;
	BigNum curRow[ROW_SIZE], lastRow[ROW_SIZE];
	bool stop = false;
	while(!stop) {
		for(int i = 0, j = curRowNumber - 1; j >= 0; ++i, --j) {
			if(i == 0 || j == 0) {
				if(j != 0)
					printf("1 ");
				else
					printf("1\n");
				curRow[curRowIndex++] = 1;
			}
			else {
				BigNum t = lastRow[curRowIndex - 1] + lastRow[curRowIndex];
				if(t >= limit)
					stop = true;
				t.print();
				curRow[curRowIndex++] = t;
			}
		}
		for(int i = 0; i < curRowNumber; ++i)
			lastRow[i] = curRow[i];
		curRowIndex = 0;
		curRowNumber++;
	}
}
