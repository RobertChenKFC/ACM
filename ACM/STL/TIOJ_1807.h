#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX = 1005;

int main() {
	unordered_map<int, int> table;
	bool connected[MAX][MAX] = {};

	int n, edges;
	cin >> n >> edges;

	bool isSimple = true;
	int a, b, ina, inb;
	while (edges--) {
		cin >> ina >> inb;

		if (isSimple) {
			if (ina == inb) { isSimple = false; break; }

			if (table.find(ina) == table.end()) a = table[ina] = table.size();
			else a = table[ina];
			if (table.find(inb) == table.end()) b = table[inb] = table.size();
			else b = table[inb];

			if (connected[a][b]) { isSimple = false; break; }
			else connected[a][b] = connected[b][a] = true;
		}
	}

	if (isSimple) cout << "yes" << endl;
	else cout << "Yes" << endl;

}