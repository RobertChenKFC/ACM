// Setting Problems *AC*

#include <iostream>
#include <cstdlib>

using namespace std;

struct Task {
	int A, B;
};

struct TaskSec {
	int start, end;
};

int cmp(const void* a, const void* b) {
	int at = ((Task*)a)->A + max(((Task*)a)->B, ((Task*)b)->A) + ((Task*)b)->B,
		bt = ((Task*)b)->A + max(((Task*)b)->B, ((Task*)a)->A) + ((Task*)a)->B;
	if(at > bt)
		return 1;
	if(at < bt)
		return -1;
	return 0;
}

int main() {
	int numProb;
	while(cin >> numProb) {
		Task* tasks = new Task[numProb];

		for(int i = 0; i < numProb; i++)
			cin >> tasks[i].A;
		for(int i = 0; i < numProb; i++)
			cin >> tasks[i].B;

		qsort(tasks, numProb, sizeof(Task), cmp);

		TaskSec* secA = new TaskSec[numProb];
		secA[0].start = 0;
		secA[0].end = tasks[0].A - 1;
		for(int i = 1; i < numProb; i++) {
			secA[i].start = secA[i - 1].end + 1;
			secA[i].end = secA[i].start + tasks[i].A - 1;
		}

		TaskSec* secB = new TaskSec[numProb];
		secB[0].start = secA[0].end + 1;
		secB[0].end = secB[0].start + tasks[0].B - 1;
		for(int i = 1; i < numProb; i++) {
			secB[i].start = secA[i].end + 1;
			if(secB[i].start <= secB[i - 1].end)
				secB[i].start = secB[i - 1].end + 1;
			secB[i].end = secB[i].start + tasks[i].B - 1;
		}

		cout << secB[numProb - 1].end + 1 << endl;

		delete[] secA;
		delete[] secB;
		delete[] tasks;
	}
}
