#include <iostream>
#include <deque>

using namespace std;

const int NUM_CARDS = 52, NUM_PILES = 7, PILE_SIZE = 7;

int main() {
	int deck[NUM_CARDS];
	while(true) {
		cin >> deck[0];
		if(deck[0] == 0)
			return 0;
		for(int i = 1; i < NUM_CARDS; i++)
			cin >> deck[i];

		deque<int> piles[7];
		deque<int> hand;
		int curCard = 0;
		for(int curPile = 0; curPile < NUM_PILES; curPile++) {
			for(; curCard < (curPile + 1) * PILE_SIZE; curCard++)
				piles[curPile].push_front(deck[curCard]);
		}
		for(int curCard = NUM_PILES * PILE_SIZE; curCard < NUM_CARDS; curCard++)
			hand.push_back(deck[curCard]);

		while(true) {
			int cur = hand.back();
			hand.pop_back();

		}
	}
}
