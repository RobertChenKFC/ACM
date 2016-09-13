// *AC*

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1005;

struct Book {
	int print;
	int press;
};

int main() {
	Book books[MAX];
	int n;

	int printTime, pressTime;
	while(cin >> n) {
		for(int i = 0; i < n; i++) cin >> books[i].print >> books[i].press;

		sort(books, books + n, [](const Book &a, const Book &b) { return a.press > b.press; } );

		printTime = 0, pressTime = 0;
		for(int i = 0; i < n; i++) {
			Book &book = books[i];
			printTime += book.print;
			if(printTime + book.press > pressTime) pressTime = printTime + book.press;
		}

		cout << pressTime << endl;
	}
}
