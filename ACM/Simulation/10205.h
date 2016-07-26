#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main() {
	string s;
	stringstream ss;

	// get number of cases
	getline(cin, s);
	int cases;
	ss << s;
	ss >> cases;
	ss.clear();

	int shuf[150][52], deck[52], tDeck[52];

	bool first = true;
	while(cases--) {
		// clear blank line
		cin.ignore(255, '\n');

		// get number of shuffles
		getline(cin, s);
		int numShuf;
		ss << s;
		ss >> numShuf;
		ss.clear();

		// get the shuffles
		int cnt = 52 * numShuf, curShuf = 0, curNum = 0, cur;
		while(cnt > 0 && getline(cin, s)) {
			ss << s;
			while(ss >> cur) {
				cur--;
				shuf[curShuf][curNum++] = cur;
				if(curNum == 52)
					curShuf++, curNum = 0;
				cnt--;
			}
			ss.clear();
		}

		// deck initialize
		for(int i = 0; i < 52; i++)
			deck[i] = i;

		// get what shuffles to use
		while(getline(cin, s) && s != "" && s[0] != '\n') {
			ss << s;
			ss >> curShuf;
			ss.clear();
			curShuf--;

			memcpy(tDeck, deck, sizeof(int) * 52);
			for(int to = 0; to < 52; to++) {
				int from = shuf[curShuf][to];
				deck[to] = tDeck[from];
			}
		}

		// print the deck
		if(!first)
			cout << endl;
		first = false;
		for(int i = 0; i < 52; i++) {
			switch(deck[i] % 13) {
			case 9:
				cout << "Jack";
				break;
			case 10:
				cout << "Queen";
				break;
			case 11:
				cout << "King";
				break;
			case 12:
				cout << "Ace";
				break;
			default:
				cout << deck[i] % 13 + 2;
			}

			cout << " of ";

			switch(deck[i] / 13) {
			case 0:
				cout << "Clubs";
				break;
			case 1:
				cout << "Diamonds";
				break;
			case 2:
				cout << "Hearts";
				break;
			case 3:
				cout << "Spades";
				break;
			}

			cout << endl;
		}
	}
}
