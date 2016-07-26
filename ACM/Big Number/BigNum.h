// Big Num

const int SIZE = 100;

class BigNum {
public:
	BigNum operator+(BigNum rhs) {
		BigNum result("0");
		int carry = 0;
		for (int i = 0; i < SIZE; ++i) {
			result.num[i] += carry + this->num[i] + rhs.num[i];
			carry = 0;
			if (result.num[i] >= 10) {
				carry = result.num[i] / 10;
				result.num[i] %= 10;
			}
		}
		return result;
	}

	BigNum operator-(BigNum rhs) {
		BigNum result("0");
		int carry = 0;
		for (int i = 0; i < SIZE; ++i) {
			result.num[i] += carry + this->num[i] - rhs.num[i];
			carry = 0;
			while (result.num[i] < 0) {
				carry--;
				result.num[i] += 10;
			}
		}
		return result;
	}

	void operator+=(BigNum rhs) {
		*this = *this + rhs;
	}

	bool operator>(BigNum rhs) {
		bool changed = false;
		for (int i = SIZE - 1; i >= 0; --i) {
			if (this->num[i] != 0 || rhs.num[i] != 0)
				changed = true;
			if (changed) {
				if (this->num[i] > rhs.num[i])
					return true;
				else if (this->num[i] < rhs.num[i])
					return false;
			}
		}
		return false;
	}

	BigNum operator%(BigNum rhs) {
		BigNum base = rhs;
		BigNum prev = "0";
		BigNum t("0");

		int i;
		for (i = 1; *this >= rhs; ++i, prev = rhs, rhs += base);
		return *this - prev;
	}

	bool operator==(BigNum rhs) {
		for (int i = 0; i < SIZE; ++i) {
			if (this->num[i] != rhs.num[i])
				return false;
		}
		return true;
	}

	bool operator!=(BigNum rhs) {
		return !(*this == rhs);
	}

	bool operator>=(BigNum rhs) {
		return *this > rhs || *this == rhs;
	}
private:
	int num[SIZE];
};
