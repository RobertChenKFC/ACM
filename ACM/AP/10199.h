#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 105;
const int NOT_FOUND = -1;

void DFS(bool graph[MAX][MAX], int n, bool isAP[MAX],
		int order[MAX], int lowest[MAX],
		int me = 0, int father = NOT_FOUND, int cur = 0) {
	order[me] = lowest[me] = cur;
	int child = 0;
	bool AP = false;
	for(int i = 0; i < n; i++) {
		if(graph[me][i]) {
			if(order[i] == NOT_FOUND) {
				child++;
				DFS(graph, n, isAP, order, lowest, i, me, cur + 1);
				if(lowest[i] < lowest[me]) lowest[me] = lowest[i];
				if(lowest[i] >= order[me]) AP = true;
			}
			else if(i != father && order[i] < lowest[me]) lowest[me] = order[i];
		}
	}
	if((father == NOT_FOUND && child >= 2) || (father != NOT_FOUND && AP)) isAP[me] = true;
}

void FindAP(bool graph[MAX][MAX], int n, bool isAP[MAX]) {
	int order[MAX], lowest[MAX];
	for(int i = 0; i < n; i++) order[i] = NOT_FOUND;
	DFS(graph, n, isAP, order, lowest);
}

int main() {
	bool graph[MAX][MAX], isAP[MAX];
	int caseNum = 1;

	int n;
	while(cin >> n, n != 0) {
		map<string, int> toIndex;
		map<int, string> toCity;
		string city;
		int index;
		for(int i = 0; i < n; i++) {
			cin >> city;
			if(toIndex.find(city) == toIndex.end())
				toIndex[city] = index = toIndex.size() - 1;
			if(toCity.find(index) == toCity.end())
				toCity[index] = city;
		}

		memset(graph, 0, sizeof(graph));
		int e;
		cin >> e;
		string aCity, bCity;
		while(e--) {
			cin >> aCity >> bCity;
			int a = toIndex[aCity], b = toIndex[bCity];
			graph[a][b] = true, graph[b][a] = true;
		}


		memset(isAP, 0, sizeof(isAP));
		FindAP(graph, n, isAP);
		int cnt = 0;
		vector<string> cameraCities;
		for(int i = 0; i < n; i++) {
			if(isAP[i]) {
				cnt++;
				cameraCities.push_back(toCity[i]);
			}
		}
		sort(cameraCities.begin(), cameraCities.end());
		if(caseNum != 1) cout << endl;
		cout << "City map #" << caseNum++ << ": " << cnt << " camera(s) found" << endl;
		for(int i = 0; i < cnt; i++)
			cout << cameraCities[i] << endl;
	}
}
