// Pie *AC*

#include <iostream>
#include <iomanip>

using namespace std;

const double gap = 0.0001, pi = 3.14159265359;

#define ABS(X) (((X) > 0) ? (X) : -(X))

bool Enough(double* pies, const double& n, const double& f, const double& size) {
	double count = 0;
	for(int i = 0; i < n; i++)
		count += (int)(pies[i] / size);

	return count >= f;
}

int main() {
	int numCases;
	cin >> numCases;
	while(numCases--) {
		double n, f;
		cin >> n >> f;
		f++;

		double* pies = new double[(int)n];
		double pieSum = 0;
		for(int i = 0; i < n; i++) {
			double radius;
			cin >> radius;
			pies[i] = radius * radius * pi;
			pieSum += pies[i];
		}

		double left = 0, right = pieSum / f;
		while(left < right) {
			double mid = (left + right) / (double)2;

			if(Enough(pies, n, f, mid))
				left = mid;
			else
				right = mid;

			if(ABS(right - left) < gap)
				break;
		}
		cout << fixed << setprecision(4) << (left > right ? left : right) << endl;

		delete[] pies;
	}
}
