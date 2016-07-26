#include <iostream>
#include <deque>
#include <vector>
#include <map>

using namespace std;

struct Seg {
	int from, to;
};

const int UNREACHED = -1;

int main() {
	int numSegs, curCase = 1;
	while(true) {
		cin >> numSegs;

		if(numSegs == 0)
			return 0;

		deque<Seg> segs;
		map<int, int> table;
		for(int i = 0; i < numSegs; i++) {
			int from, to;
			cin >> from >> to;

			if(table.find(from) == table.end())
				table[from] = table.size() - 1;
			if(table.find(to) == table.end())
				table[to] = table.size() - 1;

			Seg curSeg;
			curSeg.from = from, curSeg.to = to;
			segs.push_back(curSeg);
		}

		int numNodes = table.size();
		vector< vector<bool> > connected(numNodes, vector<bool>(numNodes, false));
		for(int i = 0; i < numSegs; i++) {
			int from = table[segs[i].from], to = table[segs[i].to];
			connected[from][to] = true, connected[to][from] = true;
		}

		int originalFrom, ttl;
		cin >> originalFrom >> ttl;
		int from;
		if(!(table.find(originalFrom) == table.end()))
			from = table[originalFrom];
		while(originalFrom != 0 || ttl != 0) {
			if(table.find(originalFrom) == table.end())
				cout << "Case " << curCase++ << ": " << numNodes << " nodes not reachable from node "
					 << originalFrom << " with TTL = " << ttl << "." << endl;
			else {
				from = table[originalFrom];
				vector<bool> marked(numNodes, false), inQ(numNodes, false);
				deque<int> nodeQ;
				vector<int> step(numNodes, UNREACHED);
				step[from] = 0;
				nodeQ.push_back(from);
				while(nodeQ.size() != 0) {
					int cur = nodeQ.front();
					nodeQ.pop_front();
					inQ[cur] = false;

					if(step[cur] == ttl)
						break;

					for(int i = 0; i < numNodes; i++) {
						if(connected[cur][i] && !marked[i] && !inQ[i]) {
							nodeQ.push_back(i);
							marked[i] = true, inQ[i] = true;
							step[i] = step[cur] + 1;
						}
					}
				}

				int unreached = 0;
				for(int i = 0; i < numNodes; i++) {
					if(step[i] == UNREACHED)
						unreached++;
				}

				cout << "Case " << curCase++ << ": " << unreached << " nodes not reachable from node "
						<< originalFrom << " with TTL = " << ttl << "." << endl;
			}

			cin >> originalFrom >> ttl;
		}
	}
}
