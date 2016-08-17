#include <iostream>
#include <string>

using namespace std;

string ToString(int n) {
	return string(1, char('a' + n - 1));
}

class BigNum {
public:
	BigNum() : n() {}
	BigNum(const string &s) : n(s) {}
	BigNum(const int &size, const char &fill) : n(size, fill) {}
	BigNum(const BigNum &base) : n("0" + base.n) {}

	BigNum operator+(const BigNum& rhs) {
		if(n.length() > rhs.n.length()) {
			BigNum res(n.length() + 1, 0);
			for(int thisI = n.length() - 1, rhsI = rhs.n.length() - 1, resI = thisI + 1; thisI >= 0; thisI--, rhsI--, resI--) {
				res.n[resI] += n[thisI] -'0';
				if(rhsI >= 0) res.n[resI] += rhs.n[rhsI] - '0';
				res.n[resI - 1] = res.n[resI] / 10, res.n[resI] -= res.n[resI - 1] * 10;
				res.n[resI] += '0';
			}
			res.n[0] += '0';
			return res;
		}
		else {
			BigNum res(rhs.n.length() + 1, 0);
			for(int thisI = n.length() - 1, rhsI = rhs.n.length() - 1, resI = rhsI + 1; rhsI >= 0; thisI--, rhsI--, resI--) {
				res.n[resI] += rhs.n[rhsI] -'0';
				if(thisI >= 0) res.n[resI] += n[thisI] - '0';
				res.n[resI - 1] = res.n[resI] / 10, res.n[resI] -= res.n[resI - 1] * 10;
				res.n[resI] += '0';
			}
			res.n[0] += '0';
			return res;
		}
	}

	BigNum operator*(const int& rhs) const {
		BigNum res(n.length() + 1, 0);
		for(int i = n.length() - 1, resI = n.length(); i >= 0; i--, resI--) {
			int cur = int(n[i] - '0') * rhs + int(res.n[resI]);
			res.n[resI] = cur % 10;
			res.n[resI - 1] = (cur - res.n[resI - 1]) / 10;
			res.n[resI] += '0';
		}
		res.n[0] += '0';
		return res;
	}

	BigNum operator/(const int& rhs) const {
		int r = 0;
		BigNum res(n.length(), '0');
		for(int i = 0; i < n.length(); i++) {
			r *= 10, r += n[i] - '0';
			res.n[i] = r / rhs + '0';
			r %= rhs;
		}
		return res;
	}

	int operator%(const int &modulus) const {
		int res = 0;
		for(int i = 0; i < n.length(); i++) {
			res *= 10, res += n[i] - '0';
			if(res >= modulus) res %= modulus;
		}
		return res;
	}

	void operator=(const BigNum& rhs) { n = rhs.n; }
	void operator+=(const BigNum &rhs) { *this = *this + rhs; }
	void operator*=(const int &rhs) { *this = *this * rhs; }
	void operator/=(const int &rhs) { *this = *this / rhs; }

	bool isZero() {
		for(int i = n.length() - 1; i >= 0; i--)
			if(n[i] != '0') return false;
		return true;
	}

	friend ostream& operator<<(ostream& out, const BigNum& in) {
		const string &s = in.n;
		int cnt;
		bool changed = false;
		for(int i = 0; i < s.length(); i++) {
			if(!changed && s[i] != '0') changed = true, cnt = (s.length() - i) % 3;
			if(changed) {
				out << s[i];
				if(cnt == 3 && i != s.length() - 1) {
					cout << ",";
					cnt = 0;
				}
				cnt++;
			}
		}
		if(!changed) out << 0;
		return out;
	}
private:
	string n;
};

int main() {
	string s;
	while(cin >> s, s != "*") {
		if(s[0] >= '0' && s[0] <= '9') {
			BigNum t(s);
			string out = "";
			while(!t.isZero()) {
				out.insert(0, ToString(t % 26));
				t /= 26;
			}
			cout << out << " ";

			BigNum num(s);
			cout << num << endl;
		}
		else {
			cout << s << " ";

			BigNum t("0"), multiply("1");
			for(int i = s.length() - 1; i >= 0; i--, multiply *= 26) {
				BigNum cur = multiply * (s[i] - 'a');
				t += cur;

				cout << "t: " << t << ", cur: " << cur << ", mul: " << multiply << endl;
			}
			cout << t << endl;
		}
	}
}
