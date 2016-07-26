// Poker Hands *AC*

#include <iostream>
#include <string>

using namespace std;

#define VAL(X) ((X)[0])
#define SUIT(X) ((X)[1])

const int NUM_CARDS = 5, NONE = 0;
const char END_OF_NUM = -1, EMPTY1 = -2, EMPTY2 = -3;

enum Levels { HIGH_CARD, PAIR, TWO_PAIRS, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH };
enum Win { A_WON, B_WON, TIE };

// forward declaration
void SortHand(string[]);
char NextVal(char);
int Value(char);
int StraightFlush(string[]);
int FourOfAKind(string[]);
int FullHouse(string[]);
bool Flush(string[]);
bool Straight(string[]);
int ThreeOfAKind(string[]);
bool TwoPairs(string[]);
bool Pair(string[]);
int HighCard(string[]);
Win TwoPairCmp(string[], string[]);
Win PairCmp(string[], string[]);
Win HighCardCmp(string[], string[]);
Win HandCmp(string[], string[]);

void SortHand(string hand[]) {
	for(int i = 0; i < NUM_CARDS; i++) {
		for(int j = 0; j + i + 1 < NUM_CARDS; j++) {
			if(Value(VAL(hand[j])) > Value(VAL(hand[j + 1]))) {
				string t = hand[j];
				hand[j] = hand[j + 1], hand[j + 1] = t;
			}
		}
	}
}

char NextVal(char curVal) {
	switch(curVal) {
	case '9':
		return 'T';
	case 'T':
		return 'J';
	case 'J':
		return 'Q';
	case 'Q':
		return 'K';
	case 'K':
		return 'A';
	case 'A':
	case END_OF_NUM:
		return END_OF_NUM;
	default:
		return curVal + 1;
	}
}

int Value(char val) {
	switch(val) {
	case 'T':
		return 10;
	case 'J':
		return 11;
	case 'Q':
		return 12;
	case 'K':
		return 13;
	case 'A':
		return 14;
	default:
		return val - '0';
	}
}

// 5 consecutive values of the same suit, ranked by highest card
int StraightFlush(string hand[]) {
	char curVal = NextVal(VAL(hand[0]));

	for(int i = 1; i < NUM_CARDS; i++, curVal = NextVal(curVal)) {
		if(VAL(hand[i]) != curVal)
			return NONE;
		if(SUIT(hand[i]) != SUIT(hand[0]))
			return NONE;
	}
	return Value(hand[NUM_CARDS - 1][0]);
}

// 4 same value cards, ranked by the 4 cards
int FourOfAKind(string hand[]) {
	// first four
	if(VAL(hand[0]) == VAL(hand[1])) {
		for(int i = 2; i < NUM_CARDS - 1; i++) {
			if(VAL(hand[i]) != VAL(hand[0]))
				return NONE;
		}
		return Value(VAL(hand[0]));
	}
	// last four
	else {
		for(int i = 2; i < NUM_CARDS; i++) {
			if(VAL(hand[i]) != VAL(hand[1]))
				return NONE;
		}
		return Value(VAL(hand[0]));
	}
}

// 3 same value cards with 2 remaining forming a pair, ranked by the 3 cards
int FullHouse(string hand[]) {
	if(VAL(hand[0]) == VAL(hand[1])) {
		// (3, 2)
		if(VAL(hand[1]) == VAL(hand[2])) {
			if(VAL(hand[3]) == VAL(hand[4]))
				return Value(VAL(hand[0]));
			else
				return NONE;
		}
		// (2, 3)
		else if(VAL(hand[2]) == VAL(hand[3]) && VAL(hand[3]) == VAL(hand[4]))
			return Value(VAL(hand[2]));
		else
			return NONE;
	}
	return NONE;
}

// 5 cards of the same suit, ranked by rules of high card
bool Flush(string hand[]) {
	for(int i = 1; i < NUM_CARDS; i++) {
		if(SUIT(hand[i]) != SUIT(hand[0]))
			return false;
	}
	return true;
}

// 5 consecutive values of different suits, ranked by rules of high card
bool Straight(string hand[]) {
	char curVal = NextVal(VAL(hand[0]));

	for(int i = 1; i < NUM_CARDS; i++, curVal = NextVal(curVal)) {
		if(VAL(hand[i]) != curVal)
			return false;
	}
	return true;
}

// 3 same value cards, ranked by the 3 cards
int ThreeOfAKind(string hand[]) {
	for(int i = 1; i < NUM_CARDS - 1; i++) {
		if(VAL(hand[i - 1]) == VAL(hand[i]) && VAL(hand[i]) == VAL(hand[i + 1]))
			return Value(VAL(hand[i]));
	}
	return NONE;
}

// 2 different pairs, see TwoPairCmp for more detail
bool TwoPairs(string hand[]) {
	// (2, 2, 1)
	if(VAL(hand[0]) == VAL(hand[1]) && VAL(hand[2]) == VAL(hand[3]))
		return true;
	// (2, 1, 2)
	if(VAL(hand[0]) == VAL(hand[1]) && VAL(hand[3]) == VAL(hand[4]))
		return true;
	// (1, 2, 2)
	if(VAL(hand[1]) == VAL(hand[2]) && VAL(hand[3]) == VAL(hand[4]))
		return true;
	return false;
}

// 2 same value cards, see PairCmp for more detail
bool Pair(string hand[]) {
	for(int i = 0; i < NUM_CARDS - 1; i++) {
		if(VAL(hand[i]) == VAL(hand[i + 1]))
			return true;
	}
	return false;
}

Win TwoPairCmp(string hand1[], string hand2[]) {
	int pair1[NUM_CARDS] = { 0 }, pair2[NUM_CARDS] = { 0 };
	// hand 1
	for(int i = NUM_CARDS - 1; i > 0; i--) {
		if(VAL(hand1[i]) == VAL(hand1[i - 1])) {
			pair1[i] = true, pair1[i - 1] = true;
			break;
		}
	}
	// hand 2
	for(int i = NUM_CARDS - 1; i > 0; i--) {
		if(VAL(hand2[i]) == VAL(hand2[i - 1])) {
			pair2[i] = true, pair2[i - 1] = true;
			break;
		}
	}

	// pair value compare
	int pairVal1, pairVal2;
	for(int i = NUM_CARDS - 1; i >= 0; i--) {
		if(pair1[i])
			pairVal1 = Value(VAL(hand1[i]));
		if(pair2[i])
			pairVal2 = Value(VAL(hand2[i]));
	}
	if(pairVal1 > pairVal2)
		return A_WON;
	if(pairVal1 < pairVal2)
		return B_WON;

	// reduce to PairCmp
	for(int i = NUM_CARDS - 1; i >= 0; i--) {
		if(pair1[i]) {
			VAL(hand1[i]) = EMPTY1, VAL(hand1[i - 1]) = EMPTY2;
			break;
		}
	}
	for(int i = NUM_CARDS - 1; i >= 0; i--) {
		if(pair2[i]) {
			VAL(hand2[i]) = EMPTY1, VAL(hand2[i - 1]) = EMPTY2;
			break;
		}
	}
	return PairCmp(hand1, hand2);
}

Win PairCmp(string hand1[], string hand2[]) {
	bool pair1[NUM_CARDS] = { 0 }, pair2[NUM_CARDS] = { 0 };
	// hand 1
	for(int i = 0; i < NUM_CARDS - 1; i++) {
		if(VAL(hand1[i]) == VAL(hand1[i + 1]))
			pair1[i] = true, pair1[i + 1] = true;
	}
	// hand 2
	for(int i = 0; i < NUM_CARDS - 1; i++) {
		if(VAL(hand2[i]) == VAL(hand2[i + 1]))
			pair2[i] = true, pair2[i + 1] = true;
	}

	// pair value compare
	int pairVal1, pairVal2;
	for(int i = 0; i < NUM_CARDS; i++) {
		if(pair1[i])
			pairVal1 = Value(VAL(hand1[i]));
		if(pair2[i])
			pairVal2 = Value(VAL(hand2[i]));
	}
	if(pairVal1 > pairVal2)
		return A_WON;
	if(pairVal1 < pairVal2)
		return B_WON;

	// non pair value compare
	int nonPairVal1, nonPairVal2;
	for(int i = NUM_CARDS - 1, j = NUM_CARDS - 1; true; i--, j--) {
		if(pair1[i])
			i--;
		if(i < 0)
			break;
		if(pair2[j])
			j--;
		if(j < 0)
			break;
		nonPairVal1 = Value(VAL(hand1[i])), nonPairVal2 = Value(VAL(hand2[j]));
		if(nonPairVal1 > nonPairVal2)
			return A_WON;
		if(nonPairVal1 < nonPairVal2)
			return B_WON;
	}
	return TIE;
}

Win HighCardCmp(string hand1[], string hand2[]) {
	for(int i = NUM_CARDS - 1; i >= 0; i--) {
		if(Value(VAL(hand1[i])) > Value(VAL(hand2[i])))
			return A_WON;
		else if(Value(VAL(hand1[i])) < Value(VAL(hand2[i])))
			return B_WON;
	}
	return TIE;
}

Win HandCmp(string hand1[], string hand2[]) {
	// Sort
	SortHand(hand1);
	SortHand(hand2);

	// Straight Flush
	int hand1Val = StraightFlush(hand1), hand2Val = StraightFlush(hand2);
	if(hand1Val > hand2Val)
		return A_WON;
	if(hand1Val < hand2Val)
		return B_WON;

	// Four of a Kind
	hand1Val = FourOfAKind(hand1), hand2Val = FourOfAKind(hand2);
	if(hand1Val > hand2Val)
		return A_WON;
	if(hand1Val < hand2Val)
		return B_WON;

	// Full House
	hand1Val = FullHouse(hand1), hand2Val = FullHouse(hand2);
	if(hand1Val > hand2Val)
		return A_WON;
	if(hand1Val < hand2Val)
		return B_WON;

	// Flush
	bool hand1Has = Flush(hand1), hand2Has = Flush(hand2);
	if(hand1Has && !hand2Has)
		return A_WON;
	if(!hand1Has && hand2Has)
		return B_WON;
	if(hand1Has && hand2Has) {
		Win res = HighCardCmp(hand1, hand2);
		if(res != TIE)
			return res;
	}

	// Straight
	hand1Has = Straight(hand1), hand2Has = Straight(hand2);
	if(hand1Has && !hand2Has)
		return A_WON;
	if(!hand1Has && hand2Has)
		return B_WON;
	if(hand1Has && hand2Has) {
		Win res = HighCardCmp(hand1, hand2);
		if(res != TIE)
			return res;
	}

	// Three of a Kind
	hand1Val = ThreeOfAKind(hand1), hand2Val = ThreeOfAKind(hand2);
	if(hand1Val > hand2Val)
		return A_WON;
	if(hand1Val < hand2Val)
		return B_WON;

	// Two Pairs
	hand1Has = TwoPairs(hand1), hand2Has = TwoPairs(hand2);
	if(hand1Has && !hand2Has)
		return A_WON;
	if(!hand1Has && hand2Has)
		return B_WON;
	if(hand1Has && hand2Has) {
		Win res = TwoPairCmp(hand1, hand2);
		if(res != TIE)
			return res;
	}

	// Pair
	hand1Has = Pair(hand1), hand2Has = Pair(hand2);
	if(hand1Has && !hand2Has)
		return A_WON;
	if(!hand1Has && hand2Has)
		return B_WON;
	if(hand1Has && hand2Has) {
		Win res = PairCmp(hand1, hand2);
		if(res != TIE)
			return res;
	}

	// High Card
	return HighCardCmp(hand1, hand2);
}

int main() {
	string blackHand[NUM_CARDS], whiteHand[NUM_CARDS];
	while(true) {
		if(!(cin >> blackHand[0]))
			return 0;
		for(int i = 1; i < NUM_CARDS; i++)
			cin >> blackHand[i];
		for(int i = 0; i < NUM_CARDS; i++)
			cin >> whiteHand[i];

		Win res = HandCmp(blackHand, whiteHand);
		if(res == A_WON)
			cout << "Black wins." << endl;
		else if(res == B_WON)
			cout << "White wins." << endl;
		else
			cout << "Tie." << endl;
	}
}
