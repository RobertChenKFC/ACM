#include <iostream>
#include <climits>
#include <vector>
#include <deque>
#include <map>

using namespace std;

struct strInfo {
	char start, end;
	int length;
};

struct strCnt {
	int length;
	int count;
};

// graph[i][j][k] means the kth street from i to j
const int NOT_DEF = -1;
int ShortestPath(vector< vector< deque<strCnt> > > graph, int size,
				 int prev = NOT_DEF, int end = NOT_DEF, int curLen = 0) {
	// first time
	if(end == NOT_DEF) {
		int shortestPath = INT_MAX;
		for(int i = 0; i < size; i++) {
			prev = i, end = i;

			int curPath = ShortestPath(graph, size, prev, end, 0);
			if(shortestPath > curPath)
				shortestPath = curPath;
		}

		return shortestPath;
	}

	// check if all nodes have been reached
	bool done = true;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			int strNum = graph[i][j].size();
			for(int k = 0; k < strNum; k++) {
				if(i != j && graph[i][j][k].count == 0) {
					done = false;
					goto FINISHED;
				}
			}
		}
	}

	FINISHED:
	// return back to starting node
	if(done) {
		vector<bool> marked(size, false);
		vector<int> length(size, INT_MAX);

		int start = prev;
		length[start] = 0;
		while(true) {
			marked[start] = true;

			for(int i = 0; i < size; i++) {
				int curDistance = length[start];
				int strNum = graph[start][i].size();
				int minStrLen = INT_MAX;
				for(int j = 0; j < strNum; j++) {
					if(graph[start][i][j].length < minStrLen)
						minStrLen = graph[start][i][j].length;
				}
				curDistance += minStrLen;

				if(curDistance < 0)
					curDistance = INT_MAX;

				if(i != start && curDistance < length[i])
					length[i] = curDistance;
			}

			int curMinDistance = INT_MAX, curMinIndex = NOT_DEF;
			for(int i = 0; i < size; i++) {
				if(!marked[i] && length[i] < curMinDistance)
					curMinDistance = length[i], curMinIndex = i;
			}

			if(curMinIndex == NOT_DEF)
				break;
			else
				start = curMinIndex;
		}

		int sumLen = length[end] + curLen;
		if(sumLen < 0)
			sumLen = INT_MAX;

		return sumLen;
	}
	// keep trying all nodes
	else {
		int maxCnt = INT_MIN;
		int cntDatum = NOT_DEF;
		bool allTheSame = true;
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				int strNum = graph[i][j].size();
				for(int k = 0; k < strNum; k++) {
					int curCnt = graph[i][j][k].count;
					if(cntDatum == NOT_DEF)
						cntDatum = curCnt;
					if(curCnt != cntDatum)
						allTheSame = false;
					if(curCnt > maxCnt)
						maxCnt = curCnt;
				}
			}
		}

		int shortestPath = INT_MAX;
		for(int i = 0; i < size; i++) {
			if(prev != i) {
				int strNum = graph[prev][i].size();

				for(int j = 0; j < strNum; j++) {
					if(graph[prev][i][j].count != maxCnt || allTheSame) {
						vector< vector< deque<strCnt> > > graphCpy(graph);
						graphCpy[prev][i][j].count++, graphCpy[i][prev][j].count++;
						int prevCpy = i;
						int lenCpy = curLen + graph[prev][i][j].length;

						int curPath = ShortestPath(graphCpy, size, prevCpy, end, lenCpy);
						if(curPath < shortestPath)
							shortestPath = curPath;
					}
				}
			}
		}
		return shortestPath;
	}
}

int main() {
	map<char, int> table;
	deque<strInfo> streets;
	vector< vector< deque<strCnt> > > graph;
	while(true) {
		string street;
		cin >> street;
		while(street != "deadend") {
			strInfo input;
			input.start = street[0], input.end = street[street.length() - 1];
			input.length = street.length();
			streets.push_back(input);

			if(table.find(input.start) == table.end())
				table[input.start] = table.size() - 1;
			if(table.find(input.end) == table.end())
				table[input.end] = table.size() - 1;

			cin >> street;
		}

		int graphSize = table.size(), strSize = streets.size();
		strCnt empty = {0, 0};
		graph = vector< vector< deque<strCnt> > >(graphSize, vector< deque<strCnt> >(graphSize, deque<strCnt> (0, empty)));
		for(int i = 0, j = 0; i < graphSize; i++, j++)
			graph[i][j].push_back(empty);
		for(int i = 0; i < strSize; i++) {
			strCnt curStr = {streets[i].length, 0};
			graph[table[streets[i].start]][table[streets[i].end]].push_back(curStr);
			graph[table[streets[i].end]][table[streets[i].start]].push_back(curStr);
		}

		cout << ShortestPath(graph, graphSize) << endl;

		table.clear();
		streets.clear();
		for(int i = 0; i < graphSize; i++) {
			for(int j = 0; j < graphSize; j++)
				graph[i][j].clear();
			graph[i].clear();
		}
		graph.clear();
	}
}
