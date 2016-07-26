// Following Orders *AC*

#include <iostream>
#include <string>

using namespace std;

const char NOT_ASSIGNED = -1, NOT_POINTED = 0, POINTED = 1, ASSIGNED = 2;

void QuickSort(string& arr, int m, int n) {
	if(n <= m)
		return;

	int i = m, j = n + 1;
	char t;
	do {
		do {
			i++;
		} while(arr[i] < arr[m]);
		do {
			j--;
		} while(arr[m] < arr[j]);

		if(i < j) {
			t = arr[i];
			arr[i] = arr[j], arr[j] = t;
		}
	} while(i < j);

	t = arr[m];
	arr[m] = arr[j], arr[j] = t;

	QuickSort(arr, m, j - 1);
	QuickSort(arr, j + 1, n);
}

class Tasks {
public:
	Tasks(string input) {
		for(int i = 0; i < input.length(); i++) {
			if(input[i] >= 'a' && input[i] <= 'z')
				tasks += input[i];
		}
		size = tasks.length();

		QuickSort(tasks, 0, size - 1);
	}

	int getSize() {
		return size;
	}

	int getIndex(char name) {
		for(int i = 0; i < tasks.length(); i++) {
			if(name == tasks[i])
				return i;
		}

		tasks += name;
		return tasks.length() - 1;
	}

	char getName(int index) {
		return tasks[index];
	}
private:
	string tasks;
	int size;
};

int newCount = 0, deleteCount = 0;
void GenerateOrders(char** matrix, Tasks tasks, int size, string curOrder) {
	if(curOrder.length() == size) {
		for(int i = 0; i < size; i++)
			delete[] matrix[i];
		delete matrix;

		cout << curOrder << endl;
		return;
	}

	int numOfValidAlphabets = 0;
	for(int i = 0; i < size; i++) {
		bool curColValid = true;
		for(int j = 0; j < size; j++) {
			if(matrix[j][i] != NOT_POINTED) {
				curColValid = false;
				break;
			}
		}
		if(curColValid)
			numOfValidAlphabets++;
	}

	int curCol, curColOrder = 1;
	while(curColOrder <= numOfValidAlphabets) {
		char** calcMatrix = new char*[size];
		for(int i = 0; i < size; i++) {
			calcMatrix[i] = new char[size];
			for(int j = 0; j < size; j++)
				calcMatrix[i][j] = matrix[i][j];
		}

		string calcOrder = curOrder;

		curCol = 0;
		for(int i = 0; i < size; i++) {
			bool curColValid = true;
			for(int j = 0; j < size; j++) {
				if(matrix[j][i] != NOT_POINTED) {
					curColValid = false;
					break;
				}
			}
			if(curColValid) {
				curCol++;
				if(curCol == curColOrder) {
					for(int j = 0; j < size; j++) {
						if(calcMatrix[i][j] != ASSIGNED)
							calcMatrix[i][j] = NOT_POINTED;
						calcMatrix[j][i] = ASSIGNED;
					}
					calcOrder += tasks.getName(i);

					GenerateOrders(calcMatrix, tasks, size, calcOrder);
					curColOrder++;
					break;
				}
			}
		}
	}
	if(curOrder.length() != 0) {
		for(int i = 0; i < size; i++)
			delete[] matrix[i];
		delete matrix;
	}
}

int main() {
	bool first = true;

	string alphabets, orders;
	char** matrix;
	char firstTask = NOT_ASSIGNED, secondTask = NOT_ASSIGNED;
	int size, orderLength = 0;
	while(getline(cin, alphabets)) {
		Tasks tasks(alphabets);
		size = tasks.getSize();

		matrix = new char*[size];
		for(int i = 0; i < size; i++) {
			matrix[i] = new char[size];
			for(int j = 0; j < size; j++)
				matrix[i][j] = NOT_POINTED;
		}

		getline(cin, orders);
		orderLength = orders.length();
		for(int i = 0; i < orderLength; i++) {
			if(orders[i] >= 'a' && orders[i] <= 'z') {
				if(firstTask == NOT_ASSIGNED)
					firstTask = orders[i];
				else if(secondTask == NOT_ASSIGNED)
					secondTask = orders[i];
			}
			if(firstTask != NOT_ASSIGNED && secondTask != NOT_ASSIGNED) {
				matrix[tasks.getIndex(firstTask)][tasks.getIndex(secondTask)] = POINTED;
				firstTask = NOT_ASSIGNED, secondTask = NOT_ASSIGNED;
			}
		}

		if(!first)
			cout << endl;
		first = false;
		string buffer;
		GenerateOrders(matrix, tasks, size, buffer);

		for(int i = 0; i < size; i++)
			delete[] matrix[i];
		delete matrix;
	}
}
