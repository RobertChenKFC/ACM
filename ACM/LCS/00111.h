#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LEN = 25;

int main() {
	int lcs[MAX_LEN][MAX_LEN];
	int order[MAX_LEN];
	int cur[MAX_LEN];
	
	int n, t;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> t;
		order[t - 1] = i;
	}
	
	while(cin >> t) {
		cur[t - 1] = 1;
		for(int i = 2; i <= n; i++) {
			cin >> t;
			cur[t - 1] = i;
		}
		
		for(int i = 0; i <= n; i++) memset(lcs[i], 0, sizeof(int) * (n + 1));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(order[i - 1] == cur[j - 1])
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else {
					if(lcs[i][j - 1] > lcs[i - 1][j])
						lcs[i][j] = lcs[i][j - 1];
					else
						lcs[i][j] = lcs[i - 1][j];
				}
			}
		}
		
		cout << lcs[n][n] << endl;
	}
}