// Foriegn Exchange *AC*

#include <iostream>
#include <cstdlib>

using namespace std;

const int TO = -1, FROM = 1;

struct Exchg {
	int A, B;
	int fromOrTo;

	bool operator==(Exchg rhs) { return (A == rhs.A) && (B == rhs.B); }
};

int cmp(const void* a, const void* b) {
	if(((Exchg*)a)->A > ((Exchg*)b)->A)
		return 1;
	if(((Exchg*)a)->A < ((Exchg*)b)->A)
		return -1;
	if(((Exchg*)a)->B > ((Exchg*)b)->B)
		return 1;
	if(((Exchg*)a)->B < ((Exchg*)b)->B)
		return -1;
	return 0;
}

int main() {
	int numStd;
	cin >> numStd;
	while(numStd != 0) {
		Exchg* stds = new Exchg[numStd];

		for(int i = 0; i < numStd; i++) {
			int A, B;
			cin >> A >> B;
			if(A < B)
				stds[i].A = A, stds[i].B = B, stds[i].fromOrTo = TO;
			else
				stds[i].A = B, stds[i].B = A, stds[i].fromOrTo = FROM;
		}

		qsort(stds, numStd, sizeof(Exchg), cmp);

		bool valid = true;
		Exchg cur = stds[0];
		int curSum = 0;
		for(int i = 0; i < numStd; i++) {
			if(cur == stds[i])
				curSum += stds[i].fromOrTo;
			else {
				if(curSum != 0) {
					valid = false;
					break;
				}
				cur = stds[i], curSum = stds[i].fromOrTo;
			}
		}
		if(curSum != 0)
			valid = false;

		if(valid)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		delete[] stds;

		cin >> numStd;
	}
}

