// *AC*

#include <iostream>
#include <vector>

using namespace std;

bool Ok(const vector< vector<int> > &parent, const vector<bool> &hasProblem, const int &check) {
	if(hasProblem[check]) return false;

	for(const auto &x : parent[check])
		if(!Ok(parent, hasProblem, x)) return false;
	return true;
}

int main() {
	int n, connect, problem, ask;
	cin >> n >> connect >> problem >> ask;

	vector< vector<int> > parent(n, vector<int>());
	vector<bool> hasProblem(n, false);

	int a, b;
	while(connect--) {
		cin >> a >> b;
		parent[b].push_back(a);
	}

	while(problem--) {
		cin >> a;
		hasProblem[a] = true;
	}

	while(ask--) {
		cin >> a;

		if(!Ok(parent, hasProblem, a)) cout << "TUIHUOOOOOO" << endl;
		else cout << "YA~~" << endl;
	}
}
