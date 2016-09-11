// Rails *AC*

#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1005;

int main() {
	int n;
	int arr[MAX];

	while(cin >> n, n != 0) {
		while(cin >> arr[0], arr[0] != 0) {
			for(int i = 1; i < n; i++) cin >> arr[i];

			int cur = 1, index = 0;
			stack<int> stk;
			while(true) {
				if(stk.size() != 0 && stk.top() == arr[index]) stk.pop(), index++;
				else if(index < n && cur == arr[index]) index++, cur++;
				else if(cur <= n) stk.push(cur++);
				else break;
			}

			if(stk.size() == 0) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		cout << endl;
	}
}
