// Ordering Tasks *AC*

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string numToStr(int num) {
	string str;
	char curNum;
	while(num != 0) {
		curNum = num % 10 + '0';
		str.insert(0, 1, curNum);
		num /= 10;
	}
	return str;
}

const char POINTED = 0, UNPOINTED = 1, ASSIGNED = 2;

int main() {
	int numOfTasks, numOfRelations;

	while(cin >> numOfTasks >> numOfRelations) {
		if(numOfTasks == 0 && numOfRelations == 0)
			return 0;

		char** matrix = new char*[numOfTasks];
		for(int i = 0; i < numOfTasks; i++) {
			matrix[i] = new char[numOfTasks];
			for(int j = 0; j < numOfTasks; j++)
				matrix[i][j] = UNPOINTED;
		}

		int firstTask, secondTask;
		for(int i = 0; i < numOfRelations; i++) {
			cin >> firstTask >> secondTask;

			matrix[firstTask - 1][secondTask - 1] = POINTED;
		}

		string output;
		int tasksArranged = 0;
		while(tasksArranged < numOfTasks) {
			bool curColValid;
			for(int i = 0; i < numOfTasks; i++) {
				curColValid = true;
				for(int j = 0; j < numOfTasks; j++) {
					if(matrix[j][i] != UNPOINTED) {
						curColValid = false;
						break;
					}
				}

				if(curColValid) {
					output += numToStr(i + 1) + " ";
					for(int j = 0; j < numOfTasks; j++) {
						matrix[i][j] = UNPOINTED;
						matrix[j][i] = ASSIGNED;
					}
					tasksArranged++;
					break;
				}
			}
		}

		for(int i = 0; i < numOfTasks; i++)
			delete[] matrix[i];
		delete matrix;

		if(output[output.length() - 1] == ' ')
			output.erase(output.length() - 1);
		cout << output << endl;
	}
}
