// *TLE*

#include <iostream>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	map< int, set<int> > edges;
	bool isSimple = true;
	int a, b, t;
	while(m--) {
		cin >> a >> b;

		if(isSimple) {
			if(a > b) t = a, a = b, b = t;

			if(a == b) isSimple = false;
			else if(edges.find(a) == edges.end())
				edges[a] = set<int>({b});
			else {
				set<int> &cur = edges[a];
				if(cur.find(b) == cur.end())
					cur.insert(b);
				else isSimple = false;
			}
		}
	}

	if(isSimple) cout << "yes" << endl;
	else cout << "Yes" << endl;
}
