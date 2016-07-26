#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

struct Event {
	int day;
	int imp;
	string name;
	bool today;
};

const char EVENT = 'A', DATE = 'D', END_SIGN = '#';

int main() {
	int year;
	while(cin >> year) {
		int size;
		int numDays[12];
		if(year % 4 != 0) {
			size = 366;
			numDays[1] = 31, numDays[2] = 59, numDays[3] = 90, numDays[4] = 120,
			numDays[5] = 151, numDays[6] = 181, numDays[7] = 212, numDays[8] = 243,
			numDays[9] = 273, numDays[10] = 304, numDays[11] = 334;
		}
		else {
			size = 367;
			numDays[1] = 31, numDays[2] = 60, numDays[3] = 91, numDays[4] = 121,
			numDays[5] = 152, numDays[6] = 182, numDays[7] = 213, numDays[8] = 244,
			numDays[9] = 274, numDays[10] = 305, numDays[11] = 335;
		}

		vector< deque<Event> > days(size, deque<Event>());
		char type;
		int date, month;
		deque<int> check;
		Event e;
		do {
			cin >> type;
			if(type == EVENT) {
				cin >> date >> month >> e.imp >> e.name;
				if(month - 1 > 0)
					e.day = numDays[month - 1] + date;
				else
					e.day = date;

				//cout << month << "/" << date << ": " << e.day << endl;

				e.today = true;
				days[e.day].push_back(e);
				e.imp--, e.today = false;
				for(int i = e.day - 1; i >= 1 && e.imp >= 0; i--, e.imp--)
					days[i].push_back(e);
			}
			else {
				cin >> date >> month;
				if(month - 1 > 0)
					check.push_back(numDays[month - 1] + date);
				else
					check.push_back(date);
			}
		} while(type != END_SIGN);

		//for(int curDay = 0; curDay)
		for(int i = 1; i < size; i++) {
			if(days[i].size() != 0) {

			}
		}
	}
}
